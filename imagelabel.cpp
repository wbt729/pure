/*
 * ImageLabel.cpp
 *
 *  Created on: May 16, 2012
 *      Author: wbt729
 */

#include "imagelabel.h"

ImageLabel::ImageLabel(QObject *parent) {
	show();
	roi = QRect(0,0,0,0);
}

ImageLabel::~ImageLabel() {
}

//set a new frame and draw it
void ImageLabel::setFrame(cv::Mat frame) {
	qDebug() << "ImageImageLabel: new Frame";
	QImage image = QImage((uchar*) frame.data, frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
	pixmap = QPixmap::fromImage(image);
	QPainter painter(&pixmap);
	QPen pen;
	pen.setColor(QColor(0,0,255,128));
	pen.setWidth(8);
	painter.setPen(pen);
	painter.drawRoundedRect(roi,5,5);	//draw ROI
	//setPixmap(pixmap);
	setPixmap(pixmap.scaledToWidth(600));
}

void ImageLabel::setRoi(cv::Rect newRoi) {
	qDebug() << "ImageImageLabel: set ROI";
	roi.setX(newRoi.x);
	roi.setY(newRoi.y);
	roi.setWidth(newRoi.width);
	roi.setHeight(newRoi.height);
}
