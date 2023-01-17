/****************************************************************************
** Meta object code from reading C++ file 'conicalgradientparamwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chartsetting/conicalgradientparamwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'conicalgradientparamwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConicalGradientParamWidget_t {
    QByteArrayData data[6];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConicalGradientParamWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConicalGradientParamWidget_t qt_meta_stringdata_ConicalGradientParamWidget = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ConicalGradientParamWidget"
QT_MOC_LITERAL(1, 27, 21), // "conicalGradientParams"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 12), // "ConicalParam"
QT_MOC_LITERAL(4, 63, 10), // "isRealTime"
QT_MOC_LITERAL(5, 74, 5) // "isBtn"

    },
    "ConicalGradientParamWidget\0"
    "conicalGradientParams\0\0ConicalParam\0"
    "isRealTime\0isBtn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConicalGradientParamWidget[] = {

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
       1,    3,   29,    2, 0x06 /* Public */,
       1,    2,   36,    2, 0x26 /* Public | MethodCloned */,
       1,    1,   41,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Bool,    2,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    4,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void ConicalGradientParamWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConicalGradientParamWidget *_t = static_cast<ConicalGradientParamWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->conicalGradientParams((*reinterpret_cast< ConicalParam(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->conicalGradientParams((*reinterpret_cast< ConicalParam(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->conicalGradientParams((*reinterpret_cast< ConicalParam(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ConicalGradientParamWidget::*_t)(ConicalParam , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConicalGradientParamWidget::conicalGradientParams)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ConicalGradientParamWidget::staticMetaObject = {
    { &GradientParamWidget::staticMetaObject, qt_meta_stringdata_ConicalGradientParamWidget.data,
      qt_meta_data_ConicalGradientParamWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConicalGradientParamWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConicalGradientParamWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConicalGradientParamWidget.stringdata0))
        return static_cast<void*>(this);
    return GradientParamWidget::qt_metacast(_clname);
}

int ConicalGradientParamWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GradientParamWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ConicalGradientParamWidget::conicalGradientParams(ConicalParam _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
