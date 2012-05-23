#ifndef PLOT_H_
#define PLOT_H_

#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_directpainter.h>
#include <qwt/qwt_scale_engine.h>
#include <QTimer>
#include <QWheelEvent>

class MeanPlot : public QwtPlot {
	Q_OBJECT
	public:
		MeanPlot(QObject *parent = NULL);
		virtual ~MeanPlot();
	private:
		bool floating, autoScale;
		QwtPlot *plot;
		QwtPlotDirectPainter *painter;
		QwtPlotCurve *curveGreen;
		QwtPlotCurve *curveRed;
		QwtPlotCurve *curveBlue;

		QVector<double> dX, dR, dG, dB;
		QwtLinearScaleEngine *scaleEngine;
		int scale;

	public slots:
		void input(double, double, double);
	protected:
		virtual void mouseDoubleClickEvent(QMouseEvent *);
		virtual void mousePressEvent(QMouseEvent *);
		virtual void wheelEvent(QWheelEvent *);
};

#endif /* PLOT_H_ */
