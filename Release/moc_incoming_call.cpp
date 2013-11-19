/****************************************************************************
** Meta object code from reading C++ file 'incoming_call.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../incoming_call.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'incoming_call.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Incoming_Call[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      34,   14,   14,   14, 0x08,
      46,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Incoming_Call[] = {
    "Incoming_Call\0\0customer_changed()\0"
    "ok_pushed()\0dismiss_pushed()\0"
};

void Incoming_Call::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Incoming_Call *_t = static_cast<Incoming_Call *>(_o);
        switch (_id) {
        case 0: _t->customer_changed(); break;
        case 1: _t->ok_pushed(); break;
        case 2: _t->dismiss_pushed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Incoming_Call::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Incoming_Call::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Incoming_Call,
      qt_meta_data_Incoming_Call, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Incoming_Call::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Incoming_Call::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Incoming_Call::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Incoming_Call))
        return static_cast<void*>(const_cast< Incoming_Call*>(this));
    return QDialog::qt_metacast(_clname);
}

int Incoming_Call::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
