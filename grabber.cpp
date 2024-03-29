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
	qDebug() << "Grabber: destructor";
	stop();
	exit();
}


//set parameters and open camera
int Grabber::init(double fS, int camNumber) {
	qDebug() << "Grabber: init";
	fpsTime = new QTime();
	samplingInterval = 1000/fS; //interval between two images in ms
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

//start recording
void Grabber::start() {
	qDebug() << "Grabber: start";
	fpsTime->start(); //this is used to determine the "real" time between two images
	timer->start(samplingInterval);
}

//get new frame from camera
void Grabber::grabFrame() {
	qDebug() << "Grabber: grab frame";
	if(cap.read(frame)) {
		int elapsed = fpsTime->elapsed();
		qDebug() << "Grabber: time elapsed" << elapsed << "fps:" << (double) 1000/elapsed;
		//qDebug() << "Grabber: fps" << cap.get(CV_CAP_PROP_FPS);
		//qDebug() << "Grabber: brightness" << cap.get(CV_CAP_PROP_BRIGHTNESS);
		//qDebug() << "Grabber: gain" << cap.get(CV_CAP_PROP_GAIN);
		//qDebug() << "Grabber: exposure" << cap.get(CV_CAP_PROP_EXPOSURE);
		fpsTime->restart();
		//downsampling at this point makes the program
		//run consideralby quicker
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

//release camera when exiting
void Grabber::exit() {
	qDebug() << "Grabber: exit";
	timer->stop();
	if(cap.isOpened())
		cap.release();
}
