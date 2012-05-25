#ifndef PURE_H
#define PURE_H

#include <QtGui/QMainWindow>
#include <QtCore/QThread>
#include <QMessageBox>
#include "ui_pure.h"
#include "grabber.h"
#include "imagedisplay.h"
#include "imageprocessor.h"
#include "signalprocessor.h"
#include "fftwidget.h"
#include "recorderwidget.h"

//the meta types of the opencv datatypes have to be declared
//using this macro before one can use them in Qt's signal and
//slot system. also they have to be registered through a function
//call (see constructor definition in pure.cpp)
Q_DECLARE_METATYPE(cv::Rect)
Q_DECLARE_METATYPE(cv::Mat)

class pure : public QMainWindow {
    Q_OBJECT

public:
    pure(QWidget *parent = 0);
    ~pure();

private:
    Ui::pureClass ui;
    Grabber *grabber;

    ImageProcessor *imgProc;
    SignalProcessor *sigProc;
	RecorderWidget *recorder;

	QThread *grabberThread,
			*imgProcThread,
			*sigProcThread,
			*fftWidgetThread,
			*recorderThread;

private slots:
	void onNewSamples(double, double, double);
protected:
	virtual void closeEvent(QCloseEvent *);
};

#endif // PURE_H
