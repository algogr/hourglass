/****************************************************************************
** Meta object code from reading C++ file 'customer.h'
**
** Created: Wed May 2 22:27:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../customer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_customer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,    9,    9,    9, 0x08,
      50,    9,    9,    9, 0x08,
      68,    9,    9,    9, 0x08,
      88,    9,    9,    9, 0x08,
     102,    9,    9,    9, 0x08,
     118,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_customer[] = {
    "customer\0\0main_customers_refresh()\0"
    "text_changed()\0insert_customer()\0"
    "insert_debit_type()\0refresh_sql()\0"
    "check_clicked()\0cancel_clicked()\0"
};

const QMetaObject customer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_customer,
      qt_meta_data_customer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &customer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *customer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *customer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_customer))
        return static_cast<void*>(const_cast< customer*>(this));
    return QDialog::qt_metacast(_clname);
}

int customer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: main_customers_refresh(); break;
        case 1: text_changed(); break;
        case 2: insert_customer(); break;
        case 3: insert_debit_type(); break;
        case 4: refresh_sql(); break;
        case 5: check_clicked(); break;
        case 6: cancel_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void customer::main_customers_refresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
