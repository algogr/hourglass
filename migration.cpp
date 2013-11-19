#include "migration.h"
#include "ui_migration.h"

migration::migration(QWidget *parent,QSqlDatabase * db1) :
    QDialog(parent),
    ui(new Ui::migration)
{
    ui->setupUi(this);
    this->db1=db1;
    db2=QSqlDatabase::addDatabase("QSQLITE","hamster");
    db2.setDatabaseName("/home/jim/simantika/hamster/hamster.db");
    db2=QSqlDatabase::database("hamster");
    if (!db2.open())
    {
        qDebug()<<"Απέτυχε η σύνδεση με τη βάση hamster";
        exit(0);
    }
    connect (ui->pushButton,SIGNAL(released()),this,SLOT(do_migration()));

}

migration::~migration()
{
    delete ui;
}

void migration::do_migration()
{
    QSqlQuery query1(*db1),query2(db2);
    query2.exec("SELECT a.id,a.name, f.start_time, f.end_time, f.description,ft.tag_id FROM activities a, facts f, fact_tags ft WHERE a.id = f.activity_id AND f.id = ft.fact_id");
    while (query2.next())
    {
        qDebug()<<"QUERY2"<<query2.value(0);
        query1.exec("insert into tmp_migration(cusid,cusname,start_time,end_time,comment,placeid) values("+query2.value(0).toString()+",'"+query2.value(1).toString()+"','"+query2.value(2).toString()+"','"+query2.value(3).toString()+"','"+query2.value(4).toString()+"',"+query2.value(5).toString()+")");
    }
    delete(this);
}
