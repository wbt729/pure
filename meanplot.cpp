#include "meanplot.h"

MeanPlot::MeanPlot(QObject *parent) {
	scale = 1;
	floating = false;
	autoScale = false;
	int size=600;
	for(int i=0;i<size;i++) {
		dX.append((double) i);
//		dG.append(0);
	}
	dR = QVector<double>(size, 0);
	dG = QVector<double>(size, 0);
	dB = QVector<double>(size, 0);
	//setAutoReplot(true);
	setAxisAutoScale(QwtPlot::yLeft);
	QwtLinearScaleEngine *scaleEngine = new QwtLinearScaleEngine();
	scaleEngine->setReference(5);
	scaleEngine->setAttribute(QwtScaleEngine::Symmetric);
	setAxisScaleEngine(QwtPlot::yLeft, scaleEngine);

	setAutoReplot(true);
	QPen pen;
	pen.setWidth(1);
	pen.setColor(QColor(255,0,0,60));
	curveRed = new QwtPlotCurve();
	curveRed->setPen(pen);
	curveRed->setRenderHint(QwtPlotItem::RenderAntialiased);
	curveRed->setRawSamples(dX.data(), dR.data(), size);
	curveRed->attach(this);

	pen.setWidth(2);
	pen.setColor(Qt::darkGreen);
	curveGreen = new QwtPlotCurve();
	curveGreen->setPen(pen);
	curveGreen->setRenderHint(QwtPlotItem::RenderAntialiased);
	curveGreen->setRawSamples(dX.data(), dG.data(), size);
	curveGreen->attach(this);

	pen.setWidth(1);
	pen.setColor(QColor(0,0,255,60));
	curveBlue = new QwtPlotCurve();
	curveBlue->setPen(pen);
	curveBlue->setRenderHint(QwtPlotItem::RenderAntialiased);
	curveBlue->setRawSamples(dX.data(), dB.data(), size);
	curveBlue->attach(this);
}

MeanPlot::~MeanPlot() {
}

void MeanPlot::input(double meanRed, double meanGreen, double meanBlue) {
	qDebug() << "MeanPlot: update Data";
	dR.erase(dR.begin());
	dR.append(meanRed);

	dB.erase(dB.begin());
	dB.append(meanBlue);

	dG.erase(dG.begin());
	dG.append(meanGreen);

	if(!autoScale) {
		if(floating)
			setAxisScale(QwtPlot::yLeft, meanGreen-scale, meanGreen+scale);
		else
			setAxisScale(QwtPlot::yLeft, -scale, +scale);
	}
	else
		updateAxes();
}

void MeanPlot::mouseDoubleClickEvent(QMouseEvent *event) {
	floating = !floating;
}

//zoom
void MeanPlot::wheelEvent(QWheelEvent *event) {
	int numDegrees = event->delta()/8;
	scale -= numDegrees/8;
	scale = (scale < 1) ? 1 : scale;
}

//void MeanPlot::mousePressEvent(QMouseEvent *event) {
//	if(event->button() == Qt::RightButton)
//		autoScale = !autoScale;
//	if(autoScale)
//		setAxisAutoScale(QwtPlot::yLeft, true);
//	else
//		setAxisAutoScale(QwtPlot::yLeft, false);
//}
