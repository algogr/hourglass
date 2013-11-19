/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jul 2 11:47:41 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *actionT;
    QAction *action_3;
    QAction *actionMigration;
    QAction *action_2;
    QAction *actionEmail;
    QAction *actionReview;
    QAction *actionProjects;
    QWidget *centralwidget;
    QTableView *tableCustomers;
    QLabel *label_customer;
    QComboBox *comboplace;
    QComboBox *comboproject;
    QTextEdit *textEdit;
    QPushButton *pushHour;
    QLabel *labelCustTime;
    QLabel *labelTime;
    QPushButton *pushAddEarlier;
    QLabel *labelDaySum;
    QComboBox *comboGraph;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QWidget *tab_3;
    QTableView *tableTodayCalls;
    QWidget *tab_2;
    QTableView *tableView_2;
    QWidget *tab_4;
    QTableView *tableAllCalls;
    QPushButton *pushDelete;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menuReports;
    QMenu *menuTools;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        actionT = new QAction(MainWindow);
        actionT->setObjectName(QString::fromUtf8("actionT"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        actionMigration = new QAction(MainWindow);
        actionMigration->setObjectName(QString::fromUtf8("actionMigration"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionEmail = new QAction(MainWindow);
        actionEmail->setObjectName(QString::fromUtf8("actionEmail"));
        actionReview = new QAction(MainWindow);
        actionReview->setObjectName(QString::fromUtf8("actionReview"));
        actionProjects = new QAction(MainWindow);
        actionProjects->setObjectName(QString::fromUtf8("actionProjects"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableCustomers = new QTableView(centralwidget);
        tableCustomers->setObjectName(QString::fromUtf8("tableCustomers"));
        tableCustomers->setGeometry(QRect(10, 10, 161, 541));
        label_customer = new QLabel(centralwidget);
        label_customer->setObjectName(QString::fromUtf8("label_customer"));
        label_customer->setGeometry(QRect(190, 230, 121, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_customer->setFont(font);
        comboplace = new QComboBox(centralwidget);
        comboplace->setObjectName(QString::fromUtf8("comboplace"));
        comboplace->setGeometry(QRect(330, 230, 121, 31));
        comboproject = new QComboBox(centralwidget);
        comboproject->setObjectName(QString::fromUtf8("comboproject"));
        comboproject->setGeometry(QRect(460, 230, 121, 31));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(600, 200, 191, 78));
        pushHour = new QPushButton(centralwidget);
        pushHour->setObjectName(QString::fromUtf8("pushHour"));
        pushHour->setGeometry(QRect(430, 270, 61, 41));
        labelCustTime = new QLabel(centralwidget);
        labelCustTime->setObjectName(QString::fromUtf8("labelCustTime"));
        labelCustTime->setGeometry(QRect(190, 270, 231, 41));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        labelCustTime->setFont(font1);
        labelTime = new QLabel(centralwidget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(500, 270, 91, 41));
        QFont font2;
        font2.setPointSize(18);
        labelTime->setFont(font2);
        pushAddEarlier = new QPushButton(centralwidget);
        pushAddEarlier->setObjectName(QString::fromUtf8("pushAddEarlier"));
        pushAddEarlier->setGeometry(QRect(740, 380, 51, 41));
        labelDaySum = new QLabel(centralwidget);
        labelDaySum->setObjectName(QString::fromUtf8("labelDaySum"));
        labelDaySum->setGeometry(QRect(720, 170, 71, 31));
        QFont font3;
        font3.setPointSize(25);
        labelDaySum->setFont(font3);
        labelDaySum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboGraph = new QComboBox(centralwidget);
        comboGraph->setObjectName(QString::fromUtf8("comboGraph"));
        comboGraph->setGeometry(QRect(350, 170, 121, 31));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(180, 320, 551, 231));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 10, 541, 191));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tableTodayCalls = new QTableView(tab_3);
        tableTodayCalls->setObjectName(QString::fromUtf8("tableTodayCalls"));
        tableTodayCalls->setGeometry(QRect(0, 0, 541, 201));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(0, 10, 541, 191));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tableAllCalls = new QTableView(tab_4);
        tableAllCalls->setObjectName(QString::fromUtf8("tableAllCalls"));
        tableAllCalls->setGeometry(QRect(0, 10, 541, 192));
        tabWidget->addTab(tab_4, QString());
        pushDelete = new QPushButton(centralwidget);
        pushDelete->setObjectName(QString::fromUtf8("pushDelete"));
        pushDelete->setGeometry(QRect(740, 440, 51, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menuReports = new QMenu(menubar);
        menuReports->setObjectName(QString::fromUtf8("menuReports"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuReports->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(actionProjects);
        menu_2->addAction(menu_3->menuAction());
        menu_3->addAction(actionT);
        menu_3->addAction(action_3);
        menuTools->addAction(actionEmail);
        menuTools->addAction(action_2);
        menuTools->addAction(actionReview);
        menuTools->addAction(actionMigration);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HourGlass", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\316\240\317\201\316\277\317\203\316\270\316\256\316\272\316\267", 0, QApplication::UnicodeUTF8));
        actionT->setText(QApplication::translate("MainWindow", "T\317\215\317\200\316\277\316\271 \316\225\317\201\316\263\316\261\317\203\316\271\317\216\316\275", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "\316\244\317\214\317\200\316\277\316\271 \316\225\316\272\317\204\316\255\316\273\316\265\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        actionMigration->setText(QApplication::translate("MainWindow", "Migration", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\316\244\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        actionEmail->setText(QApplication::translate("MainWindow", "Email E\317\201\316\263\316\261\317\203\316\271\317\216\316\275", 0, QApplication::UnicodeUTF8));
        actionReview->setText(QApplication::translate("MainWindow", "Review \316\244\316\271\316\274\316\277\316\273\317\214\316\263\316\267\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        actionProjects->setText(QApplication::translate("MainWindow", "Projects", 0, QApplication::UnicodeUTF8));
        label_customer->setText(QString());
        pushHour->setText(QString());
        labelCustTime->setText(QString());
        labelTime->setText(QString());
        pushAddEarlier->setText(QString());
        labelDaySum->setText(QApplication::translate("MainWindow", "120", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\316\225\317\201\316\263\316\261\317\203\316\257\316\265\317\202 \316\227\316\274\316\255\317\201\316\261\317\202", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\316\232\316\273\316\256\317\203\316\265\316\271\317\202 \316\227\316\274\316\255\317\201\316\261\317\202", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\316\214\316\273\316\265\317\202 \316\277\316\271 \316\265\317\201\316\263\316\261\317\203\316\257\316\265\317\202", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\316\214\316\273\316\265\317\202 \316\277\316\271 \316\272\316\273\316\256\317\203\316\265\316\271\317\202", 0, QApplication::UnicodeUTF8));
        pushDelete->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\316\240\316\265\316\273\316\254\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\316\240\316\261\317\201\316\261\316\274\316\265\317\204\317\201\316\277\317\200\316\277\316\257\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\316\240\316\257\316\275\316\261\316\272\316\265\317\202", 0, QApplication::UnicodeUTF8));
        menuReports->setTitle(QApplication::translate("MainWindow", "Reports", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
