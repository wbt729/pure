/*
 * ImageLabel.h
 *
 *  Created on: May 16, 2012
 *      Author: wbt729
 */

#ifndef ImageLabel_H_
#define ImageLabel_H_

#include<QtGui/QLabel>
#include<QtGui/QPainter>
#include <QtCore/QDebug>
#include <opencv2/opencv.hpp>

class ImageLabel : public QLabel {
	Q_OBJECT

public:
	ImageLabel(QObject *parent = NULL);
	virtual ~ImageLabel();
public slots:
	void setFrame(cv::Mat);
	void setRoi(cv::Rect);
private:
	QPixmap pixmap;
	QRect roi;
};

#endif /* ImageLabel_H_ */
