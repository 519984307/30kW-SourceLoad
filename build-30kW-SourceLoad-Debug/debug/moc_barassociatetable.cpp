/****************************************************************************
** Meta object code from reading C++ file 'barassociatetable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chartview/barassociatetable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'barassociatetable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BarAssociateTable_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BarAssociateTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BarAssociateTable_t qt_meta_stringdata_BarAssociateTable = {
    {
QT_MOC_LITERAL(0, 0, 17), // "BarAssociateTable"
QT_MOC_LITERAL(1, 18, 19), // "associateCompeleted"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "seriesColorChanged"
QT_MOC_LITERAL(4, 58, 11), // "QBarSeries*"
QT_MOC_LITERAL(5, 70, 11), // "modeChanged"
QT_MOC_LITERAL(6, 82, 12) // "tableChanged"

    },
    "BarAssociateTable\0associateCompeleted\0"
    "\0seriesColorChanged\0QBarSeries*\0"
    "modeChanged\0tableChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BarAssociateTable[] = {

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
       3,    3,   35,    2, 0x06 /* Public */,
       5,    2,   42,    2, 0x06 /* Public */,
       6,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QColor, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

       0        // eod
};

void BarAssociateTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BarAssociateTable *_t = static_cast<BarAssociateTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->associateCompeleted(); break;
        case 1: _t->seriesColorChanged((*reinterpret_cast< QBarSeries*(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->modeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->tableChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBarSeries* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BarAssociateTable::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarAssociateTable::associateCompeleted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BarAssociateTable::*_t)(QBarSeries * , QColor , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarAssociateTable::seriesColorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BarAssociateTable::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarAssociateTable::modeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BarAssociateTable::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarAssociateTable::tableChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject BarAssociateTable::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BarAssociateTable.data,
      qt_meta_data_BarAssociateTable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BarAssociateTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BarAssociateTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BarAssociateTable.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BarAssociateTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void BarAssociateTable::associateCompeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BarAssociateTable::seriesColorChanged(QBarSeries * _t1, QColor _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BarAssociateTable::modeChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BarAssociateTable::tableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
