/****************************************************************************
** Meta object code from reading C++ file 'debit_types.h'
**
** Created: Wed May 2 22:27:18 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../debit_types.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debit_types.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_debit_types[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   12,   12,   12, 0x08,
      44,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_debit_types[] = {
    "debit_types\0\0refresh_table()\0"
    "text_changed()\0insert_debit_type()\0"
};

const QMetaObject debit_types::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_debit_types,
      qt_meta_data_debit_types, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &debit_types::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *debit_types::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *debit_types::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_debit_types))
        return static_cast<void*>(const_cast< debit_types*>(this));
    return QDialog::qt_metacast(_clname);
}

int debit_types::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: refresh_table(); break;
        case 1: text_changed(); break;
        case 2: insert_debit_type(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void debit_types::refresh_table()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
