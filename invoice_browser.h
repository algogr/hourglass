#ifndef INVOICE_BROWSER_H
#define INVOICE_BROWSER_H

#include <QDialog>
#include <QtSql>
#include "invoice_customer.h"


namespace Ui {
    class invoice_browser;
}

class invoice_browser : public QDialog
{
    Q_OBJECT

public:
    explicit invoice_browser(QWidget *parent = 0,QSqlDatabase *db1=0);
    ~invoice_browser();

private:
    Ui::invoice_browser *ui;
    QSqlDatabase *db1;
    QSqlQueryModel *invoice_model;
    QString cusid;
    void refresh_invoices();

private slots:
    void show_customer();
};

#endif // INVOICE_BROWSER_H
