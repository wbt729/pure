#include "pure.h"

pure::pure(QWidget *parent) : QMainWindow(parent) {
	qRegisterMetaType<cv::Rect>("cv::Rect");
	qRegisterMetaType<cv::Mat>("cv::Mat");
	ui.setupUi(this);

	grabber = new Grabber();
	sigProc = new SignalProcessor();
	imgProc = new ImageProcessor(1);

	grabberThread = new QThread();
	imgProcThread = new QThread();
	sigProcThread = new QThread();
	fftWidgetThread = new QThread();

	ui.fftWidget->moveToThread(fftWidgetThread);
	grabber->moveToThread(sigProcThread);
	imgProc->moveToThread(imgProcThread);
	sigProc->moveToThread(grabberThread);
	grabberThread->start();
	imgProcThread->start();
	sigProcThread->start();
	fftWidgetThread->start();

	connect(grabber, SIGNAL(output(cv::Mat)), ui.display, SLOT(setFrame(cv::Mat)));

	connect(grabber, SIGNAL(output(cv::Mat)), imgProc, SLOT(input(cv::Mat)));
	connect(imgProc, SIGNAL(output(double, double, double)), sigProc, SLOT(input(double, double, double)));
	connect(sigProc, SIGNAL(output(double, double, double)), ui.meanPlot, SLOT(input(double, double, double)));

	connect(imgProc, SIGNAL(newRoi(cv::Rect)), ui.display, SLOT(setRoi(cv::Rect)));

	connect(sigProc, SIGNAL(output(double, double, double)), ui.fftWidget, SLOT(addSamples(double, double, double)));
	connect(ui.fftWidget, SIGNAL(newHrEstimation(QString)), ui.labelHr, SLOT(setText(const QString &)));
	connect(imgProc, SIGNAL(output(double, double, double)), this, SLOT(onNewSamples(double, double, double)));

	if(grabber->init(15,0) == 0)
		grabber->start();
}

pure::~pure() {
}

void pure::onNewSamples(double red, double green, double blue) {
	ui.labelMean->setText(tr("%1").arg(qFloor(red+green+blue)/3));
}
