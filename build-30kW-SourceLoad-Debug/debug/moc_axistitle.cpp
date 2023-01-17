/****************************************************************************
** Meta object code from reading C++ file 'axistitle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../axissetting/axistitle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axistitle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AxisTitle_t {
    QByteArrayData data[7];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AxisTitle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AxisTitle_t qt_meta_stringdata_AxisTitle = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AxisTitle"
QT_MOC_LITERAL(1, 10, 16), // "changeVisibility"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "changeText"
QT_MOC_LITERAL(4, 39, 11), // "changeColor"
QT_MOC_LITERAL(5, 51, 11), // "changeBrush"
QT_MOC_LITERAL(6, 63, 10) // "changeFont"

    },
    "AxisTitle\0changeVisibility\0\0changeText\0"
    "changeColor\0changeBrush\0changeFont"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AxisTitle[] = {

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
       3,    0,   42,    2, 0x08 /* Private */,
       4,    0,   43,    2, 0x08 /* Private */,
       5,    1,   44,    2, 0x08 /* Private */,
       6,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void AxisTitle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AxisTitle *_t = static_cast<AxisTitle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeVisibility((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeText(); break;
        case 2: _t->changeColor(); break;
        case 3: _t->changeBrush((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeFont(); break;
        default: ;
        }
    }
}

const QMetaObject AxisTitle::staticMetaObject = {
    { &AxisBox::staticMetaObject, qt_meta_stringdata_AxisTitle.data,
      qt_meta_data_AxisTitle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AxisTitle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AxisTitle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AxisTitle.stringdata0))
        return static_cast<void*>(this);
    return AxisBox::qt_metacast(_clname);
}

int AxisTitle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AxisBox::qt_metacall(_c, _id, _a);
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
