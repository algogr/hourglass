/****************************************************************************
** Meta object code from reading C++ file 'hourglass.h'
**
** Created: Wed Oct 5 14:02:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hourglass.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hourglass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_hourglass[] = {

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
      18,   11,   10,   10, 0x08,
      67,   10,   10,   10, 0x08,
      86,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_hourglass[] = {
    "hourglass\0\0reason\0"
    "iconActivated(QSystemTrayIcon::ActivationReason)\0"
    "setDialogVisible()\0button_clicked()\0"
};

const QMetaObject hourglass::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_hourglass,
      qt_meta_data_hourglass, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &hourglass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *hourglass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *hourglass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_hourglass))
        return static_cast<void*>(const_cast< hourglass*>(this));
    return QWidget::qt_metacast(_clname);
}

int hourglass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 1: setDialogVisible(); break;
        case 2: button_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE