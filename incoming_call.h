#ifndef INCOMING_CALL_H
#define INCOMING_CALL_H

#include <QDialog>
#include <QtSql>
#include "constants.h"

namespace Ui {
    class Incoming_Call;
}

class Incoming_Call : public QDialog
{
    Q_OBJECT

public:
    explicit Incoming_Call(QWidget *parent = 0,QSqlDatabase *db1=0,QString phonebookid="",QString phoneno="");
    ~Incoming_Call();

private:
    Ui::Incoming_Call *ui;
    QSqlDatabase *db1;
    QString cusid,phoneno,phonebookid;
    QSqlQueryModel *customer_model;
    bool edit;

private slots:
    void customer_changed();
    void ok_pushed();
    void dismiss_pushed();
};

#endif // INCOMING_CALL_H
