/****************************************************************************
** Meta object code from reading C++ file 'editform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../editform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditForm_t {
    QByteArrayData data[8];
    char stringdata[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditForm_t qt_meta_stringdata_EditForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "EditForm"
QT_MOC_LITERAL(1, 9, 4), // "hero"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 4), // "wall"
QT_MOC_LITERAL(4, 20, 3), // "box"
QT_MOC_LITERAL(5, 24, 4), // "exit"
QT_MOC_LITERAL(6, 29, 7), // "restore"
QT_MOC_LITERAL(7, 37, 4) // "save"

    },
    "EditForm\0hero\0\0wall\0box\0exit\0restore\0"
    "save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditForm *_t = static_cast<EditForm *>(_o);
        switch (_id) {
        case 0: _t->hero(); break;
        case 1: _t->wall(); break;
        case 2: _t->box(); break;
        case 3: _t->exit(); break;
        case 4: _t->restore(); break;
        case 5: _t->save(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EditForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EditForm.data,
      qt_meta_data_EditForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditForm.stringdata))
        return static_cast<void*>(const_cast< EditForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int EditForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
