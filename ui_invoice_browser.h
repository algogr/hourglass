/********************************************************************************
** Form generated from reading UI file 'invoice_browser.ui'
**
** Created: Wed May 2 22:26:27 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICE_BROWSER_H
#define UI_INVOICE_BROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_invoice_browser
{
public:
    QTableView *tableView;

    void setupUi(QDialog *invoice_browser)
    {
        if (invoice_browser->objectName().isEmpty())
            invoice_browser->setObjectName(QString::fromUtf8("invoice_browser"));
        invoice_browser->resize(450, 300);
        tableView = new QTableView(invoice_browser);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 431, 271));

        retranslateUi(invoice_browser);

        QMetaObject::connectSlotsByName(invoice_browser);
    } // setupUi

    void retranslateUi(QDialog *invoice_browser)
    {
        invoice_browser->setWindowTitle(QApplication::translate("invoice_browser", "\316\225\316\272\316\272\317\201\316\265\316\274\317\214\317\204\316\267\317\204\316\265\317\202 \316\240\316\265\316\273\316\261\317\204\317\216\316\275", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class invoice_browser: public Ui_invoice_browser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICE_BROWSER_H
