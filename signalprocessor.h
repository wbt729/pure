/*
 * SignalProcessor.h
 *
 *  Created on: May 16, 2012
 *      Author: wbt729
 */

#ifndef SIGNALPROCESSOR_H_
#define SIGNALPROCESSOR_H_

#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <opencv2/opencv.hpp>

class SignalProcessor : public QObject {
	Q_OBJECT
public:
	SignalProcessor(int bufLength = 512);
	virtual ~SignalProcessor();
public slots:
	void input(double, double, double);	// samples of three color channels
signals:
	void output(double, double, double);
private:
	QVector<double> *dataRedIn;
	QVector<double> *dataGreenIn;
	QVector<double> *dataBlueIn;
	QVector<double> *dataRedOut;
	QVector<double> *dataGreenOut;
	QVector<double> *dataBlueOut;
	int dataLength;
	void processData(QVector<double> *, QVector<double> *, double);
	double avgFilter(QVector<double> *, int l = 2);
};

#endif /* SIGNALPROCESSOR_H_ */
