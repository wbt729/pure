#include "grabber.h"

Grabber::Grabber() {
	frameCounter = 0;
	samplingInterval = 0;
	running = 0;
	cap = cv::VideoCapture();
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(grabFrame()));
}

Grabber::~Grabber() {
	stop();
	exit();
}

int Grabber::init(double fS, int camNumber) {
	qDebug() << "Grabber: init";
	fpsTime = new QTime();
	samplingInterval = 1000/fS;
    cap.open(camNumber); // open the camera
    if(!cap.isOpened()) { // check if we succeeded
    	qDebug() << "Grabber: cant open camera number" << camNumber;
        return -1;
    }
    else {
    	qDebug() << "Grabber: opened camera number" << camNumber;
    	return 0;
    }
}

void Grabber::start() {
	qDebug() << "Grabber: start";
	fpsTime->start();
	timer->start(samplingInterval);
}

//get new frame from camera
void Grabber::grabFrame() {
	qDebug() << "Grabber: grab frame";
	if(cap.read(frame)) {
		int elapsed = fpsTime->elapsed();
		qDebug() << "Grabber: time elapsed" << elapsed << "fps:" << (double) 1000/elapsed;
		fpsTime->restart();
		//cv::resize(frame, frame, cv::Size(), 0.25, 0.25);
		emit output(frame);
	}
	else
		qDebug() << "Grabber: something went wrong during frame acquisition";
}

void Grabber::stop() {
	qDebug() << "Grabber: stop";
	timer->stop();
}

void Grabber::exit() {
	qDebug() << "Grabber: exit";
	if(cap.isOpened())
		cap.release();
}
