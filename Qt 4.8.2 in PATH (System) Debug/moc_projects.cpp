/****************************************************************************
** Meta object code from reading C++ file 'projects.h'
**
** Created: Tue Jul 2 11:49:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projects.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projects.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Projects[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,    9,    9,    9, 0x08,
      44,    9,    9,    9, 0x08,
      53,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Projects[] = {
    "Projects\0\0data_changed()\0customer_changed()\0"
    "insert()\0cancel()\0"
};

void Projects::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Projects *_t = static_cast<Projects *>(_o);
        switch (_id) {
        case 0: _t->data_changed(); break;
        case 1: _t->customer_changed(); break;
        case 2: _t->insert(); break;
        case 3: _t->cancel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Projects::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Projects::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Projects,
      qt_meta_data_Projects, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Projects::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Projects::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Projects::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Projects))
        return static_cast<void*>(const_cast< Projects*>(this));
    return QDialog::qt_metacast(_clname);
}

int Projects::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Projects::data_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
