/********************************************************************************
** Form generated from reading UI file 'customer.ui'
**
** Created: Tue Jul 2 11:47:41 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_H
#define UI_CUSTOMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_customer
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QTableView *tableView;
    QPushButton *pushCusInsert;
    QPushButton *pushLeave;
    QPushButton *pushAddDebit;
    QPushButton *pushEditDebit;
    QPushButton *pushDeleteDebit;
    QLineEdit *lineEmail1;
    QLineEdit *lineEmail2;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *checkActive;
    QLabel *label_5;
    QLineEdit *linePhone;

    void setupUi(QDialog *customer)
    {
        if (customer->objectName().isEmpty())
            customer->setObjectName(QString::fromUtf8("customer"));
        customer->resize(400, 217);
        lineEdit = new QLineEdit(customer);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 10, 113, 21));
        label = new QLabel(customer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 51, 20));
        line = new QFrame(customer);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 90, 401, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(customer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 51, 16));
        tableView = new QTableView(customer);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 120, 251, 91));
        pushCusInsert = new QPushButton(customer);
        pushCusInsert->setObjectName(QString::fromUtf8("pushCusInsert"));
        pushCusInsert->setGeometry(QRect(210, 10, 61, 31));
        pushLeave = new QPushButton(customer);
        pushLeave->setObjectName(QString::fromUtf8("pushLeave"));
        pushLeave->setGeometry(QRect(280, 10, 61, 31));
        pushAddDebit = new QPushButton(customer);
        pushAddDebit->setObjectName(QString::fromUtf8("pushAddDebit"));
        pushAddDebit->setGeometry(QRect(270, 120, 41, 41));
        pushEditDebit = new QPushButton(customer);
        pushEditDebit->setObjectName(QString::fromUtf8("pushEditDebit"));
        pushEditDebit->setGeometry(QRect(320, 120, 41, 41));
        pushDeleteDebit = new QPushButton(customer);
        pushDeleteDebit->setObjectName(QString::fromUtf8("pushDeleteDebit"));
        pushDeleteDebit->setGeometry(QRect(300, 170, 41, 41));
        lineEmail1 = new QLineEdit(customer);
        lineEmail1->setObjectName(QString::fromUtf8("lineEmail1"));
        lineEmail1->setGeometry(QRect(70, 40, 113, 20));
        lineEmail2 = new QLineEdit(customer);
        lineEmail2->setObjectName(QString::fromUtf8("lineEmail2"));
        lineEmail2->setGeometry(QRect(70, 70, 113, 20));
        label_3 = new QLabel(customer);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 51, 20));
        label_4 = new QLabel(customer);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 51, 20));
        checkActive = new QCheckBox(customer);
        checkActive->setObjectName(QString::fromUtf8("checkActive"));
        checkActive->setGeometry(QRect(270, 70, 70, 21));
        checkActive->setChecked(true);
        label_5 = new QLabel(customer);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 50, 51, 20));
        linePhone = new QLineEdit(customer);
        linePhone->setObjectName(QString::fromUtf8("linePhone"));
        linePhone->setGeometry(QRect(270, 50, 113, 20));

        retranslateUi(customer);

        QMetaObject::connectSlotsByName(customer);
    } // setupUi

    void retranslateUi(QDialog *customer)
    {
        customer->setWindowTitle(QApplication::translate("customer", "\316\240\316\265\316\273\316\254\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("customer", "\316\225\317\200\317\211\316\275\317\205\316\274\316\257\316\261", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("customer", "\316\247\317\201\316\265\317\216\317\203\316\265\316\271\317\202", 0, QApplication::UnicodeUTF8));
        pushCusInsert->setText(QString());
        pushLeave->setText(QString());
        pushAddDebit->setText(QString());
        pushEditDebit->setText(QString());
        pushDeleteDebit->setText(QString());
        label_3->setText(QApplication::translate("customer", "Email-1", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("customer", "Email-2", 0, QApplication::UnicodeUTF8));
        checkActive->setText(QApplication::translate("customer", "\316\225\316\275\316\265\317\201\316\263\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("customer", "\316\244\316\267\316\273\316\255\317\206\317\211\316\275\316\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class customer: public Ui_customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_H
