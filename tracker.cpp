#include "tracker.h"

Tracker::Tracker() {
	scale = 2;
	roi = cv::Rect(0,0,0,0);
	const char* cascadeNameFace = "haarcascades/haarcascade_frontalface_alt.xml";
	if(!cascadeFace.load(cascadeNameFace))
		qDebug() << "Tracker: can not load" << cascadeNameFace;

	//this timer calls the image segmentation periodically
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(roiFromFeatures()));
}

Tracker::~Tracker() {
	qDebug() << "Tracker: destructor";
}

void Tracker::start() {
	timer->start(100);
}

void Tracker::stop() {
	timer->stop();
}

void Tracker::input(cv::Mat img) {
	qDebug() << "Tracker: new image";
	image = img.clone();
}

void Tracker::roiFromFeatures() {
	qDebug() << "Tracker: tracking features";

	if(image.empty()) {
		qDebug() << "Tracker: no input image";
		return;
	}

	//downsize image and convert to grayscale.
	//this allows for faster tracking
	cv::Mat gray, smallImg(cvRound (image.rows/scale), cvRound(image.cols/scale), CV_8UC1);
	cv::cvtColor(image, gray, CV_BGR2GRAY);
	cv::resize(gray, smallImg, smallImg.size(), 0, 0, cv::INTER_LINEAR);

	std::vector<cv::Rect> faces;
	cascadeFace.detectMultiScale(smallImg, faces, 1.1, 3, 0 |CV_HAAR_FIND_BIGGEST_OBJECT |CV_HAAR_DO_ROUGH_SEARCH |CV_HAAR_SCALE_IMAGE);

	if(!faces.empty()) {
		qDebug() << "Tracker: found features eyes and face";
		// rescale first detected face rect and eyes rect to original size
		cv::Rect firstFace(	scale*faces[0].x,
							scale*faces[0].y,
							scale*faces[0].width,
							scale*faces[0].height);

		constructRoi(firstFace);	//build the rois geometry from the largest face and eyepair

		qDebug() << "Tracker: done, new ROI ready";
		emit output(roi);
	}
}

//weighted superposition of old and new roi
//change the weight factor to make ROI adaption more snappy
//or more smooth
void Tracker::constructRoi(cv::Rect face) {
	qDebug() << "Tracker: construct roi";
	double weightNew = 0.1;
	double weightOld = 1 - weightNew;

	//set geometry from face detection
	//position of eyes is not used at the moment
	cv::Rect roiNew;
	roiNew.x = face.x+face.width*3/10;
	roiNew.y = face.y+face.height*1/10;
	roiNew.width = face.width*4/10;
	roiNew.height = face.height*2/10;

	//superimpose old and new roi
	roi.x = roiNew.x*weightNew+roi.x*weightOld;
	roi.y = roiNew.y*weightNew+roi.y*weightOld;
	roi.width = roiNew.width*weightNew+roi.width*weightOld;
	roi.height = roiNew.height*weightNew+roi.height*weightOld;
}
