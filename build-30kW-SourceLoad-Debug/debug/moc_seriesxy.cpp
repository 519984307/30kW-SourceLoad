/****************************************************************************
** Meta object code from reading C++ file 'seriesxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../seriessetting/seriesxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'seriesxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SeriesXY_t {
    QByteArrayData data[12];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SeriesXY_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SeriesXY_t qt_meta_stringdata_SeriesXY = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SeriesXY"
QT_MOC_LITERAL(1, 9, 18), // "seriesColorChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "QXYSeries*"
QT_MOC_LITERAL(4, 40, 18), // "changePointVisible"
QT_MOC_LITERAL(5, 59, 24), // "changePointLabelsVisible"
QT_MOC_LITERAL(6, 84, 25), // "changePointLabelsClipping"
QT_MOC_LITERAL(7, 110, 11), // "changeColor"
QT_MOC_LITERAL(8, 122, 16), // "changeLabelColor"
QT_MOC_LITERAL(9, 139, 15), // "changeLabelFont"
QT_MOC_LITERAL(10, 155, 11), // "changeWidth"
QT_MOC_LITERAL(11, 167, 12) // "changeFormat"

    },
    "SeriesXY\0seriesColorChanged\0\0QXYSeries*\0"
    "changePointVisible\0changePointLabelsVisible\0"
    "changePointLabelsClipping\0changeColor\0"
    "changeLabelColor\0changeLabelFont\0"
    "changeWidth\0changeFormat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SeriesXY[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   62,    2, 0x08 /* Private */,
       5,    1,   65,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    1,   74,    2, 0x08 /* Private */,
      11,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void SeriesXY::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SeriesXY *_t = static_cast<SeriesXY *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seriesColorChanged((*reinterpret_cast< QXYSeries*(*)>(_a[1]))); break;
        case 1: _t->changePointVisible((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changePointLabelsVisible((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changePointLabelsClipping((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeColor(); break;
        case 5: _t->changeLabelColor(); break;
        case 6: _t->changeLabelFont(); break;
        case 7: _t->changeWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changeFormat((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SeriesXY::*_t)(QXYSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SeriesXY::seriesColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SeriesXY::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_SeriesXY.data,
      qt_meta_data_SeriesXY,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SeriesXY::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SeriesXY::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SeriesXY.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int SeriesXY::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SeriesXY::seriesColorChanged(QXYSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
