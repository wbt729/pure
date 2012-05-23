#ifndef RECORDERWIDGET_H
#define RECORDERWIDGET_H

#include <QWidget>
#include <qdebug.h>
#include <QFile>
#include "ui_recorderwidget.h"

class RecorderWidget : public QWidget
{
	Q_OBJECT

public:
	RecorderWidget(QWidget *parent = 0);
	~RecorderWidget();

private:
	Ui::RecorderWidget ui;
	QString filename;
	QFile file;
	QTextStream out;

public slots:
	void input(double, double, double);
};

#endif // RECORDERWIDGET_H
