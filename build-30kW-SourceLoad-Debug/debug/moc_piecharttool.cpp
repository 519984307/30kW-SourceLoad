/****************************************************************************
** Meta object code from reading C++ file 'piecharttool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../charttool/piecharttool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'piecharttool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PieChartTool_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PieChartTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PieChartTool_t qt_meta_stringdata_PieChartTool = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PieChartTool"
QT_MOC_LITERAL(1, 13, 11), // "modeChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "seriesColorChanged"
QT_MOC_LITERAL(4, 45, 11) // "QPieSeries*"

    },
    "PieChartTool\0modeChanged\0\0seriesColorChanged\0"
    "QPieSeries*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PieChartTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       3,    3,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QColor, QMetaType::Int,    2,    2,    2,

       0        // eod
};

void PieChartTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PieChartTool *_t = static_cast<PieChartTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->seriesColorChanged((*reinterpret_cast< QPieSeries*(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPieSeries* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PieChartTool::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PieChartTool::modeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PieChartTool::*_t)(QPieSeries * , QColor , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PieChartTool::seriesColorChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject PieChartTool::staticMetaObject = {
    { &ChartTool::staticMetaObject, qt_meta_stringdata_PieChartTool.data,
      qt_meta_data_PieChartTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PieChartTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PieChartTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PieChartTool.stringdata0))
        return static_cast<void*>(this);
    return ChartTool::qt_metacast(_clname);
}

int PieChartTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ChartTool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PieChartTool::modeChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PieChartTool::seriesColorChanged(QPieSeries * _t1, QColor _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
