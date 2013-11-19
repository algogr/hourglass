/****************************************************************************
** Meta object code from reading C++ file 'invoicereview.h'
**
** Created: Wed May 2 22:27:34 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../invoicereview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'invoicereview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InvoiceReview[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      33,   14,   14,   14, 0x08,
      48,   14,   14,   14, 0x08,
      65,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_InvoiceReview[] = {
    "InvoiceReview\0\0invoice_changed()\0"
    "date_changed()\0delete_pressed()\0"
    "email_pressed()\0"
};

const QMetaObject InvoiceReview::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_InvoiceReview,
      qt_meta_data_InvoiceReview, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InvoiceReview::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InvoiceReview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InvoiceReview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InvoiceReview))
        return static_cast<void*>(const_cast< InvoiceReview*>(this));
    return QDialog::qt_metacast(_clname);
}

int InvoiceReview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: invoice_changed(); break;
        case 1: date_changed(); break;
        case 2: delete_pressed(); break;
        case 3: email_pressed(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
