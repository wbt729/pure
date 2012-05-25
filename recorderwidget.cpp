#include "recorderwidget.h"

RecorderWidget::RecorderWidget(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	file.setFileName("bla.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Text);	
}

RecorderWidget::~RecorderWidget() {
	qDebug() << "RecorderWidget: destructor";
	file.close();
}

void RecorderWidget::input(double red, double green, double blue) {
	qDebug() << "RecorderWidget: write samples to file";
	out.setDevice(&file);
	out << red << "\t" << green << "\t" << blue << "\n";
}