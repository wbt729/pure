#include "recorderwidget.h"

RecorderWidget::RecorderWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	file.setFileName("d:\\bla.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Text);	
}

RecorderWidget::~RecorderWidget() {
	file.close();
}

void RecorderWidget::input(double red, double green, double blue) {
	out.setDevice(&file);
	out << red << "\t" << green << "\t" << blue << "\n";
}