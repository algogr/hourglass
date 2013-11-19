/********************************************************************************
** Form generated from reading UI file 'incoming_call.ui'
**
** Created: Wed May 2 22:26:28 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOMING_CALL_H
#define UI_INCOMING_CALL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Incoming_Call
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushOk;
    QPushButton *pushDismiss;
    QLabel *labelPhone;

    void setupUi(QDialog *Incoming_Call)
    {
        if (Incoming_Call->objectName().isEmpty())
            Incoming_Call->setObjectName(QString::fromUtf8("Incoming_Call"));
        Incoming_Call->resize(402, 156);
        label = new QLabel(Incoming_Call);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 161, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        comboBox = new QComboBox(Incoming_Call);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 50, 231, 41));
        comboBox->setFont(font);
        pushOk = new QPushButton(Incoming_Call);
        pushOk->setObjectName(QString::fromUtf8("pushOk"));
        pushOk->setGeometry(QRect(100, 110, 71, 41));
        pushDismiss = new QPushButton(Incoming_Call);
        pushDismiss->setObjectName(QString::fromUtf8("pushDismiss"));
        pushDismiss->setGeometry(QRect(200, 110, 71, 41));
        labelPhone = new QLabel(Incoming_Call);
        labelPhone->setObjectName(QString::fromUtf8("labelPhone"));
        labelPhone->setGeometry(QRect(180, 10, 211, 41));
        labelPhone->setFont(font);

        retranslateUi(Incoming_Call);

        QMetaObject::connectSlotsByName(Incoming_Call);
    } // setupUi

    void retranslateUi(QDialog *Incoming_Call)
    {
        Incoming_Call->setWindowTitle(QApplication::translate("Incoming_Call", "Asterisk", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Incoming_Call", "\316\225\316\271\317\203\316\265\317\201\317\207\317\214\316\274\316\265\316\275\316\267 \316\232\316\273\316\256\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushOk->setText(QString());
        pushDismiss->setText(QString());
        labelPhone->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Incoming_Call: public Ui_Incoming_Call {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMING_CALL_H
