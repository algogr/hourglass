/********************************************************************************
** Form generated from reading UI file 'invoice_customer.ui'
**
** Created: Tue Jul 2 11:47:41 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICE_CUSTOMER_H
#define UI_INVOICE_CUSTOMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_invoice_customer
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QWidget *tab_2;
    QTableView *tableView_2;
    QWidget *tab_4;
    QTableView *tableView_4;
    QWidget *tab_3;
    QTableView *tableView_3;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QCheckBox *checkBox;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLCDNumber *lcdAtimol;
    QLCDNumber *lcdTimol;
    QLCDNumber *lcdAjia;
    QPushButton *pushInvoice;

    void setupUi(QDialog *invoice_customer)
    {
        if (invoice_customer->objectName().isEmpty())
            invoice_customer->setObjectName(QString::fromUtf8("invoice_customer"));
        invoice_customer->resize(531, 474);
        tabWidget = new QTabWidget(invoice_customer);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 200, 511, 271));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 501, 241));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(0, 0, 501, 241));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tableView_4 = new QTableView(tab_4);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setGeometry(QRect(0, 0, 501, 241));
        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tableView_3 = new QTableView(tab_3);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(0, 0, 501, 241));
        tabWidget->addTab(tab_3, QString());
        label = new QLabel(invoice_customer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 491, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        scrollArea = new QScrollArea(invoice_customer);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 69, 221, 91));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 89));
        dateEdit = new QDateEdit(scrollAreaWidgetContents);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(90, 10, 110, 21));
        dateEdit->setCalendarPopup(true);
        dateEdit_2 = new QDateEdit(scrollAreaWidgetContents);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(90, 40, 110, 22));
        dateEdit_2->setCalendarPopup(true);
        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 20, 71, 31));
        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox = new QGroupBox(invoice_customer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(240, 70, 281, 91));
        QFont font1;
        font1.setPointSize(10);
        groupBox->setFont(font1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(67, 0, 81, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 30, 101, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(17, 60, 121, 21));
        lcdAtimol = new QLCDNumber(groupBox);
        lcdAtimol->setObjectName(QString::fromUtf8("lcdAtimol"));
        lcdAtimol->setGeometry(QRect(150, 0, 111, 23));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lcdAtimol->setFont(font2);
        lcdAtimol->setAutoFillBackground(true);
        lcdAtimol->setFrameShape(QFrame::Box);
        lcdAtimol->setSegmentStyle(QLCDNumber::Flat);
        lcdTimol = new QLCDNumber(groupBox);
        lcdTimol->setObjectName(QString::fromUtf8("lcdTimol"));
        lcdTimol->setGeometry(QRect(150, 30, 111, 23));
        lcdTimol->setSegmentStyle(QLCDNumber::Flat);
        lcdAjia = new QLCDNumber(groupBox);
        lcdAjia->setObjectName(QString::fromUtf8("lcdAjia"));
        lcdAjia->setGeometry(QRect(150, 60, 111, 23));
        lcdAjia->setSegmentStyle(QLCDNumber::Flat);
        pushInvoice = new QPushButton(invoice_customer);
        pushInvoice->setObjectName(QString::fromUtf8("pushInvoice"));
        pushInvoice->setGeometry(QRect(400, 160, 85, 41));

        retranslateUi(invoice_customer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(invoice_customer);
    } // setupUi

    void retranslateUi(QDialog *invoice_customer)
    {
        invoice_customer->setWindowTitle(QApplication::translate("invoice_customer", "\316\244\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("invoice_customer", "\316\221\316\275\316\261\316\273\317\205\317\204\316\271\316\272\316\256", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("invoice_customer", "\316\243\317\205\316\275\316\277\317\200\317\204\316\271\316\272\316\256", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("invoice_customer", "Projects", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("invoice_customer", "'\316\237\316\273\316\265\317\202 \316\277\316\271 \316\272\316\271\316\275\316\256\317\203\316\265\316\271\317\202", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("invoice_customer", "\317\204\316\265\317\203\317\204", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("invoice_customer", "d/M/yy", 0, QApplication::UnicodeUTF8));
        dateEdit_2->setDisplayFormat(QApplication::translate("invoice_customer", "d/M/yy", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("invoice_customer", "\316\224\316\271\316\254\317\203\317\204\316\267\316\274\316\261", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("invoice_customer", "\316\243\317\215\316\275\316\277\316\273\316\261", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("invoice_customer", "\316\221\317\204\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\204\316\261", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("invoice_customer", "\316\240\317\201\316\277\317\202 \316\244\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("invoice_customer", "\316\221\316\276\316\257\316\261 \317\200\317\201\316\277\317\202 \316\244\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushInvoice->setToolTip(QApplication::translate("invoice_customer", "\316\244\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushInvoice->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class invoice_customer: public Ui_invoice_customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICE_CUSTOMER_H
