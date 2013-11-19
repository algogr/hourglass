#ifndef TASKS_H
#define TASKS_H

#include <QDialog>
#include <QtSql>
#include "constants.h"
#include <QMessageBox>

namespace Ui {
    class tasks;
}

class tasks : public QDialog
{
    Q_OBJECT

public:
    explicit tasks(QWidget *parent = 0,QSqlDatabase* db1=0,QString task_id="",int mode=0);
    ~tasks();

private:
    Ui::tasks *ui;
    QSqlDatabase *db1;
    QString task_id;
    int mode;
    QSqlQueryModel *customermodel;
    QSqlQueryModel *placesmodel;
    QSqlQueryModel *projectmodel;
    void populate_customers();
    void populate_places();
    void populate_projects();
    QString cusid;

private slots:
    void set_customer();
    void ok_pressed();
    void cancel_pressed();
    void stop_time_changed();

signals:
    void refresh_tasks();
};

#endif // TASKS_H
