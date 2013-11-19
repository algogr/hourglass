/********************************************************************************
** Form generated from reading UI file 'debit_types.ui'
**
** Created: Wed May 2 22:26:27 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBIT_TYPES_H
#define UI_DEBIT_TYPES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_debit_types
{
public:
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushInsert;
    QPushButton *pushCancel;

    void setupUi(QDialog *debit_types)
    {
        if (debit_types->objectName().isEmpty())
            debit_types->setObjectName(QString::fromUtf8("debit_types"));
        debit_types->resize(216, 143);
        comboBox = new QComboBox(debit_types);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 10, 111, 24));
        lineEdit = new QLineEdit(debit_types);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 60, 71, 21));
        label = new QLabel(debit_types);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 51, 21));
        label_2 = new QLabel(debit_types);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 51, 16));
        pushInsert = new QPushButton(debit_types);
        pushInsert->setObjectName(QString::fromUtf8("pushInsert"));
        pushInsert->setGeometry(QRect(20, 100, 61, 31));
        pushCancel = new QPushButton(debit_types);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(120, 100, 61, 31));

        retranslateUi(debit_types);

        QMetaObject::connectSlotsByName(debit_types);
    } // setupUi

    void retranslateUi(QDialog *debit_types)
    {
        debit_types->setWindowTitle(QApplication::translate("debit_types", "\316\244\317\215\317\200\316\277\316\271 \316\247\317\201\316\265\317\216\317\203\316\265\317\211\316\275", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("debit_types", "T\317\214\317\200\316\277\317\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("debit_types", "\316\247\317\201\316\255\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushInsert->setText(QString());
        pushCancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class debit_types: public Ui_debit_types {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBIT_TYPES_H
