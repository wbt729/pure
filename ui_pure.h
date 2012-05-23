/********************************************************************************
** Form generated from reading UI file 'pure.ui'
**
** Created: Mon May 21 19:28:24 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURE_H
#define UI_PURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "fftwidget.h"
#include "imagelabel.h"
#include "meanplot.h"

QT_BEGIN_NAMESPACE

class Ui_pureClass
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    MeanPlot *meanPlot;
    ImageLabel *display;
    FFTWidget *fftWidget;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelMean;
    QLabel *labelHr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pureClass)
    {
        if (pureClass->objectName().isEmpty())
            pureClass->setObjectName(QString::fromUtf8("pureClass"));
        pureClass->resize(952, 731);
        centralwidget = new QWidget(pureClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        meanPlot = new MeanPlot(centralwidget);
        meanPlot->setObjectName(QString::fromUtf8("meanPlot"));
        meanPlot->setFrameShape(QFrame::StyledPanel);
        meanPlot->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(meanPlot, 2, 0, 1, 1);

        display = new ImageLabel(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setFrameShape(QFrame::StyledPanel);
        display->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(display, 1, 0, 1, 1);

        fftWidget = new FFTWidget(centralwidget);
        fftWidget->setObjectName(QString::fromUtf8("fftWidget"));
        fftWidget->setMinimumSize(QSize(300, 100));
        fftWidget->setFrameShape(QFrame::StyledPanel);
        fftWidget->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(fftWidget, 1, 1, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        labelMean = new QLabel(frame);
        labelMean->setObjectName(QString::fromUtf8("labelMean"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelMean);

        labelHr = new QLabel(frame);
        labelHr->setObjectName(QString::fromUtf8("labelHr"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelHr);


        gridLayout->addWidget(frame, 2, 1, 1, 1);

        pureClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(pureClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 952, 20));
        pureClass->setMenuBar(menubar);
        statusbar = new QStatusBar(pureClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        pureClass->setStatusBar(statusbar);

        retranslateUi(pureClass);

        QMetaObject::connectSlotsByName(pureClass);
    } // setupUi

    void retranslateUi(QMainWindow *pureClass)
    {
        pureClass->setWindowTitle(QApplication::translate("pureClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("pureClass", "Heartrate Estimation:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("pureClass", "Mean Brightess of ROI:", 0, QApplication::UnicodeUTF8));
        labelMean->setText(QApplication::translate("pureClass", "n/A", 0, QApplication::UnicodeUTF8));
        labelHr->setText(QApplication::translate("pureClass", "n/A", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class pureClass: public Ui_pureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURE_H
