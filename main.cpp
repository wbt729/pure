#include "pure.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pure w;
    w.show();
    return a.exec();
}
