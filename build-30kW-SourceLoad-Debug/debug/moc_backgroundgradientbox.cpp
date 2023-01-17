/****************************************************************************
** Meta object code from reading C++ file 'backgroundgradientbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chartsetting/backgroundgradientbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backgroundgradientbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChartBackgroundGradientBox_t {
    QByteArrayData data[10];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChartBackgroundGradientBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChartBackgroundGradientBox_t qt_meta_stringdata_ChartBackgroundGradientBox = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ChartBackgroundGradientBox"
QT_MOC_LITERAL(1, 27, 21), // "coordinateModeChanged"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 25), // "QGradient::CoordinateMode"
QT_MOC_LITERAL(4, 76, 13), // "spreadChanged"
QT_MOC_LITERAL(5, 90, 17), // "QGradient::Spread"
QT_MOC_LITERAL(6, 108, 19), // "gradientTypeChanged"
QT_MOC_LITERAL(7, 128, 15), // "QGradient::Type"
QT_MOC_LITERAL(8, 144, 20), // "linearGradientParams"
QT_MOC_LITERAL(9, 165, 29) // "QVector<QPair<qreal,QColor> >"

    },
    "ChartBackgroundGradientBox\0"
    "coordinateModeChanged\0\0QGradient::CoordinateMode\0"
    "spreadChanged\0QGradient::Spread\0"
    "gradientTypeChanged\0QGradient::Type\0"
    "linearGradientParams\0QVector<QPair<qreal,QColor> >"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChartBackgroundGradientBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       8,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void ChartBackgroundGradientBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChartBackgroundGradientBox *_t = static_cast<ChartBackgroundGradientBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->coordinateModeChanged((*reinterpret_cast< QGradient::CoordinateMode(*)>(_a[1]))); break;
        case 1: _t->spreadChanged((*reinterpret_cast< QGradient::Spread(*)>(_a[1]))); break;
        case 2: _t->gradientTypeChanged((*reinterpret_cast< QGradient::Type(*)>(_a[1]))); break;
        case 3: _t->linearGradientParams((*reinterpret_cast< QVector<QPair<qreal,QColor> >(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ChartBackgroundGradientBox::*_t)(QGradient::CoordinateMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartBackgroundGradientBox::coordinateModeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChartBackgroundGradientBox::*_t)(QGradient::Spread );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartBackgroundGradientBox::spreadChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChartBackgroundGradientBox::*_t)(QGradient::Type );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartBackgroundGradientBox::gradientTypeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ChartBackgroundGradientBox::*_t)(QVector<QPair<qreal,QColor>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartBackgroundGradientBox::linearGradientParams)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ChartBackgroundGradientBox::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_ChartBackgroundGradientBox.data,
      qt_meta_data_ChartBackgroundGradientBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChartBackgroundGradientBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChartBackgroundGradientBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChartBackgroundGradientBox.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int ChartBackgroundGradientBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ChartBackgroundGradientBox::coordinateModeChanged(QGradient::CoordinateMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChartBackgroundGradientBox::spreadChanged(QGradient::Spread _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChartBackgroundGradientBox::gradientTypeChanged(QGradient::Type _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChartBackgroundGradientBox::linearGradientParams(QVector<QPair<qreal,QColor>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
