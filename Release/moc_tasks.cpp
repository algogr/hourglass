/****************************************************************************
** Meta object code from reading C++ file 'tasks.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tasks.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tasks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_tasks[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,    6,    6,    6, 0x08,
      38,    6,    6,    6, 0x08,
      51,    6,    6,    6, 0x08,
      68,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_tasks[] = {
    "tasks\0\0refresh_tasks()\0set_customer()\0"
    "ok_pressed()\0cancel_pressed()\0"
    "stop_time_changed()\0"
};

void tasks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        tasks *_t = static_cast<tasks *>(_o);
        switch (_id) {
        case 0: _t->refresh_tasks(); break;
        case 1: _t->set_customer(); break;
        case 2: _t->ok_pressed(); break;
        case 3: _t->cancel_pressed(); break;
        case 4: _t->stop_time_changed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData tasks::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject tasks::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_tasks,
      qt_meta_data_tasks, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tasks::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tasks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tasks::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tasks))
        return static_cast<void*>(const_cast< tasks*>(this));
    return QDialog::qt_metacast(_clname);
}

int tasks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void tasks::refresh_tasks()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
