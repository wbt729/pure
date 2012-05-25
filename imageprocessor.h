//The ImageProcesssor takes an image as input and outputs a three-pair of samples (rgb)
//Everything that is image processing related goes in here

#ifndef IMAGEPROCESSOR_H_
#define IMAGEPROCESSOR_H_

#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtCore/QDebug>
#include <QtCore/QRect>
#include <QtCore/QThread>
#include <opencv2/opencv.hpp>
#include "tracker.h"

class ImageProcessor :public QObject {
	Q_OBJECT
public:
	ImageProcessor(int roiMode = 1);
	virtual ~ImageProcessor();
public slots:
	void input(cv::Mat);
	void setQRectRoi(QRect);
	void setCvRectRoi(cv::Rect);

private:
	QThread *trackerThread;
	void setTracking(bool);
	void extractSamples();
	void updateRoi();
	void getMeanValues();
	void roiFromFeatureTracking();
	cv::Mat image;
	cv::Rect roi; //internal ROI derives from face tracking, external can be set from GUI
	bool busy;
	double red, green, blue;
	int roiMode;	//0 = external, 1 = face tracking
	Tracker *tracker;
	cv::Mat roiFrame;
signals:
	void output(double, double, double);
	void newRoi(cv::Rect);
	void newFrame(cv::Mat); //only for testing
};

#endif /* IMAGEPROCESSOR_H_ */
