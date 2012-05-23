#include "signalprocessor.h"

SignalProcessor::SignalProcessor(int bufLength) {
	dataLength = bufLength;

	dataRedIn = new QVector<double>(dataLength);
	dataGreenIn = new QVector<double>(dataLength);
	dataBlueIn = new QVector<double>(dataLength);

	dataRedOut = new QVector<double>(dataLength);
	dataGreenOut = new QVector<double>(dataLength);
	dataBlueOut= new QVector<double>(dataLength);
}

SignalProcessor::~SignalProcessor() {

}

void SignalProcessor::input(double red, double green, double blue) {
	qDebug() << "SignalProcessor: set Input" << red << green << blue;

	processData(dataRedIn, dataRedOut, red);
	processData(dataGreenIn, dataGreenOut, green);
	processData(dataBlueIn, dataBlueOut, blue);

	emit output(dataRedOut->last(), dataGreenOut->last(), dataBlueOut->last());
	qDebug() << "SignalProcessor: output " << dataRedOut->last() << dataGreenOut->last() << dataBlueOut->last();
}

void SignalProcessor::processData(QVector<double> *in, QVector<double> *out, double newValue) {
	in->erase(in->begin());
	in->append(newValue);

	double outValue = avgFilter(in,4);
	outValue = outValue - avgFilter(in,10);	//detrend by subtracting average

	out->erase(out->begin());
	out->append(outValue);
}

//averaging over the the last few samples
double SignalProcessor::avgFilter(QVector<double> *data, int l) {
	int length = l;
	double tmp = 0;
	for(int i=0; i<length; i++) {
		tmp += data->at(data->size()-i-1);
	}
	tmp = tmp/length;
	//data->replace(data->size()-1, tmp);
	return tmp;
}

