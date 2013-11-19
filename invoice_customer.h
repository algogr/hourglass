#ifndef INVOICE_CUSTOMER_H
#define INVOICE_CUSTOMER_H

#include <QDialog>
#include <QtSql>
#include "chechkablesqlquerymodel.h"
#include "constants.h"


namespace Ui {
    class invoice_customer;
}

class invoice_customer : public QDialog
{
    Q_OBJECT

public:
    explicit invoice_customer(QWidget *parent = 0,QSqlDatabase *db1=0,QString cusid="");
    ~invoice_customer();
    QHash <int,int> checks;
    QHash <int,int> spins;

private:
    Ui::invoice_customer *ui;
    QSqlDatabase *db1;
    QString cusid;
    chechkablesqlquerymodel *tasks_model;
    QSqlQueryModel *tasks_model_2,*tasks_model_3,*tasks_model_4;
    void refresh_tasks_analytic();
    void refresh_tasks_summary();
    void refresh_tasks_full();
    void refresh_tasks_projects();

    QList<QString> createList(QString str);

private slots:
    void check_clicked();
    void date_from();
    void date_to();
    void editor_changed(bool state,const QModelIndex &index);
    void editor_spin_changed(int value,const QModelIndex &index);
    void create_invoice();
};

#endif // INVOICE_CUSTOMER_H
