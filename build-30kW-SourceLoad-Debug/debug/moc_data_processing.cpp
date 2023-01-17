/****************************************************************************
** Meta object code from reading C++ file 'data_processing.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../core/data_processing.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'data_processing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResponseProcessor_t {
    QByteArrayData data[6];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResponseProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResponseProcessor_t qt_meta_stringdata_ResponseProcessor = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ResponseProcessor"
QT_MOC_LITERAL(1, 18, 10), // "fixedQuery"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "monitorQuery"
QT_MOC_LITERAL(4, 43, 11), // "MONITORROLE"
QT_MOC_LITERAL(5, 55, 13) // "terminalQuery"

    },
    "ResponseProcessor\0fixedQuery\0\0"
    "monitorQuery\0MONITORROLE\0terminalQuery"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResponseProcessor[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,
       3,    2,   37,    2, 0x06 /* Public */,
       3,    3,   42,    2, 0x06 /* Public */,
       5,    2,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArrayList,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,

       0        // eod
};

void ResponseProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResponseProcessor *_t = static_cast<ResponseProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fixedQuery((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 1: _t->monitorQuery((*reinterpret_cast< MONITORROLE(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->monitorQuery((*reinterpret_cast< MONITORROLE(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 3: _t->terminalQuery((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MONITORROLE >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MONITORROLE >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ResponseProcessor::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResponseProcessor::fixedQuery)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ResponseProcessor::*_t)(MONITORROLE , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResponseProcessor::monitorQuery)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ResponseProcessor::*_t)(MONITORROLE , const QByteArray & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResponseProcessor::monitorQuery)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ResponseProcessor::*_t)(const QByteArray & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResponseProcessor::terminalQuery)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ResponseProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ResponseProcessor.data,
      qt_meta_data_ResponseProcessor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ResponseProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResponseProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResponseProcessor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ResponseProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ResponseProcessor::fixedQuery(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ResponseProcessor::monitorQuery(MONITORROLE _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ResponseProcessor::monitorQuery(MONITORROLE _t1, const QByteArray & _t2, const QByteArray & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ResponseProcessor::terminalQuery(const QByteArray & _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
