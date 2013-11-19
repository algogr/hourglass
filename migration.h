#ifndef MIGRATION_H
#define MIGRATION_H

#include <QDialog>
#include <QtSql>

namespace Ui {
    class migration;
}

class migration : public QDialog
{
    Q_OBJECT

public:
    explicit migration(QWidget *parent = 0,QSqlDatabase * db1=0);
    ~migration();

private:
    Ui::migration *ui;
    QSqlDatabase *db1;
    QSqlDatabase db2;

private slots:
    void do_migration();
};

#endif // MIGRATION_H
