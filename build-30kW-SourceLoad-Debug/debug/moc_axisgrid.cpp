/****************************************************************************
** Meta object code from reading C++ file 'axisgrid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../axissetting/axisgrid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axisgrid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AxisGrid_t {
    QByteArrayData data[8];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AxisGrid_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AxisGrid_t qt_meta_stringdata_AxisGrid = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AxisGrid"
QT_MOC_LITERAL(1, 9, 22), // "changeMasterVisibility"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 21), // "changeMinorVisibility"
QT_MOC_LITERAL(4, 55, 17), // "changeMasterColor"
QT_MOC_LITERAL(5, 73, 16), // "changeMinorColor"
QT_MOC_LITERAL(6, 90, 20), // "changeMasterPenWidth"
QT_MOC_LITERAL(7, 111, 19) // "changeMinorPenWidth"

    },
    "AxisGrid\0changeMasterVisibility\0\0"
    "changeMinorVisibility\0changeMasterColor\0"
    "changeMinorColor\0changeMasterPenWidth\0"
    "changeMinorPenWidth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AxisGrid[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       3,    1,   47,    2, 0x08 /* Private */,
       4,    0,   50,    2, 0x08 /* Private */,
       5,    0,   51,    2, 0x08 /* Private */,
       6,    1,   52,    2, 0x08 /* Private */,
       7,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void AxisGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AxisGrid *_t = static_cast<AxisGrid *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeMasterVisibility((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeMinorVisibility((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeMasterColor(); break;
        case 3: _t->changeMinorColor(); break;
        case 4: _t->changeMasterPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->changeMinorPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AxisGrid::staticMetaObject = {
    { &AxisBox::staticMetaObject, qt_meta_stringdata_AxisGrid.data,
      qt_meta_data_AxisGrid,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AxisGrid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AxisGrid::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AxisGrid.stringdata0))
        return static_cast<void*>(this);
    return AxisBox::qt_metacast(_clname);
}

int AxisGrid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AxisBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
