//The FFTWidget takes a (prefiltered) three-pair of samles (rgb), as input.
//It calculates and displays the FFT of this timeseries using fftw and makes a
//heart rate estimation based on the highest peak in a physiologically
//relevant frequency range

#ifndef FFTWIDGET_H_
#define FFTWIDGET_H_

#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_marker.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_directpainter.h>
#include <qwt/qwt_scale_engine.h>
#include <QTimer>
#include <QVector>
#include <fftw3.h>

class FFTWidget : public QwtPlot {
	Q_OBJECT
public:
	FFTWidget(QObject *parent = NULL);
	FFTWidget(int f, int size, int i, QObject *parent = NULL);
	virtual ~FFTWidget();
private:
	QwtPlotCurve *curve;
	QVector<double> dX, dY, dYBuf, dataIn, hamming;
	int size, fftInterval, sampleInterval, counter;
	double hrBpm, fS;
	void init();
	fftw_plan p;
	QwtPlotMarker *hrMarker, *hrLabel;
public slots:
	void addSamples(double, double, double);
	void doFft();
	void doHrDetection();
signals:
	void newHrEstimation(QString);
};

#endif /* FFTWIDGET_H_ */
