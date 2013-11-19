/****************************************************************************
** Meta object code from reading C++ file 'invoice_customer.h'
**
** Created: Tue Jul 2 11:48:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../invoice_customer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'invoice_customer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_invoice_customer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      34,   17,   17,   17, 0x08,
      46,   17,   17,   17, 0x08,
      68,   56,   17,   17, 0x08,
     113,  101,   17,   17, 0x08,
     150,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_invoice_customer[] = {
    "invoice_customer\0\0check_clicked()\0"
    "date_from()\0date_to()\0state,index\0"
    "editor_changed(bool,QModelIndex)\0"
    "value,index\0editor_spin_changed(int,QModelIndex)\0"
    "create_invoice()\0"
};

void invoice_customer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        invoice_customer *_t = static_cast<invoice_customer *>(_o);
        switch (_id) {
        case 0: _t->check_clicked(); break;
        case 1: _t->date_from(); break;
        case 2: _t->date_to(); break;
        case 3: _t->editor_changed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->editor_spin_changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 5: _t->create_invoice(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData invoice_customer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject invoice_customer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_invoice_customer,
      qt_meta_data_invoice_customer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &invoice_customer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *invoice_customer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *invoice_customer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_invoice_customer))
        return static_cast<void*>(const_cast< invoice_customer*>(this));
    return QDialog::qt_metacast(_clname);
}

int invoice_customer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
