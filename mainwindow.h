#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "constants.h"
#include "customer.h"
#include "tasks.h"
#include "migration.h"
#include "invoice_browser.h"
#include "email_tasks.h"
#include "weekgraph.h"
#include "invoicereview.h"
#include "projectsbrowser.h"
#include <QtNetwork>
#include <QTcpSocket>
#include "asterisk_callerid_monitor.h"
#include "incoming_call.h"
extern QString g_HOST,g_USER,g_PASS,g_ASTERISK_SERVER,g_ASTERISK_EXTENSION,g_ASTERISK_CONTEXT,g_ASTERISK_DIAL_PREFIX;
extern QString g_ASTERISK_LOGIN,g_ASTERISK_SECRET,g_AST_MYSQL_USER;
extern QString g_AST_MYSQL_PASS,g_AST_MYSQL_CDR;

extern int g_ASTERISK_PORT,g_AST_MYSQL_PORT;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase db1,db2;

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *customer_model;
    QSqlQueryModel *places_model;
    QSqlQueryModel *project_model;
    QSqlQueryModel *tasks_model;
    QSqlQueryModel *tasks_full_model;
    QSqlQueryModel *daily_calls_model;
    QSqlQueryModel *full_calls_model;
    QString cusid;
    void refresh_places();
    void refresh_projects();
    void refresh_daily_calls();
    void refresh_full_calls();
    bool tracking_status;
    QString current_task_id;
    QTimer *timer,*timer_asterisk;
    void refresh_daysum();
    WeekGraph *drb;
    int current_tab;


private slots:
    void refresh_customers();
    void new_customer();
    void customer_selection_changed();
    void edit_customer();
    void tracking_pressed();
    void refresh_tasks();
    void refresh_full_tasks();
    void remove_invalid_chars();
    void refresh_time();
    void edit_task();
    void edit_task_full();
    void add_earlier_task();
    void do_migration();
    void invoicing();
    void email_tasks();
    void change_graph(int i);
    void context_menu(const QPoint& pos);
    void context_menu_daily_calls(const QPoint& pos);
    void context_menu_full_calls(const QPoint& pos);
    void invoice_review();
    void projects();
    void table_clicked();
    void table2_clicked();
    void delete_clicked();
    void tab_changed(int tab);
    void sortbycolumn(int column);
    void dial_customer(const QPoint& pos);
    void dial(QString phone);
    void incoming_call(QString callerid);
    void refresh_calls();

};

#endif // MAINWINDOW_H
