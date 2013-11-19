#ifndef PROJECTS_H
#define PROJECTS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
    class Projects;
}

class Projects : public QDialog
{
    Q_OBJECT

public:
    explicit Projects(QWidget *parent = 0,QSqlDatabase *db1=0,int mode=0,int pid=0);
    ~Projects();

private:
    Ui::Projects *ui;
    QSqlDatabase* db1;
    int mode;
    QSqlQueryModel *model;
    QString cusid,pid;

private slots:
    void customer_changed();
    void insert();
    void cancel();

signals:
    void data_changed();
};

#endif // PROJECTS_H
