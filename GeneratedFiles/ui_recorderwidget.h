/********************************************************************************
** Form generated from reading UI file 'recorderwidget.ui'
**
** Created: Fri 25. May 13:09:00 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDERWIDGET_H
#define UI_RECORDERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecorderWidget
{
public:

    void setupUi(QWidget *RecorderWidget)
    {
        if (RecorderWidget->objectName().isEmpty())
            RecorderWidget->setObjectName(QString::fromUtf8("RecorderWidget"));
        RecorderWidget->resize(400, 300);

        retranslateUi(RecorderWidget);

        QMetaObject::connectSlotsByName(RecorderWidget);
    } // setupUi

    void retranslateUi(QWidget *RecorderWidget)
    {
        RecorderWidget->setWindowTitle(QApplication::translate("RecorderWidget", "RecorderWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RecorderWidget: public Ui_RecorderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDERWIDGET_H
