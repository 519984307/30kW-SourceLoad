/****************************************************************************
** Meta object code from reading C++ file 'axislog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../axissetting/axislog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axislog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AxisLog_t {
    QByteArrayData data[7];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AxisLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AxisLog_t qt_meta_stringdata_AxisLog = {
    {
QT_MOC_LITERAL(0, 0, 7), // "AxisLog"
QT_MOC_LITERAL(1, 8, 10), // "changeBase"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "changeMin"
QT_MOC_LITERAL(4, 30, 9), // "changeMax"
QT_MOC_LITERAL(5, 40, 20), // "changeMinorTickCount"
QT_MOC_LITERAL(6, 61, 17) // "changeLabelFormat"

    },
    "AxisLog\0changeBase\0\0changeMin\0changeMax\0"
    "changeMinorTickCount\0changeLabelFormat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AxisLog[] = {

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
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void AxisLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AxisLog *_t = static_cast<AxisLog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeBase((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->changeMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changeMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->changeMinorTickCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeLabelFormat(); break;
        default: ;
        }
    }
}

const QMetaObject AxisLog::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_AxisLog.data,
      qt_meta_data_AxisLog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AxisLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AxisLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AxisLog.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int AxisLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
