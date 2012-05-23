/****************************************************************************
** Meta object code from reading C++ file 'tracker.h'
**
** Created: Mon May 21 16:08:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tracker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tracker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tracker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,    8,    8,    8, 0x0a,
      41,    8,    8,    8, 0x0a,
      49,    8,    8,    8, 0x0a,
      56,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tracker[] = {
    "Tracker\0\0output(cv::Rect)\0input(cv::Mat)\0"
    "start()\0stop()\0roiFromFeatures()\0"
};

void Tracker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tracker *_t = static_cast<Tracker *>(_o);
        switch (_id) {
        case 0: _t->output((*reinterpret_cast< cv::Rect(*)>(_a[1]))); break;
        case 1: _t->input((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->start(); break;
        case 3: _t->stop(); break;
        case 4: _t->roiFromFeatures(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tracker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tracker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tracker,
      qt_meta_data_Tracker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tracker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tracker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tracker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tracker))
        return static_cast<void*>(const_cast< Tracker*>(this));
    return QObject::qt_metacast(_clname);
}

int Tracker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tracker::output(cv::Rect _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
