/****************************************************************************
** Meta object code from reading C++ file 'email_tasks.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../email_tasks.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'email_tasks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Email_tasks[] = {

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
      13,   12,   12,   12, 0x08,
      28,   12,   12,   12, 0x08,
      45,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Email_tasks[] = {
    "Email_tasks\0\0date_changed()\0"
    "prepare_emails()\0cancel_pressed()\0"
};

void Email_tasks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Email_tasks *_t = static_cast<Email_tasks *>(_o);
        switch (_id) {
        case 0: _t->date_changed(); break;
        case 1: _t->prepare_emails(); break;
        case 2: _t->cancel_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Email_tasks::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Email_tasks::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Email_tasks,
      qt_meta_data_Email_tasks, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Email_tasks::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Email_tasks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Email_tasks::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Email_tasks))
        return static_cast<void*>(const_cast< Email_tasks*>(this));
    return QDialog::qt_metacast(_clname);
}

int Email_tasks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
