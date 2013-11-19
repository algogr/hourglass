/********************************************************************************
** Form generated from reading UI file 'migration.ui'
**
** Created: Wed May 2 22:26:27 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIGRATION_H
#define UI_MIGRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_migration
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *migration)
    {
        if (migration->objectName().isEmpty())
            migration->setObjectName(QString::fromUtf8("migration"));
        migration->resize(400, 300);
        pushButton = new QPushButton(migration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 110, 141, 61));

        retranslateUi(migration);

        QMetaObject::connectSlotsByName(migration);
    } // setupUi

    void retranslateUi(QDialog *migration)
    {
        migration->setWindowTitle(QApplication::translate("migration", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("migration", "Migrate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class migration: public Ui_migration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIGRATION_H
