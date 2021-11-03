/****************************************************************************
** Meta object code from reading C++ file 'PgrExport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../PgrExport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PgrExport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PgrExport_t {
    QByteArrayData data[9];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PgrExport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PgrExport_t qt_meta_stringdata_PgrExport = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PgrExport"
QT_MOC_LITERAL(1, 10, 7), // "process"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 1), // "v"
QT_MOC_LITERAL(4, 21, 6), // "handle"
QT_MOC_LITERAL(5, 28, 2), // "nm"
QT_MOC_LITERAL(6, 31, 9), // "btnSelect"
QT_MOC_LITERAL(7, 41, 9), // "onProcess"
QT_MOC_LITERAL(8, 51, 8) // "onHandle"

    },
    "PgrExport\0process\0\0v\0handle\0nm\0btnSelect\0"
    "onProcess\0onHandle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PgrExport[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
       8,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void PgrExport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PgrExport *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->process((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->handle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->btnSelect(); break;
        case 3: _t->onProcess((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onHandle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PgrExport::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PgrExport::process)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PgrExport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PgrExport::handle)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PgrExport::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_PgrExport.data,
    qt_meta_data_PgrExport,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PgrExport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PgrExport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PgrExport.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PgrExport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PgrExport::process(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PgrExport::handle(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
