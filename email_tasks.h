#ifndef EMAIL_TASKS_H
#define EMAIL_TASKS_H

#include <QDialog>
#include <QtSql>
#include "constants.h"
extern QString g_MAIL_FROM,g_MAIL_SERVER;

namespace Ui {
    class Email_tasks;
}

class Email_tasks : public QDialog
{
    Q_OBJECT

public:
    explicit Email_tasks(QWidget *parent = 0,QSqlDatabase *db1=0);
    ~Email_tasks();

private:
    Ui::Email_tasks *ui;
    QSqlDatabase *db1;
    QSqlQueryModel *model;
    void refresh_table();
    void send_email(QString from,QString to,QString subject,QString body);
    void prepare_footer(QString &body);

private slots:
    void date_changed();
    void prepare_emails();
    void cancel_pressed();
};

#endif // EMAIL_TASKS_H
