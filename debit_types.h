#ifndef DEBIT_TYPES_H
#define DEBIT_TYPES_H

#include <QDialog>
#include "constants.h"
#include <QtSql>
#include <QMessageBox>

namespace Ui {
    class debit_types;
}

class debit_types : public QDialog
{
    Q_OBJECT

public:
    explicit debit_types(QWidget *parent = 0,QSqlDatabase* db1=0,int mode=0,QString cusid="");
    ~debit_types();

private:
    Ui::debit_types *ui;
    QSqlDatabase *db1;
    QSqlQueryModel *m;
    int mode;
    QString cusid;

private slots:
    void text_changed();
    void insert_debit_type();

signals:
    void refresh_table();
};

#endif // DEBIT_TYPES_H
