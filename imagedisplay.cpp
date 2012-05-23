/*
 * ImageDisplay.cpp
 *
 *  Created on: May 16, 2012
 *      Author: wbt729
 */

#include "imagedisplay.h"

ImageDisplay::ImageDisplay(QObject *parent) {
	show();
	roi = QRect(0,0,0,0);
}

ImageDisplay::~ImageDisplay() {
}

void ImageDisplay::setFrame(cv::Mat frame) {
	qDebug() << "ImageImageDisplay: new Frame";
	QImage image = QImage((uchar*) frame.data, frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
	pixmap = QPixmap::fromImage(image);
	QPainter painter(&pixmap);
	QPen pen;
	pen.setColor(QColor(0,0,255,128));
	pen.setWidth(8);
	painter.setPen(pen);
	painter.drawRoundedRect(roi,5,5);

	setPixmap(pixmap);
}

void ImageDisplay::setRoi(cv::Rect newRoi) {
	qDebug() << "ImageImageDisplay: set ROI";
	roi.setX(newRoi.x);
	roi.setY(newRoi.y);
	roi.setWidth(newRoi.width);
	roi.setHeight(newRoi.height);
}
