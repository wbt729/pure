/****************************************************************************
** Meta object code from reading C++ file 'imageprocessor.h'
**
** Created: Mon May 21 16:08:50 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imageprocessor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageProcessor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   16,   15,   15, 0x05,
      48,   15,   15,   15, 0x05,
      65,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,   15,   15,   15, 0x0a,
      98,   15,   15,   15, 0x0a,
     117,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageProcessor[] = {
    "ImageProcessor\0\0,,\0output(double,double,double)\0"
    "newRoi(cv::Rect)\0newFrame(cv::Mat)\0"
    "input(cv::Mat)\0setQRectRoi(QRect)\0"
    "setCvRectRoi(cv::Rect)\0"
};

void ImageProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageProcessor *_t = static_cast<ImageProcessor *>(_o);
        switch (_id) {
        case 0: _t->output((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: _t->newRoi((*reinterpret_cast< cv::Rect(*)>(_a[1]))); break;
        case 2: _t->newFrame((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->input((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 4: _t->setQRectRoi((*reinterpret_cast< QRect(*)>(_a[1]))); break;
        case 5: _t->setCvRectRoi((*reinterpret_cast< cv::Rect(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageProcessor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageProcessor,
      qt_meta_data_ImageProcessor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageProcessor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessor))
        return static_cast<void*>(const_cast< ImageProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ImageProcessor::output(double _t1, double _t2, double _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageProcessor::newRoi(cv::Rect _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImageProcessor::newFrame(cv::Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
