/****************************************************************************
** Meta object code from reading C++ file 'lineseriessetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../seriessetting/lineseriessetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lineseriessetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LineSeriesSetting_t {
    QByteArrayData data[6];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineSeriesSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineSeriesSetting_t qt_meta_stringdata_LineSeriesSetting = {
    {
QT_MOC_LITERAL(0, 0, 17), // "LineSeriesSetting"
QT_MOC_LITERAL(1, 18, 19), // "associateCompeleted"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "seriesColorChanged"
QT_MOC_LITERAL(4, 58, 12), // "QLineSeries*"
QT_MOC_LITERAL(5, 71, 13) // "seriesRemoved"

    },
    "LineSeriesSetting\0associateCompeleted\0"
    "\0seriesColorChanged\0QLineSeries*\0"
    "seriesRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineSeriesSetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       5,    1,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void LineSeriesSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineSeriesSetting *_t = static_cast<LineSeriesSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->associateCompeleted(); break;
        case 1: _t->seriesColorChanged((*reinterpret_cast< QLineSeries*(*)>(_a[1]))); break;
        case 2: _t->seriesRemoved((*reinterpret_cast< QLineSeries*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineSeries* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineSeries* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LineSeriesSetting::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineSeriesSetting::associateCompeleted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LineSeriesSetting::*_t)(QLineSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineSeriesSetting::seriesColorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LineSeriesSetting::*_t)(QLineSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineSeriesSetting::seriesRemoved)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject LineSeriesSetting::staticMetaObject = {
    { &QVBoxLayout::staticMetaObject, qt_meta_stringdata_LineSeriesSetting.data,
      qt_meta_data_LineSeriesSetting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LineSeriesSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineSeriesSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LineSeriesSetting.stringdata0))
        return static_cast<void*>(this);
    return QVBoxLayout::qt_metacast(_clname);
}

int LineSeriesSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVBoxLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LineSeriesSetting::associateCompeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LineSeriesSetting::seriesColorChanged(QLineSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LineSeriesSetting::seriesRemoved(QLineSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
