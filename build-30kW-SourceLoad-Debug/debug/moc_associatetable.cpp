/****************************************************************************
** Meta object code from reading C++ file 'associatetable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chartview/associatetable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'associatetable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AssociateTable_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AssociateTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AssociateTable_t qt_meta_stringdata_AssociateTable = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AssociateTable"
QT_MOC_LITERAL(1, 15, 19), // "associateCompeleted"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 12), // "tableChanged"
QT_MOC_LITERAL(4, 49, 18), // "seriesColorChanged"
QT_MOC_LITERAL(5, 68, 12), // "QLineSeries*"
QT_MOC_LITERAL(6, 81, 15), // "QScatterSeries*"
QT_MOC_LITERAL(7, 97, 13) // "seriesRemoved"

    },
    "AssociateTable\0associateCompeleted\0\0"
    "tableChanged\0seriesColorChanged\0"
    "QLineSeries*\0QScatterSeries*\0seriesRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AssociateTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,
       4,    1,   49,    2, 0x06 /* Public */,
       7,    1,   52,    2, 0x06 /* Public */,
       7,    1,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void AssociateTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AssociateTable *_t = static_cast<AssociateTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->associateCompeleted(); break;
        case 1: _t->tableChanged(); break;
        case 2: _t->seriesColorChanged((*reinterpret_cast< QLineSeries*(*)>(_a[1]))); break;
        case 3: _t->seriesColorChanged((*reinterpret_cast< QScatterSeries*(*)>(_a[1]))); break;
        case 4: _t->seriesRemoved((*reinterpret_cast< QLineSeries*(*)>(_a[1]))); break;
        case 5: _t->seriesRemoved((*reinterpret_cast< QScatterSeries*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineSeries* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QScatterSeries* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineSeries* >(); break;
            }
            break;
        case 5:
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
            typedef void (AssociateTable::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AssociateTable::associateCompeleted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AssociateTable::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AssociateTable::tableChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AssociateTable::*_t)(QLineSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AssociateTable::seriesColorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AssociateTable::*_t)(QScatterSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AssociateTable::seriesColorChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AssociateTable::*_t)(QLineSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AssociateTable::seriesRemoved)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (AssociateTable::*_t)(QScatterSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AssociateTable::seriesRemoved)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject AssociateTable::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AssociateTable.data,
      qt_meta_data_AssociateTable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AssociateTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AssociateTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AssociateTable.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AssociateTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AssociateTable::associateCompeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AssociateTable::tableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AssociateTable::seriesColorChanged(QLineSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AssociateTable::seriesColorChanged(QScatterSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AssociateTable::seriesRemoved(QLineSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AssociateTable::seriesRemoved(QScatterSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
