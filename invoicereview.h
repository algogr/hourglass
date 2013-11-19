#ifndef INVOICEREVIEW_H
#define INVOICEREVIEW_H
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QtSql>
#include <constants.h>
extern QString g_MAIL_FROM,g_MAIL_INVOICER,g_MAIL_SERVER;

namespace Ui {
    class InvoiceReview;
}

class InvoiceReview : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceReview(QWidget *parent = 0,QSqlDatabase *db1=0);
    ~InvoiceReview();

private:
    Ui::InvoiceReview *ui;
    QSqlDatabase *db1;
    QSqlQueryModel * fintrade_model,* lines_model;
    void refresh_fintrade();
    void refresh_lines();
    void send_email(QString from,QString to,QString subject,QString body);

private slots:
    void invoice_changed();
    void date_changed();
    void delete_pressed();
    void email_pressed();
};

#endif // INVOICEREVIEW_H
