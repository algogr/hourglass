/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created: Wed May 2 22:26:28 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QPushButton *pushOk;
    QPushButton *pushCancel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_15;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *linemysqlhost;
    QLineEdit *linemysqluser;
    QLineEdit *linemysqlpass;
    QLineEdit *lineemail;
    QLineEdit *lineemailinv;
    QLineEdit *linemailserver;
    QLineEdit *lineastserver;
    QLineEdit *lineastport;
    QLineEdit *lineastcontext;
    QLineEdit *lineastextension;
    QLineEdit *lineasteriskprefix;
    QLineEdit *lineamilogin;
    QLineEdit *lineamisecret;
    QLineEdit *lineastmysqlport;
    QLineEdit *lineastmysqluser;
    QLineEdit *lineastmysqlpass;
    QLineEdit *lineastmysqlcdr;

    void setupUi(QDialog *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(360, 552);
        pushOk = new QPushButton(Config);
        pushOk->setObjectName(QString::fromUtf8("pushOk"));
        pushOk->setGeometry(QRect(110, 500, 38, 27));
        pushCancel = new QPushButton(Config);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(154, 500, 38, 27));
        widget = new QWidget(Config);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 130, 471));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout->addWidget(label_13);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout->addWidget(label_14);

        label_17 = new QLabel(widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout->addWidget(label_17);

        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout->addWidget(label_16);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout->addWidget(label_15);

        widget1 = new QWidget(Config);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(146, 10, 191, 472));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        linemysqlhost = new QLineEdit(widget1);
        linemysqlhost->setObjectName(QString::fromUtf8("linemysqlhost"));
        linemysqlhost->setMaximumSize(QSize(76, 22));

        verticalLayout_2->addWidget(linemysqlhost);

        linemysqluser = new QLineEdit(widget1);
        linemysqluser->setObjectName(QString::fromUtf8("linemysqluser"));

        verticalLayout_2->addWidget(linemysqluser);

        linemysqlpass = new QLineEdit(widget1);
        linemysqlpass->setObjectName(QString::fromUtf8("linemysqlpass"));

        verticalLayout_2->addWidget(linemysqlpass);

        lineemail = new QLineEdit(widget1);
        lineemail->setObjectName(QString::fromUtf8("lineemail"));

        verticalLayout_2->addWidget(lineemail);

        lineemailinv = new QLineEdit(widget1);
        lineemailinv->setObjectName(QString::fromUtf8("lineemailinv"));

        verticalLayout_2->addWidget(lineemailinv);

        linemailserver = new QLineEdit(widget1);
        linemailserver->setObjectName(QString::fromUtf8("linemailserver"));

        verticalLayout_2->addWidget(linemailserver);

        lineastserver = new QLineEdit(widget1);
        lineastserver->setObjectName(QString::fromUtf8("lineastserver"));

        verticalLayout_2->addWidget(lineastserver);

        lineastport = new QLineEdit(widget1);
        lineastport->setObjectName(QString::fromUtf8("lineastport"));

        verticalLayout_2->addWidget(lineastport);

        lineastcontext = new QLineEdit(widget1);
        lineastcontext->setObjectName(QString::fromUtf8("lineastcontext"));

        verticalLayout_2->addWidget(lineastcontext);

        lineastextension = new QLineEdit(widget1);
        lineastextension->setObjectName(QString::fromUtf8("lineastextension"));

        verticalLayout_2->addWidget(lineastextension);

        lineasteriskprefix = new QLineEdit(widget1);
        lineasteriskprefix->setObjectName(QString::fromUtf8("lineasteriskprefix"));

        verticalLayout_2->addWidget(lineasteriskprefix);

        lineamilogin = new QLineEdit(widget1);
        lineamilogin->setObjectName(QString::fromUtf8("lineamilogin"));

        verticalLayout_2->addWidget(lineamilogin);

        lineamisecret = new QLineEdit(widget1);
        lineamisecret->setObjectName(QString::fromUtf8("lineamisecret"));

        verticalLayout_2->addWidget(lineamisecret);

        lineastmysqlport = new QLineEdit(widget1);
        lineastmysqlport->setObjectName(QString::fromUtf8("lineastmysqlport"));

        verticalLayout_2->addWidget(lineastmysqlport);

        lineastmysqluser = new QLineEdit(widget1);
        lineastmysqluser->setObjectName(QString::fromUtf8("lineastmysqluser"));

        verticalLayout_2->addWidget(lineastmysqluser);

        lineastmysqlpass = new QLineEdit(widget1);
        lineastmysqlpass->setObjectName(QString::fromUtf8("lineastmysqlpass"));

        verticalLayout_2->addWidget(lineastmysqlpass);

        lineastmysqlcdr = new QLineEdit(widget1);
        lineastmysqlcdr->setObjectName(QString::fromUtf8("lineastmysqlcdr"));

        verticalLayout_2->addWidget(lineastmysqlcdr);


        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QDialog *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Dialog", 0, QApplication::UnicodeUTF8));
        pushOk->setText(QString());
        pushCancel->setText(QString());
        label->setText(QApplication::translate("Config", "MYSQL Host", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Config", "MYSQL Username", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Config", "MYSQL Password", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Config", "Email ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Config", "Email \316\244\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Config", "Mail Server", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Config", "ASTERISK Server", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Config", "ASTERISK Port", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Config", "ASTERISK Context", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Config", "ASTERISK Extension", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Config", "ASTERISK Dial Prefix", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Config", "ASTERISK Manager login", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Config", "ASTERISK Manager secret", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Config", "ASTERISK MYSQL Port", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Config", "ASTERISK MYSQL User", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Config", "ASTERISK MYSQL Password", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Config", "ASTERISK MYSQL CDR Tablename", 0, QApplication::UnicodeUTF8));
        linemysqlhost->setText(QApplication::translate("Config", "localhost", 0, QApplication::UnicodeUTF8));
        linemysqluser->setText(QApplication::translate("Config", "root", 0, QApplication::UnicodeUTF8));
        linemysqlpass->setText(QApplication::translate("Config", "101264", 0, QApplication::UnicodeUTF8));
        lineemail->setText(QApplication::translate("Config", "jimpar@algo.gr", 0, QApplication::UnicodeUTF8));
        lineemailinv->setText(QApplication::translate("Config", "rxa@algo.gr", 0, QApplication::UnicodeUTF8));
        linemailserver->setText(QApplication::translate("Config", "192.168.2.251", 0, QApplication::UnicodeUTF8));
        lineastserver->setText(QApplication::translate("Config", "192.168.2.254", 0, QApplication::UnicodeUTF8));
        lineastport->setText(QApplication::translate("Config", "5038", 0, QApplication::UnicodeUTF8));
        lineastcontext->setText(QApplication::translate("Config", "algo_DLPN_Internal", 0, QApplication::UnicodeUTF8));
        lineastextension->setText(QApplication::translate("Config", "SIP/15", 0, QApplication::UnicodeUTF8));
        lineasteriskprefix->setText(QApplication::translate("Config", "9", 0, QApplication::UnicodeUTF8));
        lineamilogin->setText(QApplication::translate("Config", "admin", 0, QApplication::UnicodeUTF8));
        lineamisecret->setText(QApplication::translate("Config", "admin", 0, QApplication::UnicodeUTF8));
        lineastmysqlport->setText(QApplication::translate("Config", "3306", 0, QApplication::UnicodeUTF8));
        lineastmysqluser->setText(QApplication::translate("Config", "asterisk", 0, QApplication::UnicodeUTF8));
        lineastmysqlpass->setText(QApplication::translate("Config", "asterisk", 0, QApplication::UnicodeUTF8));
        lineastmysqlcdr->setText(QApplication::translate("Config", "cdr", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
