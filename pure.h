#ifndef PURE_H
#define PURE_H

#include <QtGui/QMainWindow>
#include <QtCore/QThread>
#include "ui_pure.h"
#include "grabber.h"
#include "imagedisplay.h"
#include "imageprocessor.h"
#include "signalprocessor.h"
#include "fftwidget.h"

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
    QThread *grabberThread;
    QThread *imgProcThread;
    QThread *sigProcThread;
    QThread *fftWidgetThread;
    ImageProcessor *imgProc;
    SignalProcessor *sigProc;
private slots:
	void onNewSamples(double, double, double);
protected:
	virtual void closeEvent(QCloseEvent *);
};

#endif // PURE_H
