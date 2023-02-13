/****************************************************************************
** Meta object code from reading C++ file 'seriespie.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../seriessetting/seriespie.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'seriespie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SeriesPie_t {
    QByteArrayData data[9];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SeriesPie_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SeriesPie_t qt_meta_stringdata_SeriesPie = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SeriesPie"
QT_MOC_LITERAL(1, 10, 19), // "changeLabelPosition"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "changeStartAngle"
QT_MOC_LITERAL(4, 48, 14), // "changeEndAngle"
QT_MOC_LITERAL(5, 63, 14), // "changeHoleSize"
QT_MOC_LITERAL(6, 78, 13), // "changePieSize"
QT_MOC_LITERAL(7, 92, 15), // "changeHPosition"
QT_MOC_LITERAL(8, 108, 15) // "changeVPosition"

    },
    "SeriesPie\0changeLabelPosition\0\0"
    "changeStartAngle\0changeEndAngle\0"
    "changeHoleSize\0changePieSize\0"
    "changeHPosition\0changeVPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SeriesPie[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       3,    1,   52,    2, 0x08 /* Private */,
       4,    1,   55,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       6,    1,   61,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void SeriesPie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SeriesPie *_t = static_cast<SeriesPie *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeLabelPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeStartAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changeEndAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->changeHoleSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->changePieSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->changeHPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->changeVPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SeriesPie::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_SeriesPie.data,
      qt_meta_data_SeriesPie,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SeriesPie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SeriesPie::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SeriesPie.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int SeriesPie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
