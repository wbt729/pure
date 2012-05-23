/*
 * tracker.h
 *
 *  Created on: May 17, 2012
 *      Author: wbt729
 */

#ifndef TRACKER_H_
#define TRACKER_H_

#include <opencv2/opencv.hpp>
#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtCore/QTimer>
class Tracker : public QObject {
	Q_OBJECT

public:
	Tracker();
	virtual ~Tracker();
public slots:
	void input(cv::Mat);
	void start();
	void stop();
private:
	QTimer *timer;
	double scale;	//the downscaling factor, smaller image means shorter runtime
	cv::Rect roi;
	cv::Mat image;
	cv::CascadeClassifier cascadeFace;
	cv::CascadeClassifier cascadeEyesBig;
	cv::CascadeClassifier cascadeEyesSmall;
	void constructRoi(cv::Rect);
private slots:
	void roiFromFeatures();
signals:
	void output(cv::Rect);
};

#endif /* TRACKER_H_ */
