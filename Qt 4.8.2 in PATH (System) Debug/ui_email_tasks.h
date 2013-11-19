/********************************************************************************
** Form generated from reading UI file 'email_tasks.ui'
**
** Created: Tue Jul 2 11:47:41 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAIL_TASKS_H
#define UI_EMAIL_TASKS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Email_tasks
{
public:
    QDateEdit *dateEditfrom;
    QDateEdit *dateEditto;
    QLabel *label;
    QLabel *label_2;
    QTableView *tableView;
    QPushButton *pushSend;
    QPushButton *pushCancel;

    void setupUi(QDialog *Email_tasks)
    {
        if (Email_tasks->objectName().isEmpty())
            Email_tasks->setObjectName(QString::fromUtf8("Email_tasks"));
        Email_tasks->resize(436, 341);
        dateEditfrom = new QDateEdit(Email_tasks);
        dateEditfrom->setObjectName(QString::fromUtf8("dateEditfrom"));
        dateEditfrom->setGeometry(QRect(210, 10, 110, 22));
        dateEditfrom->setCalendarPopup(true);
        dateEditto = new QDateEdit(Email_tasks);
        dateEditto->setObjectName(QString::fromUtf8("dateEditto"));
        dateEditto->setGeometry(QRect(210, 40, 110, 22));
        dateEditto->setCalendarPopup(true);
        label = new QLabel(Email_tasks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 101, 20));
        label_2 = new QLabel(Email_tasks);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 40, 101, 20));
        tableView = new QTableView(Email_tasks);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 81, 411, 211));
        pushSend = new QPushButton(Email_tasks);
        pushSend->setObjectName(QString::fromUtf8("pushSend"));
        pushSend->setGeometry(QRect(114, 300, 51, 31));
        pushCancel = new QPushButton(Email_tasks);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(250, 300, 51, 31));

        retranslateUi(Email_tasks);

        QMetaObject::connectSlotsByName(Email_tasks);
    } // setupUi

    void retranslateUi(QDialog *Email_tasks)
    {
        Email_tasks->setWindowTitle(QApplication::translate("Email_tasks", "Email \316\225\317\201\316\263\316\261\317\203\316\271\317\216\316\275", 0, QApplication::UnicodeUTF8));
        dateEditfrom->setDisplayFormat(QApplication::translate("Email_tasks", "d/M/yy", 0, QApplication::UnicodeUTF8));
        dateEditto->setDisplayFormat(QApplication::translate("Email_tasks", "d/M/yy", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Email_tasks", "\316\221\317\200\317\214 \316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Email_tasks", "\316\225\317\211\317\202 \316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261", 0, QApplication::UnicodeUTF8));
        pushSend->setText(QString());
        pushCancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Email_tasks: public Ui_Email_tasks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAIL_TASKS_H
