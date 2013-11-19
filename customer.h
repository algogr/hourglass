#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include "QtSql"
#include "constants.h"
#include "debit_types.h"

namespace Ui {
    class customer;
}

class customer : public QDialog
{
    Q_OBJECT

public:
    explicit customer(QWidget *parent = 0,QSqlDatabase* db1=0,int mode=0,QString cusid="");
    ~customer();

private:
    Ui::customer *ui;
    QSqlDatabase *db1;
    int mode;
    QString cusid;


private slots:
    void text_changed();
    void insert_customer();
    void insert_debit_type();
    void refresh_sql();
    void check_clicked();
    void cancel_clicked();

signals:
    void main_customers_refresh();
};

#endif // CUSTOMER_H
