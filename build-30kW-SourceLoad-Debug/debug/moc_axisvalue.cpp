/****************************************************************************
** Meta object code from reading C++ file 'axisvalue.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../axissetting/axisvalue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axisvalue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AxisValue_t {
    QByteArrayData data[7];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AxisValue_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AxisValue_t qt_meta_stringdata_AxisValue = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AxisValue"
QT_MOC_LITERAL(1, 10, 9), // "changeMin"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "changeMax"
QT_MOC_LITERAL(4, 31, 15), // "changeTickCount"
QT_MOC_LITERAL(5, 47, 20), // "changeMinorTickCount"
QT_MOC_LITERAL(6, 68, 17) // "changeLabelFormat"

    },
    "AxisValue\0changeMin\0\0changeMax\0"
    "changeTickCount\0changeMinorTickCount\0"
    "changeLabelFormat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AxisValue[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       3,    1,   42,    2, 0x08 /* Private */,
       4,    1,   45,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void AxisValue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AxisValue *_t = static_cast<AxisValue *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->changeMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changeTickCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeMinorTickCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeLabelFormat(); break;
        default: ;
        }
    }
}

const QMetaObject AxisValue::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_AxisValue.data,
      qt_meta_data_AxisValue,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AxisValue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AxisValue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AxisValue.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int AxisValue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE