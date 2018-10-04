/****************************************************************************
** Meta object code from reading C++ file 'qtdice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/headers/qtdice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtdice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtDice_t {
    QByteArrayData data[14];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtDice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtDice_t qt_meta_stringdata_QtDice = {
    {
QT_MOC_LITERAL(0, 0, 6), // "QtDice"
QT_MOC_LITERAL(1, 7, 18), // "qmovieFrameChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "QMovie*"
QT_MOC_LITERAL(4, 35, 5), // "movie"
QT_MOC_LITERAL(5, 41, 26), // "isNumberOfRollsIncremented"
QT_MOC_LITERAL(6, 68, 6), // "answer"
QT_MOC_LITERAL(7, 75, 6), // "reload"
QT_MOC_LITERAL(8, 82, 3), // "num"
QT_MOC_LITERAL(9, 86, 11), // "resetQtDice"
QT_MOC_LITERAL(10, 98, 14), // "disableWidgets"
QT_MOC_LITERAL(11, 113, 13), // "enableWidgets"
QT_MOC_LITERAL(12, 127, 19), // "stopLastQMovieFrame"
QT_MOC_LITERAL(13, 147, 19) // "QtDiceConfiguration"

    },
    "QtDice\0qmovieFrameChanged\0\0QMovie*\0"
    "movie\0isNumberOfRollsIncremented\0"
    "answer\0reload\0num\0resetQtDice\0"
    "disableWidgets\0enableWidgets\0"
    "stopLastQMovieFrame\0QtDiceConfiguration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtDice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   65,    2, 0x08 /* Private */,
       7,    1,   66,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    1,   72,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void QtDice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtDice *_t = static_cast<QtDice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->qmovieFrameChanged((*reinterpret_cast< QMovie*(*)>(_a[1]))); break;
        case 1: { bool _r = _t->isNumberOfRollsIncremented((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->reload(); break;
        case 3: _t->reload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->resetQtDice(); break;
        case 5: _t->disableWidgets(); break;
        case 6: _t->enableWidgets(); break;
        case 7: _t->stopLastQMovieFrame((*reinterpret_cast< QMovie*(*)>(_a[1]))); break;
        case 8: _t->QtDiceConfiguration(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMovie* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMovie* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtDice::*)(QMovie * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDice::qmovieFrameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = bool (QtDice::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDice::isNumberOfRollsIncremented)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtDice::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_QtDice.data,
    qt_meta_data_QtDice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtDice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtDice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtDice.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtDice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QtDice::qmovieFrameChanged(QMovie * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
bool QtDice::isNumberOfRollsIncremented(bool _t1)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
