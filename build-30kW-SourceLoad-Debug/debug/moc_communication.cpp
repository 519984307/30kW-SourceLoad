/****************************************************************************
** Meta object code from reading C++ file 'communication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../communication/communication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Communication_t {
    QByteArrayData data[32];
    char stringdata0[388];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Communication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Communication_t qt_meta_stringdata_Communication = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Communication"
QT_MOC_LITERAL(1, 14, 14), // "getMonitorRole"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "MONITORROLE"
QT_MOC_LITERAL(4, 42, 14), // "setMonitorRole"
QT_MOC_LITERAL(5, 57, 14), // "fixedQueryData"
QT_MOC_LITERAL(6, 72, 16), // "monitorQueryData"
QT_MOC_LITERAL(7, 89, 9), // "errorCode"
QT_MOC_LITERAL(8, 99, 11), // "TIMEOUTCODE"
QT_MOC_LITERAL(9, 111, 8), // "USBERROR"
QT_MOC_LITERAL(10, 120, 8), // "TCPERROR"
QT_MOC_LITERAL(11, 129, 14), // "selectedPeriod"
QT_MOC_LITERAL(12, 144, 10), // "logEnabled"
QT_MOC_LITERAL(13, 155, 13), // "logFileFormat"
QT_MOC_LITERAL(14, 169, 10), // "FILEFORMAT"
QT_MOC_LITERAL(15, 180, 13), // "currentDevice"
QT_MOC_LITERAL(16, 194, 10), // "QIODevice*"
QT_MOC_LITERAL(17, 205, 18), // "getTerminalCommand"
QT_MOC_LITERAL(18, 224, 17), // "terminalQueryData"
QT_MOC_LITERAL(19, 242, 6), // "record"
QT_MOC_LITERAL(20, 249, 12), // "monitorQuery"
QT_MOC_LITERAL(21, 262, 13), // "terminalQuery"
QT_MOC_LITERAL(22, 276, 8), // "usbError"
QT_MOC_LITERAL(23, 285, 8), // "usbCycle"
QT_MOC_LITERAL(24, 294, 12), // "usbConfigure"
QT_MOC_LITERAL(25, 307, 10), // "usbConnect"
QT_MOC_LITERAL(26, 318, 13), // "usbDisconnect"
QT_MOC_LITERAL(27, 332, 8), // "tcpError"
QT_MOC_LITERAL(28, 341, 8), // "tcpCycle"
QT_MOC_LITERAL(29, 350, 10), // "tcpConnect"
QT_MOC_LITERAL(30, 361, 13), // "tcpDisconnect"
QT_MOC_LITERAL(31, 375, 12) // "tcpConfigure"

    },
    "Communication\0getMonitorRole\0\0MONITORROLE\0"
    "setMonitorRole\0fixedQueryData\0"
    "monitorQueryData\0errorCode\0TIMEOUTCODE\0"
    "USBERROR\0TCPERROR\0selectedPeriod\0"
    "logEnabled\0logFileFormat\0FILEFORMAT\0"
    "currentDevice\0QIODevice*\0getTerminalCommand\0"
    "terminalQueryData\0record\0monitorQuery\0"
    "terminalQuery\0usbError\0usbCycle\0"
    "usbConfigure\0usbConnect\0usbDisconnect\0"
    "tcpError\0tcpCycle\0tcpConnect\0tcpDisconnect\0"
    "tcpConfigure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Communication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  169,    2, 0x06 /* Public */,
       4,    2,  174,    2, 0x06 /* Public */,
       5,    1,  179,    2, 0x06 /* Public */,
       6,    2,  182,    2, 0x06 /* Public */,
       7,    1,  187,    2, 0x06 /* Public */,
       7,    1,  190,    2, 0x06 /* Public */,
       7,    1,  193,    2, 0x06 /* Public */,
      11,    4,  196,    2, 0x06 /* Public */,
      11,    3,  205,    2, 0x26 /* Public | MethodCloned */,
      11,    2,  212,    2, 0x26 /* Public | MethodCloned */,
      11,    1,  217,    2, 0x26 /* Public | MethodCloned */,
      12,    1,  220,    2, 0x06 /* Public */,
      13,    1,  223,    2, 0x06 /* Public */,
      15,    1,  226,    2, 0x06 /* Public */,
      17,    1,  229,    2, 0x06 /* Public */,
      18,    1,  232,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  235,    2, 0x08 /* Private */,
      19,    3,  238,    2, 0x08 /* Private */,
      19,    2,  245,    2, 0x08 /* Private */,
      20,    2,  250,    2, 0x08 /* Private */,
      21,    1,  255,    2, 0x08 /* Private */,
      22,    1,  258,    2, 0x08 /* Private */,
      23,    0,  261,    2, 0x08 /* Private */,
      24,    0,  262,    2, 0x08 /* Private */,
      25,    0,  263,    2, 0x08 /* Private */,
      26,    0,  264,    2, 0x08 /* Private */,
      27,    1,  265,    2, 0x08 /* Private */,
      28,    0,  268,    2, 0x08 /* Private */,
      29,    0,  269,    2, 0x08 /* Private */,
      30,    0,  270,    2, 0x08 /* Private */,
      31,    0,  271,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, QMetaType::QByteArrayList,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    2,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArrayList,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Communication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Communication *_t = static_cast<Communication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getMonitorRole((*reinterpret_cast< MONITORROLE(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 1: _t->setMonitorRole((*reinterpret_cast< MONITORROLE(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 2: _t->fixedQueryData((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 3: _t->monitorQueryData((*reinterpret_cast< MONITORROLE(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->errorCode((*reinterpret_cast< TIMEOUTCODE(*)>(_a[1]))); break;
        case 5: _t->errorCode((*reinterpret_cast< USBERROR(*)>(_a[1]))); break;
        case 6: _t->errorCode((*reinterpret_cast< TCPERROR(*)>(_a[1]))); break;
        case 7: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 8: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 9: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 10: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 11: _t->logEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->logFileFormat((*reinterpret_cast< FILEFORMAT(*)>(_a[1]))); break;
        case 13: _t->currentDevice((*reinterpret_cast< QIODevice*(*)>(_a[1]))); break;
        case 14: _t->getTerminalCommand((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 15: _t->terminalQueryData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 16: _t->record((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 17: _t->record((*reinterpret_cast< MONITORROLE(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 18: _t->record((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 19: _t->monitorQuery((*reinterpret_cast< MONITORROLE(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 20: _t->terminalQuery((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 21: _t->usbError((*reinterpret_cast< USBERROR(*)>(_a[1]))); break;
        case 22: _t->usbCycle(); break;
        case 23: _t->usbConfigure(); break;
        case 24: _t->usbConnect(); break;
        case 25: _t->usbDisconnect(); break;
        case 26: _t->tcpError((*reinterpret_cast< TCPERROR(*)>(_a[1]))); break;
        case 27: _t->tcpCycle(); break;
        case 28: _t->tcpConnect(); break;
        case 29: _t->tcpDisconnect(); break;
        case 30: _t->tcpConfigure(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MONITORROLE >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MONITORROLE >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MONITORROLE >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TIMEOUTCODE >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< USBERROR >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TCPERROR >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FILEFORMAT >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MONITORROLE >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MONITORROLE >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< USBERROR >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TCPERROR >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Communication::*_t)(MONITORROLE , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::getMonitorRole)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(MONITORROLE , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::setMonitorRole)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::fixedQueryData)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(MONITORROLE , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::monitorQueryData)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(TIMEOUTCODE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::errorCode)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(USBERROR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::errorCode)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(TCPERROR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::errorCode)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(quint32 , quint32 , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::selectedPeriod)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::logEnabled)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(FILEFORMAT );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::logFileFormat)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QIODevice * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::currentDevice)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::getTerminalCommand)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::terminalQueryData)) {
                *result = 15;
                return;
            }
        }
    }
}

const QMetaObject Communication::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Communication.data,
      qt_meta_data_Communication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Communication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Communication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Communication.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Communication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void Communication::getMonitorRole(MONITORROLE _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Communication::setMonitorRole(MONITORROLE _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Communication::fixedQueryData(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Communication::monitorQueryData(MONITORROLE _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Communication::errorCode(TIMEOUTCODE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Communication::errorCode(USBERROR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Communication::errorCode(TCPERROR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Communication::selectedPeriod(quint32 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 11
void Communication::logEnabled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Communication::logFileFormat(FILEFORMAT _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Communication::currentDevice(QIODevice * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Communication::getTerminalCommand(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Communication::terminalQueryData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
