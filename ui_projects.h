/********************************************************************************
** Form generated from reading UI file 'projects.ui'
**
** Created: Wed May 2 22:26:27 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTS_H
#define UI_PROJECTS_H

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
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Projects
{
public:
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushInsert;
    QPushButton *pushCancel;

    void setupUi(QDialog *Projects)
    {
        if (Projects->objectName().isEmpty())
            Projects->setObjectName(QString::fromUtf8("Projects"));
        Projects->resize(350, 300);
        comboBox = new QComboBox(Projects);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 30, 171, 31));
        lineEdit = new QLineEdit(Projects);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 100, 171, 31));
        spinBox = new QSpinBox(Projects);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(120, 160, 171, 31));
        spinBox->setMaximum(99999);
        label = new QLabel(Projects);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 35, 81, 21));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(Projects);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 81, 21));
        label_2->setFont(font);
        label_3 = new QLabel(Projects);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 81, 21));
        label_3->setFont(font);
        pushInsert = new QPushButton(Projects);
        pushInsert->setObjectName(QString::fromUtf8("pushInsert"));
        pushInsert->setGeometry(QRect(50, 220, 85, 41));
        pushCancel = new QPushButton(Projects);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(200, 220, 85, 41));

        retranslateUi(Projects);

        QMetaObject::connectSlotsByName(Projects);
    } // setupUi

    void retranslateUi(QDialog *Projects)
    {
        Projects->setWindowTitle(QApplication::translate("Projects", "Project", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Projects", "\316\240\316\265\316\273\316\254\317\204\316\267\317\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Projects", "Project", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Projects", "\316\221\316\274\316\277\316\271\316\262\316\256", 0, QApplication::UnicodeUTF8));
        pushInsert->setText(QString());
        pushCancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Projects: public Ui_Projects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTS_H
