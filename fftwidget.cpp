#include "fftwidget.h"

FFTWidget::FFTWidget(QObject *parent) {
	fS = 15.0;
	size = 256;
	fftInterval = 100; // in ms
	init();
}

FFTWidget::FFTWidget(int f, int sz, int i, QObject *parent) {
	fS = f;
	size = sz;
	fftInterval = i;
	init();
}

void FFTWidget::init() {
	setTitle("FFT");
	hrBpm = 0;
	hrMarker = new QwtPlotMarker();
	hrMarker->setLineStyle(QwtPlotMarker::VLine);
	hrMarker->setLinePen(QPen(QColor(255,255,255,100), 2, Qt::SolidLine));

	QPen pen;
	pen.setWidth(2);
	pen.setColor(Qt::blue);
	QwtSymbol *symb = new QwtSymbol(QwtSymbol::Diamond);
	symb->setPen(pen);
	symb->setSize(10);

	hrMarker->setSymbol(symb);
	hrMarker->attach(this);
	hrMarker->setVisible(false);
	setAxisAutoScale(QwtPlot::yLeft, true);
	counter = 0;
	dX = QVector<double>(size, 0);
	dY = QVector<double>(size, 0);
	dYBuf = QVector<double>(size, 0);
	hamming = QVector<double>(size, 0);

	dataIn = QVector<double>(size, 0);
	sampleInterval = 1000/fS;
	p = fftw_plan_r2r_1d( size, dataIn.data(), dYBuf.data(), FFTW_DHT, FFTW_ESTIMATE );

	for(int i=0;i<size;i++) {
		dX.replace(i, i*(fS/size));
		double tmp = 0.54 - 0.46*(2*3.1415*i/size);
		hamming.replace(i, tmp);
	}

	pen.setColor(Qt::red);

	curve = new QwtPlotCurve();
	curve->setPen(pen);
	curve->setRawSamples(dX.data(), dY.data(), size/2);
	curve->setRenderHint(QwtPlotItem::RenderAntialiased);
	curve->attach(this);
}

FFTWidget::~FFTWidget() {
	// TODO Auto-generated destructor stub
}

void FFTWidget::addSamples(double red, double green, double blue) {
	qDebug() << "FFTWidget: add sample" << green;
	dataIn.erase(dataIn.begin());
	dataIn.append(green);
	counter++;
	if(counter >= fftInterval/sampleInterval) {
		doFft();
		counter = 0;
	}
}

void FFTWidget::doFft() {
	qDebug() << "FFTWidget: do FFT";
	//input filter, removes movement artifacts as far as possible
	for(int i=0; i<dataIn.size(); i++) {
		if(dataIn.at(i) > 2 || dataIn.at(i) < -2) {
			for(int j=-20; j<20; j++) {
				if(i+j >=0 && i+j < dataIn.size())
					dataIn.replace(i+j, 0);
			}
		}
	}


	fftw_execute(p);	//apply fft
		
	//add old and new fft in a weighted sum
	double weightOld = 0.9;
	double weightNew = 1 - weightOld;

	for(int i=0; i<size; i++) {
			double buf = dY.at(i)*weightOld + abs(dYBuf.at(i)*weightNew);
			dY.replace(i, buf);
	}

	doHrDetection();
	curve->setRawSamples(dX.data(), dY.data(), size/2);

	//scale the y-axis of the plot according to the
	//highest value and limit the display to a minimum
	//axis height, so that we don't look at inflated noise
	double scaleMinYValue = 5;
	//get max value for scaling
	double max = 0;
	for(int i=0; i<dY.size()/2; i++) {
		if(dY.at(i) > max)
			max = dY.at(i);
	}
	//set scale
	if(max < scaleMinYValue)
		setAxisScale(QwtPlot::yLeft, 0, scaleMinYValue);
	else
		setAxisScale(QwtPlot::yLeft, 0, max);
	replot();	
}

//detect largest peak in physiologically relevant
//range of the amplitude spectrum
//emit heartrate estimation as string
void FFTWidget::doHrDetection() {
	double weightNew = 0.1;
	double weightOld = 1 - weightNew;
	double max = 0;
	int maxIndex = 0;
	int indexLower = size*0.7/fS;
	int indexHigher = size*3/fS;
	//find peak
	for(int i=indexLower; i<indexHigher; i++) {
		if(dY.at(i) > max) {
			max = dY.at(i); maxIndex = i;
		}
	}
	double peakFreqHz = maxIndex*(fS/size);
	if( peakFreqHz > 0.7 && peakFreqHz < 3) {
		hrMarker->setValue(peakFreqHz, max);
		hrMarker->setVisible(true);
	}
	else
		hrMarker->setVisible(false);
	double hrBpmNew = peakFreqHz*60;
	if(hrBpmNew > 40) {
		hrBpm = weightOld*hrBpm + weightNew*hrBpmNew;
		qDebug() << "FFTWidget: new hr estimation" << hrBpm;
	}
	if(hrBpm > 40) {
		QString hrEstimation = QString(tr("%1 bpm").arg(qFloor(hrBpm)));
		emit newHrEstimation(hrEstimation);
	}
}
