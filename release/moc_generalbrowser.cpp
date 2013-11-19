/****************************************************************************
** Meta object code from reading C++ file 'generalbrowser.h'
**
** Created: Wed May 2 22:27:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../generalbrowser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generalbrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeneralBrowser[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      28,   22,   15,   15, 0x0a,
      46,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeneralBrowser[] = {
    "GeneralBrowser\0\0add()\0index\0"
    "edit(QModelIndex)\0model_reset()\0"
};

const QMetaObject GeneralBrowser::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GeneralBrowser,
      qt_meta_data_GeneralBrowser, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneralBrowser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneralBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneralBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralBrowser))
        return static_cast<void*>(const_cast< GeneralBrowser*>(this));
    return QDialog::qt_metacast(_clname);
}

int GeneralBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: add(); break;
        case 1: edit((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: model_reset(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
