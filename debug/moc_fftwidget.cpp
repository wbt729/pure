/****************************************************************************
** Meta object code from reading C++ file 'fftwidget.h'
**
** Created: Mon May 21 16:08:42 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fftwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fftwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FFTWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   36,   10,   10, 0x0a,
      72,   10,   10,   10, 0x0a,
      80,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FFTWidget[] = {
    "FFTWidget\0\0newHrEstimation(QString)\0"
    ",,\0addSamples(double,double,double)\0"
    "doFft()\0doHrDetection()\0"
};

void FFTWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FFTWidget *_t = static_cast<FFTWidget *>(_o);
        switch (_id) {
        case 0: _t->newHrEstimation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addSamples((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->doFft(); break;
        case 3: _t->doHrDetection(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FFTWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FFTWidget::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_FFTWidget,
      qt_meta_data_FFTWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FFTWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FFTWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FFTWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FFTWidget))
        return static_cast<void*>(const_cast< FFTWidget*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int FFTWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FFTWidget::newHrEstimation(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
