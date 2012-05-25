#include "pure.h"

pure::pure(QWidget *parent) : QMainWindow(parent) {
	//the meta types of the opencv datatypes have to be registered
	//that one can use them in Qt's signal and slot system
	qRegisterMetaType<cv::Rect>("cv::Rect");
	qRegisterMetaType<cv::Mat>("cv::Mat");

	ui.setupUi(this);
	//setAttribute(Qt::WA_DeleteOnClose);

	grabber = new Grabber();
	sigProc = new SignalProcessor();
	imgProc = new ImageProcessor(1);
	recorder = new RecorderWidget();

	//QThread is a thread handling class, that represents the thread
	//itself. The code that is run inside the thread is determined
	//by moving a QObject to the thread. once the thread is started
	//the QObject behaves as it normally would but runs inside the
	//thread.
	grabberThread = new QThread(this);
	imgProcThread = new QThread(this);
	sigProcThread = new QThread(this);
	recorderThread = new QThread(this);

	grabber->moveToThread(sigProcThread);
	imgProc->moveToThread(imgProcThread);
	sigProc->moveToThread(grabberThread);
	recorder->moveToThread(recorderThread);

	grabberThread->start();
	imgProcThread->start();
	sigProcThread->start();
	recorderThread->start();

	//the connections of the singal and slot system. when you connect two QObjects
	//using
	//    connect(sender, signal, receiver, slot)
	//the slot function gets called everytime the sender emits the signal.
	//signals can also carry data. datatypes unknown to Qt (here cv::Mat and cv::Rect)
	//must be declared and registered first.
	connect(grabber, SIGNAL(output(cv::Mat)), ui.display, SLOT(setFrame(cv::Mat)));
	connect(grabber, SIGNAL(output(cv::Mat)), imgProc, SLOT(input(cv::Mat)));

	connect(imgProc, SIGNAL(output(double, double, double)), sigProc, SLOT(input(double, double, double)));
	connect(imgProc, SIGNAL(output(double, double, double)), recorder, SLOT(input(double, double, double)));
	connect(imgProc, SIGNAL(output(double, double, double)), this, SLOT(onNewSamples(double, double, double)));
	connect(imgProc, SIGNAL(newRoi(cv::Rect)), ui.display, SLOT(setRoi(cv::Rect)));

	connect(sigProc, SIGNAL(output(double, double, double)), ui.meanPlot, SLOT(input(double, double, double)));
	connect(sigProc, SIGNAL(output(double, double, double)), ui.fftWidget, SLOT(addSamples(double, double, double)));
	
	connect(ui.fftWidget, SIGNAL(newHrEstimation(QString)), ui.labelHr, SLOT(setText(const QString &)));
	
	if(grabber->init(15,0) == 0) {
		//showFullScreen();
		grabber->start();
		showMaximized();
	}
	else {
		QMessageBox msgBox;
		msgBox.setText("No camera found, ending now.");
		msgBox.exec();
		close();
	}
}

pure::~pure() {
	qDebug() << "Pure: destructor";
}

void pure::onNewSamples(double red, double green, double blue) {
	ui.labelMean->setText(tr("%1").arg(qFloor(red+green+blue)/3));	//display avg brightness of ROI
}

//release camera or the grabber thread will not
//stop when the mainwindow is closed. meaning
//the program will never stop
void pure::closeEvent(QCloseEvent *e) {
	grabber->exit();
	//grabber->blockSignals(true);
	//imgProc->blockSignals(true);
	//sigProc->blockSignals(true);
	//QApplication::processEvents();
	//grabberThread->quit();
	//grabberThread->wait();
	//imgProcThread->quit();
	//imgProcThread->wait();
	//sigProcThread->quit();
	//sigProcThread->wait();
	//recorderThread->quit();
	//recorderThread->wait();
	//delete recorder;
}
