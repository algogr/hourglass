/********************************************************************************
** Form generated from reading UI file 'tasks.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKS_H
#define UI_TASKS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_tasks
{
public:
    QComboBox *comboCustomer;
    QDateTimeEdit *dateTimeStart;
    QDateTimeEdit *dateTimeStop;
    QComboBox *comboPlace;
    QComboBox *comboProject;
    QTextEdit *textEdit;
    QPushButton *pushOK;
    QPushButton *pushCancel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineDebit;
    QLabel *label_6;

    void setupUi(QDialog *tasks)
    {
        if (tasks->objectName().isEmpty())
            tasks->setObjectName(QString::fromUtf8("tasks"));
        tasks->resize(379, 300);
        comboCustomer = new QComboBox(tasks);
        comboCustomer->setObjectName(QString::fromUtf8("comboCustomer"));
        comboCustomer->setGeometry(QRect(150, 10, 151, 24));
        dateTimeStart = new QDateTimeEdit(tasks);
        dateTimeStart->setObjectName(QString::fromUtf8("dateTimeStart"));
        dateTimeStart->setGeometry(QRect(150, 120, 111, 22));
        dateTimeStart->setCalendarPopup(true);
        dateTimeStop = new QDateTimeEdit(tasks);
        dateTimeStop->setObjectName(QString::fromUtf8("dateTimeStop"));
        dateTimeStop->setGeometry(QRect(150, 150, 111, 22));
        dateTimeStop->setCalendarPopup(true);
        comboPlace = new QComboBox(tasks);
        comboPlace->setObjectName(QString::fromUtf8("comboPlace"));
        comboPlace->setGeometry(QRect(150, 40, 151, 24));
        comboProject = new QComboBox(tasks);
        comboProject->setObjectName(QString::fromUtf8("comboProject"));
        comboProject->setGeometry(QRect(150, 70, 151, 24));
        textEdit = new QTextEdit(tasks);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 210, 251, 78));
        pushOK = new QPushButton(tasks);
        pushOK->setObjectName(QString::fromUtf8("pushOK"));
        pushOK->setGeometry(QRect(300, 210, 71, 27));
        pushCancel = new QPushButton(tasks);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(300, 250, 71, 27));
        label = new QLabel(tasks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 81, 21));
        label_2 = new QLabel(tasks);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 40, 81, 21));
        label_3 = new QLabel(tasks);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 70, 81, 21));
        label_4 = new QLabel(tasks);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 120, 81, 21));
        label_5 = new QLabel(tasks);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 150, 81, 21));
        lineDebit = new QLineEdit(tasks);
        lineDebit->setObjectName(QString::fromUtf8("lineDebit"));
        lineDebit->setGeometry(QRect(150, 180, 61, 20));
        label_6 = new QLabel(tasks);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 180, 81, 21));

        retranslateUi(tasks);

        QMetaObject::connectSlotsByName(tasks);
    } // setupUi

    void retranslateUi(QDialog *tasks)
    {
        tasks->setWindowTitle(QApplication::translate("tasks", "\316\225\317\201\316\263\316\261\317\203\316\257\316\265\317\202", 0, QApplication::UnicodeUTF8));
        dateTimeStart->setDisplayFormat(QApplication::translate("tasks", "d/M/yy h:mm AP", 0, QApplication::UnicodeUTF8));
        dateTimeStop->setDisplayFormat(QApplication::translate("tasks", "d/M/yy h:mm AP", 0, QApplication::UnicodeUTF8));
        pushOK->setText(QString());
        pushCancel->setText(QString());
        label->setText(QApplication::translate("tasks", "\316\240\316\265\316\273\316\254\317\204\316\267\317\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("tasks", "\316\244\317\214\317\200\316\277\317\202", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("tasks", "\316\210\317\201\316\263\316\277", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("tasks", "\316\210\316\275\316\261\317\201\316\276\316\267", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("tasks", "\316\233\316\256\316\276\316\267", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("tasks", "\316\247\317\201\316\255\317\211\317\203\316\267/\317\216\317\201\316\261", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class tasks: public Ui_tasks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKS_H
