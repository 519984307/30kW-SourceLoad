/****************************************************************************
** Meta object code from reading C++ file 'axislabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../axissetting/axislabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axislabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AxisLabel_t {
    QByteArrayData data[7];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AxisLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AxisLabel_t qt_meta_stringdata_AxisLabel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AxisLabel"
QT_MOC_LITERAL(1, 10, 16), // "changeVisibility"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "changeAngle"
QT_MOC_LITERAL(4, 40, 11), // "changeColor"
QT_MOC_LITERAL(5, 52, 11), // "changeBrush"
QT_MOC_LITERAL(6, 64, 10) // "changeFont"

    },
    "AxisLabel\0changeVisibility\0\0changeAngle\0"
    "changeColor\0changeBrush\0changeFont"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AxisLabel[] = {

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
       4,    0,   45,    2, 0x08 /* Private */,
       5,    1,   46,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void AxisLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AxisLabel *_t = static_cast<AxisLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeVisibility((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changeColor(); break;
        case 3: _t->changeBrush((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeFont(); break;
        default: ;
        }
    }
}

const QMetaObject AxisLabel::staticMetaObject = {
    { &AxisBox::staticMetaObject, qt_meta_stringdata_AxisLabel.data,
      qt_meta_data_AxisLabel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AxisLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AxisLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AxisLabel.stringdata0))
        return static_cast<void*>(this);
    return AxisBox::qt_metacast(_clname);
}

int AxisLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
