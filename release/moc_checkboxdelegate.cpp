/****************************************************************************
** Meta object code from reading C++ file 'checkboxdelegate.h'
**
** Created: Wed May 2 22:27:24 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../checkboxdelegate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkboxdelegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CheckBoxDelegate[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   18,   17,   17, 0x05,
      54,   42,   17,   17, 0x05,
     105,   93,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     140,   42,   17,   17, 0x0a,
     171,   93,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CheckBoxDelegate[] = {
    "CheckBoxDelegate\0\0diff\0transmit_diff(int)\0"
    "state,index\0editor_changed_state(bool,QModelIndex)\0"
    "value,index\0editor_spin_value(int,QModelIndex)\0"
    "echk_clicked(bool,QModelIndex)\0"
    "espin_clicked(int,QModelIndex)\0"
};

const QMetaObject CheckBoxDelegate::staticMetaObject = {
    { &QItemDelegate::staticMetaObject, qt_meta_stringdata_CheckBoxDelegate,
      qt_meta_data_CheckBoxDelegate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CheckBoxDelegate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CheckBoxDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CheckBoxDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CheckBoxDelegate))
        return static_cast<void*>(const_cast< CheckBoxDelegate*>(this));
    return QItemDelegate::qt_metacast(_clname);
}

int CheckBoxDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: transmit_diff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: editor_changed_state((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: editor_spin_value((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 3: echk_clicked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: espin_clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CheckBoxDelegate::transmit_diff(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CheckBoxDelegate::editor_changed_state(bool _t1, const QModelIndex & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CheckBoxDelegate::editor_spin_value(int _t1, const QModelIndex & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
