/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     198,   11,   11,   11, 0x08,
     215,   11,   11,   11, 0x08,
     234,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     261,   11,   11,   11, 0x08,
     277,  275,   11,   11, 0x08,
     299,  295,   11,   11, 0x08,
     320,  295,   11,   11, 0x08,
     353,  295,   11,   11, 0x08,
     385,   11,   11,   11, 0x08,
     402,   11,   11,   11, 0x08,
     413,   11,   11,   11, 0x08,
     429,   11,   11,   11, 0x08,
     446,   11,   11,   11, 0x08,
     467,  463,   11,   11, 0x08,
     491,  484,   11,   11, 0x08,
     509,  295,   11,   11, 0x08,
     537,  531,   11,   11, 0x08,
     560,  551,   11,   11, 0x08,
     583,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0refresh_customers()\0"
    "new_customer()\0customer_selection_changed()\0"
    "edit_customer()\0tracking_pressed()\0"
    "refresh_tasks()\0refresh_full_tasks()\0"
    "remove_invalid_chars()\0refresh_time()\0"
    "edit_task()\0edit_task_full()\0"
    "add_earlier_task()\0do_migration()\0"
    "invoicing()\0email_tasks()\0i\0"
    "change_graph(int)\0pos\0context_menu(QPoint)\0"
    "context_menu_daily_calls(QPoint)\0"
    "context_menu_full_calls(QPoint)\0"
    "invoice_review()\0projects()\0table_clicked()\0"
    "table2_clicked()\0delete_clicked()\0tab\0"
    "tab_changed(int)\0column\0sortbycolumn(int)\0"
    "dial_customer(QPoint)\0phone\0dial(QString)\0"
    "callerid\0incoming_call(QString)\0"
    "refresh_calls()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->refresh_customers(); break;
        case 1: _t->new_customer(); break;
        case 2: _t->customer_selection_changed(); break;
        case 3: _t->edit_customer(); break;
        case 4: _t->tracking_pressed(); break;
        case 5: _t->refresh_tasks(); break;
        case 6: _t->refresh_full_tasks(); break;
        case 7: _t->remove_invalid_chars(); break;
        case 8: _t->refresh_time(); break;
        case 9: _t->edit_task(); break;
        case 10: _t->edit_task_full(); break;
        case 11: _t->add_earlier_task(); break;
        case 12: _t->do_migration(); break;
        case 13: _t->invoicing(); break;
        case 14: _t->email_tasks(); break;
        case 15: _t->change_graph((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->context_menu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 17: _t->context_menu_daily_calls((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 18: _t->context_menu_full_calls((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 19: _t->invoice_review(); break;
        case 20: _t->projects(); break;
        case 21: _t->table_clicked(); break;
        case 22: _t->table2_clicked(); break;
        case 23: _t->delete_clicked(); break;
        case 24: _t->tab_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->sortbycolumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->dial_customer((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 27: _t->dial((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->incoming_call((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->refresh_calls(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
