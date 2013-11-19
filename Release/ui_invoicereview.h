/********************************************************************************
** Form generated from reading UI file 'invoicereview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICEREVIEW_H
#define UI_INVOICEREVIEW_H

#include <QtCore/QDate>
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

class Ui_InvoiceReview
{
public:
    QTableView *tableFintrade;
    QTableView *tableLines;
    QDateEdit *dateFrom;
    QDateEdit *dateTo;
    QPushButton *pushDelete;
    QPushButton *pushEmail;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *InvoiceReview)
    {
        if (InvoiceReview->objectName().isEmpty())
            InvoiceReview->setObjectName(QString::fromUtf8("InvoiceReview"));
        InvoiceReview->resize(536, 391);
        tableFintrade = new QTableView(InvoiceReview);
        tableFintrade->setObjectName(QString::fromUtf8("tableFintrade"));
        tableFintrade->setGeometry(QRect(10, 50, 256, 131));
        tableLines = new QTableView(InvoiceReview);
        tableLines->setObjectName(QString::fromUtf8("tableLines"));
        tableLines->setGeometry(QRect(10, 190, 511, 192));
        dateFrom = new QDateEdit(InvoiceReview);
        dateFrom->setObjectName(QString::fromUtf8("dateFrom"));
        dateFrom->setGeometry(QRect(110, 10, 110, 22));
        dateFrom->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        dateFrom->setDate(QDate(2000, 1, 1));
        dateFrom->setCalendarPopup(true);
        dateTo = new QDateEdit(InvoiceReview);
        dateTo->setObjectName(QString::fromUtf8("dateTo"));
        dateTo->setGeometry(QRect(320, 10, 110, 22));
        dateTo->setCalendarPopup(true);
        pushDelete = new QPushButton(InvoiceReview);
        pushDelete->setObjectName(QString::fromUtf8("pushDelete"));
        pushDelete->setGeometry(QRect(280, 50, 85, 41));
        pushEmail = new QPushButton(InvoiceReview);
        pushEmail->setObjectName(QString::fromUtf8("pushEmail"));
        pushEmail->setGeometry(QRect(410, 50, 85, 41));
        pushEmail->setAutoDefault(false);
        label = new QLabel(InvoiceReview);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 91, 16));
        label_2 = new QLabel(InvoiceReview);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 10, 91, 16));

        retranslateUi(InvoiceReview);

        QMetaObject::connectSlotsByName(InvoiceReview);
    } // setupUi

    void retranslateUi(QDialog *InvoiceReview)
    {
        InvoiceReview->setWindowTitle(QApplication::translate("InvoiceReview", "Review \316\244\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        dateFrom->setDisplayFormat(QApplication::translate("InvoiceReview", "d/M/yy", 0, QApplication::UnicodeUTF8));
        dateTo->setDisplayFormat(QApplication::translate("InvoiceReview", "d/M/yy", 0, QApplication::UnicodeUTF8));
        pushDelete->setText(QString());
        pushEmail->setText(QString());
        label->setText(QApplication::translate("InvoiceReview", "\316\221\317\200\317\214 \316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InvoiceReview", "\316\225\317\211\317\202 \316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InvoiceReview: public Ui_InvoiceReview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICEREVIEW_H
