/****************************************************************************
** Meta object code from reading C++ file 'seriesscatter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../seriessetting/seriesscatter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'seriesscatter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SeriesScatter_t {
    QByteArrayData data[8];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SeriesScatter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SeriesScatter_t qt_meta_stringdata_SeriesScatter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SeriesScatter"
QT_MOC_LITERAL(1, 14, 18), // "seriesColorChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "QScatterSeries*"
QT_MOC_LITERAL(4, 50, 11), // "changeShape"
QT_MOC_LITERAL(5, 62, 10), // "changeSize"
QT_MOC_LITERAL(6, 73, 17), // "changeBorderColor"
QT_MOC_LITERAL(7, 91, 15) // "changeFillColor"

    },
    "SeriesScatter\0seriesColorChanged\0\0"
    "QScatterSeries*\0changeShape\0changeSize\0"
    "changeBorderColor\0changeFillColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SeriesScatter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SeriesScatter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SeriesScatter *_t = static_cast<SeriesScatter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->seriesColorChanged((*reinterpret_cast< QScatterSeries*(*)>(_a[1]))); break;
        case 1: _t->changeShape((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeSize((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->changeBorderColor(); break;
        case 4: _t->changeFillColor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QScatterSeries* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SeriesScatter::*_t)(QScatterSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SeriesScatter::seriesColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SeriesScatter::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_SeriesScatter.data,
      qt_meta_data_SeriesScatter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SeriesScatter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SeriesScatter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SeriesScatter.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int SeriesScatter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SeriesScatter::seriesColorChanged(QScatterSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
