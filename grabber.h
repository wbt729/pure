//The grabber gets images from the camera. In order to use it
//the init() function has to be called first. It will return whether
//or not a camera could be opened.
//You can specify the sampling frequency and the camera, if you
//have more than one camera connected to your system.

//images are sent through Qts signal and slot mechanism

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
	double samplingInterval; //in ms
	cv::Mat frame;
	cv::VideoCapture cap;
	int frameCounter;
	int running;
	QTimer *timer;
	QTime *fpsTime;
	
public:
	int init(double fS=15, int camNumber=0);
	void exit();
public slots:
	void start();
	void stop();

private slots:
	void grabFrame();
signals:
	void output(cv::Mat);
};

#endif /* GRABBER_H_ */
