/****************************************************************************
** Meta object code from reading C++ file 'backgroundareagradient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chartsetting/backgroundareagradient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backgroundareagradient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackgroundAreaGradient_t {
    QByteArrayData data[16];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackgroundAreaGradient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackgroundAreaGradient_t qt_meta_stringdata_BackgroundAreaGradient = {
    {
QT_MOC_LITERAL(0, 0, 22), // "BackgroundAreaGradient"
QT_MOC_LITERAL(1, 23, 20), // "interpolationChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 28), // "QGradient::InterpolationMode"
QT_MOC_LITERAL(4, 74, 17), // "coordinateChanged"
QT_MOC_LITERAL(5, 92, 25), // "QGradient::CoordinateMode"
QT_MOC_LITERAL(6, 118, 13), // "spreadChanged"
QT_MOC_LITERAL(7, 132, 17), // "QGradient::Spread"
QT_MOC_LITERAL(8, 150, 19), // "gradientTypeChanged"
QT_MOC_LITERAL(9, 170, 15), // "QGradient::Type"
QT_MOC_LITERAL(10, 186, 14), // "gradientParams"
QT_MOC_LITERAL(11, 201, 29), // "QVector<QPair<qreal,QColor> >"
QT_MOC_LITERAL(12, 231, 20), // "radialGradientParams"
QT_MOC_LITERAL(13, 252, 38), // "RadialGradientParamWidget::Ra..."
QT_MOC_LITERAL(14, 291, 21), // "conicalGradientParams"
QT_MOC_LITERAL(15, 313, 40) // "ConicalGradientParamWidget::C..."

    },
    "BackgroundAreaGradient\0interpolationChanged\0"
    "\0QGradient::InterpolationMode\0"
    "coordinateChanged\0QGradient::CoordinateMode\0"
    "spreadChanged\0QGradient::Spread\0"
    "gradientTypeChanged\0QGradient::Type\0"
    "gradientParams\0QVector<QPair<qreal,QColor> >\0"
    "radialGradientParams\0"
    "RadialGradientParamWidget::RadialParam\0"
    "conicalGradientParams\0"
    "ConicalGradientParamWidget::ConicalParam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackgroundAreaGradient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       8,    1,   78,    2, 0x06 /* Public */,
      10,    2,   81,    2, 0x06 /* Public */,
      12,    3,   86,    2, 0x06 /* Public */,
      12,    2,   93,    2, 0x26 /* Public | MethodCloned */,
      12,    1,   98,    2, 0x26 /* Public | MethodCloned */,
      14,    3,  101,    2, 0x06 /* Public */,
      14,    2,  108,    2, 0x26 /* Public | MethodCloned */,
      14,    1,  113,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 9,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Bool, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Bool, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 15,    2,

       0        // eod
};

void BackgroundAreaGradient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackgroundAreaGradient *_t = static_cast<BackgroundAreaGradient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->interpolationChanged((*reinterpret_cast< QGradient::InterpolationMode(*)>(_a[1]))); break;
        case 1: _t->coordinateChanged((*reinterpret_cast< QGradient::CoordinateMode(*)>(_a[1]))); break;
        case 2: _t->spreadChanged((*reinterpret_cast< QGradient::Spread(*)>(_a[1]))); break;
        case 3: _t->gradientTypeChanged((*reinterpret_cast< QGradient::Type(*)>(_a[1]))); break;
        case 4: _t->gradientParams((*reinterpret_cast< QVector<QPair<qreal,QColor> >(*)>(_a[1])),(*reinterpret_cast< QGradient::Type(*)>(_a[2]))); break;
        case 5: _t->radialGradientParams((*reinterpret_cast< RadialGradientParamWidget::RadialParam(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->radialGradientParams((*reinterpret_cast< RadialGradientParamWidget::RadialParam(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->radialGradientParams((*reinterpret_cast< RadialGradientParamWidget::RadialParam(*)>(_a[1]))); break;
        case 8: _t->conicalGradientParams((*reinterpret_cast< ConicalGradientParamWidget::ConicalParam(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 9: _t->conicalGradientParams((*reinterpret_cast< ConicalGradientParamWidget::ConicalParam(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->conicalGradientParams((*reinterpret_cast< ConicalGradientParamWidget::ConicalParam(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BackgroundAreaGradient::*_t)(QGradient::InterpolationMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundAreaGradient::interpolationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BackgroundAreaGradient::*_t)(QGradient::CoordinateMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundAreaGradient::coordinateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BackgroundAreaGradient::*_t)(QGradient::Spread );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundAreaGradient::spreadChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BackgroundAreaGradient::*_t)(QGradient::Type );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundAreaGradient::gradientTypeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BackgroundAreaGradient::*_t)(QVector<QPair<qreal,QColor>> , QGradient::Type );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundAreaGradient::gradientParams)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (BackgroundAreaGradient::*_t)(RadialGradientParamWidget::RadialParam , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundAreaGradient::radialGradientParams)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (BackgroundAreaGradient::*_t)(ConicalGradientParamWidget::ConicalParam , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundAreaGradient::conicalGradientParams)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject BackgroundAreaGradient::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_BackgroundAreaGradient.data,
      qt_meta_data_BackgroundAreaGradient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BackgroundAreaGradient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackgroundAreaGradient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackgroundAreaGradient.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int BackgroundAreaGradient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void BackgroundAreaGradient::interpolationChanged(QGradient::InterpolationMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BackgroundAreaGradient::coordinateChanged(QGradient::CoordinateMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BackgroundAreaGradient::spreadChanged(QGradient::Spread _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BackgroundAreaGradient::gradientTypeChanged(QGradient::Type _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BackgroundAreaGradient::gradientParams(QVector<QPair<qreal,QColor>> _t1, QGradient::Type _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BackgroundAreaGradient::radialGradientParams(RadialGradientParamWidget::RadialParam _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 8
void BackgroundAreaGradient::conicalGradientParams(ConicalGradientParamWidget::ConicalParam _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
