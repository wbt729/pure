#include "imageprocessor.h"

ImageProcessor::ImageProcessor(int mode) {
	roiMode = mode;
	busy = false;
	tracker = new Tracker();
	QThread *trackerThread = new QThread();
	trackerThread->start();
	tracker->start();
	tracker->moveToThread(trackerThread);	

	connect(this, SIGNAL(newFrame(cv::Mat)), tracker, SLOT(input(cv::Mat)));
	connect(tracker, SIGNAL(output(cv::Rect)), this, SLOT(setCvRectRoi(cv::Rect)));

	if(mode == 0)
		tracker->blockSignals(true);
}

ImageProcessor::~ImageProcessor() {
	qDebug() << "ImageProcessor: destructor";
	tracker->stop();
	trackerThread->quit();
	trackerThread->wait();
}

void ImageProcessor::input(cv::Mat img) {
	qDebug() << "ImageProcessor: set input image";
	if(!busy) {
		busy = true;
		image = img.clone();
		if(roiMode == 1) {
			emit newFrame(image);
		}
		else {
			qDebug() << "ImageProcessor: setting static ROI";
			setCvRectRoi(cv::Rect(200,100,200,100));
		}
		extractSamples();
	}
	else
		qDebug() << "ImageProcessor: busy, omitting image";
}

void ImageProcessor::extractSamples() {
	getMeanValues();

	//isnan is not defined in windows
	//if(std::isNaN(red))
	//		red = 0;
	//if(std::isnan(green))
	//	green = 0;
	//if(std::isnan(blue))
	//	blue = 0;

	qDebug() << "ImageProcessor: output rgb " << red << green << blue;
	emit output(red, green, blue);
	busy = false;
}

void ImageProcessor::setTracking(bool s) {
	tracker->blockSignals(!s);
}

void ImageProcessor::getMeanValues() {
	//to determine the mean value of the ROI a new
	red = 0; green = 0; blue = 0;
	qDebug() << "ImageProcessor: get mean values using ROI" << roi.x << roi.y << roi.width << roi.height;
	cv::Mat subImg = cv::Mat(image, roi);	//new matrix from ROI
	subImg = subImg.clone();

	qDebug() << "ImageProcessor: subimg rows cols" << subImg.rows << subImg.cols;
	for(int i=0; i < subImg.rows*subImg.cols; i++) {
		blue += subImg.data[3*i];    //opencv uses BGR pixel order
		green += subImg.data[3*i+1];
		red += subImg.data[3*i+2];
	}
	int area = subImg.rows*subImg.cols;
	if(area == 0)	//prevent zero division if no ROI is set
		area = 1;
	red = red/area;
	green = green/area;
	blue = blue/area;
}

void ImageProcessor::setCvRectRoi(cv::Rect rect) {
	qDebug() << "ImageProcessor: set ROI from cv::Rect";
	roi = rect;
	emit newRoi(roi);
}

void ImageProcessor::setQRectRoi(QRect) {
	;
}
