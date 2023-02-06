/****************************************************************************
** Meta object code from reading C++ file 'scatterassociatetable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chartview/scatterassociatetable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scatterassociatetable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScatterAssociateTable_t {
    QByteArrayData data[7];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScatterAssociateTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScatterAssociateTable_t qt_meta_stringdata_ScatterAssociateTable = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ScatterAssociateTable"
QT_MOC_LITERAL(1, 22, 19), // "associateCompeleted"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 12), // "tableChanged"
QT_MOC_LITERAL(4, 56, 18), // "seriesColorChanged"
QT_MOC_LITERAL(5, 75, 15), // "QScatterSeries*"
QT_MOC_LITERAL(6, 91, 13) // "seriesRemoved"

    },
    "ScatterAssociateTable\0associateCompeleted\0"
    "\0tableChanged\0seriesColorChanged\0"
    "QScatterSeries*\0seriesRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScatterAssociateTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,
       6,    1,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void ScatterAssociateTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScatterAssociateTable *_t = static_cast<ScatterAssociateTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->associateCompeleted(); break;
        case 1: _t->tableChanged(); break;
        case 2: _t->seriesColorChanged((*reinterpret_cast< QScatterSeries*(*)>(_a[1]))); break;
        case 3: _t->seriesRemoved((*reinterpret_cast< QScatterSeries*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QScatterSeries* >(); break;
            }
            break;
        case 3:
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
            typedef void (ScatterAssociateTable::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScatterAssociateTable::associateCompeleted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ScatterAssociateTable::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScatterAssociateTable::tableChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ScatterAssociateTable::*_t)(QScatterSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScatterAssociateTable::seriesColorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ScatterAssociateTable::*_t)(QScatterSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScatterAssociateTable::seriesRemoved)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ScatterAssociateTable::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScatterAssociateTable.data,
      qt_meta_data_ScatterAssociateTable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScatterAssociateTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScatterAssociateTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScatterAssociateTable.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ScatterAssociateTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ScatterAssociateTable::associateCompeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ScatterAssociateTable::tableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ScatterAssociateTable::seriesColorChanged(QScatterSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ScatterAssociateTable::seriesRemoved(QScatterSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
