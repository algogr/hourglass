/********************************************************************************
** Form generated from reading UI file 'generalbrowser.ui'
**
** Created: Wed May 2 22:26:28 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALBROWSER_H
#define UI_GENERALBROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_GeneralBrowser
{
public:
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *GeneralBrowser)
    {
        if (GeneralBrowser->objectName().isEmpty())
            GeneralBrowser->setObjectName(QString::fromUtf8("GeneralBrowser"));
        GeneralBrowser->resize(457, 300);
        tableView = new QTableView(GeneralBrowser);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 381, 281));
        pushButton = new QPushButton(GeneralBrowser);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(394, 120, 61, 51));

        retranslateUi(GeneralBrowser);

        QMetaObject::connectSlotsByName(GeneralBrowser);
    } // setupUi

    void retranslateUi(QDialog *GeneralBrowser)
    {
        GeneralBrowser->setWindowTitle(QApplication::translate("GeneralBrowser", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GeneralBrowser: public Ui_GeneralBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALBROWSER_H
