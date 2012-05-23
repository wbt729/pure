/*
 * grabber.h
 *
 *  Created on: May 16, 2012
 *      Author: wbt729
 */

#ifndef GRABBER_H_
#define GRABBER_H_

#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <opencv2/opencv.hpp>

class Grabber : public QObject {
	Q_OBJECT
public:
	Grabber();
	Grabber(double fS, int camNumber);
	virtual ~Grabber();
private:
	double samplingInterval; //in Hertz
	cv::Mat frame;
	cv::VideoCapture cap;
	int frameCounter;
	int running;
	QTimer *timer;
	QTime *fpsTime;
	void exit();
public:
	int init(double fS=15, int camNumber=0);
public slots:
	void start();
	void stop();
private slots:
	void grabFrame();
signals:
	void output(cv::Mat);
};

#endif /* GRABBER_H_ */
