/****************************************************************************
** Meta object code from reading C++ file 'play.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../play.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'play.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Play_t {
    QByteArrayData data[7];
    char stringdata[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Play_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Play_t qt_meta_stringdata_Play = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Play"
QT_MOC_LITERAL(1, 5, 10), // "boxsignalx"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 1), // "i"
QT_MOC_LITERAL(4, 19, 10), // "boxsignaly"
QT_MOC_LITERAL(5, 30, 5), // "check"
QT_MOC_LITERAL(6, 36, 4) // "play"

    },
    "Play\0boxsignalx\0\0i\0boxsignaly\0check\0"
    "play"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Play[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Play::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Play *_t = static_cast<Play *>(_o);
        switch (_id) {
        case 0: { int _r = _t->boxsignalx((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->boxsignaly((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->check(); break;
        case 3: _t->play(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (Play::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Play::boxsignalx)) {
                *result = 0;
            }
        }
        {
            typedef int (Play::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Play::boxsignaly)) {
                *result = 1;
            }
        }
        {
            typedef void (Play::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Play::check)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Play::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Play.data,
      qt_meta_data_Play,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Play::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Play::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Play.stringdata))
        return static_cast<void*>(const_cast< Play*>(this));
    return QObject::qt_metacast(_clname);
}

int Play::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
int Play::boxsignalx(int _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int Play::boxsignaly(int _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
void Play::check()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
