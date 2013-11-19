#include "customer.h"
#include "ui_customer.h"

customer::customer(QWidget *parent,QSqlDatabase* db1,int mode,QString cusid) :
    QDialog(parent),
    ui(new Ui::customer)
{
    this->db1=db1;
    this->mode=mode;
    this->cusid=cusid;
    ui->setupUi(this);
    QIcon* icon =new QIcon((QString)APATH+"add.jpg");
    QIcon* icon1 =new QIcon((QString)APATH+"cancel.png");
    QIcon* icon2 =new QIcon((QString)APATH+"edit.png");
    ui->pushAddDebit->setIcon(*icon);
    ui->pushAddDebit->setIconSize(QSize( ui->pushAddDebit->size().width()-5,ui->pushAddDebit->size().height()-5 ));
    ui->pushLeave->setIcon(*icon1);
    ui->pushLeave->setIconSize(QSize( ui->pushLeave->size().width()-5,ui->pushLeave->size().height()-5 ));
    ui->pushCusInsert->setIcon(*icon);
    ui->pushCusInsert->setIconSize(QSize( ui->pushCusInsert->size().width()-5,ui->pushCusInsert->size().height()-5 ));
    ui->pushDeleteDebit->setIcon(*icon1);
    ui->pushDeleteDebit->setIconSize(QSize( ui->pushDeleteDebit->size().width()-5,ui->pushDeleteDebit->size().height()-5 ));
    ui->pushEditDebit->setIcon(*icon2);
    ui->pushEditDebit->setIconSize(QSize( ui->pushEditDebit->size().width()-5,ui->pushEditDebit->size().height()-5 ));

    if (mode==0)
        //INSERT MODE
    {
        ui->pushAddDebit->setEnabled(FALSE);
        ui->pushCusInsert->setEnabled(FALSE);
        ui->pushDeleteDebit->setEnabled(FALSE);
        ui->pushEditDebit->setEnabled(FALSE);

    }
    if (mode==1)
    {
        QSqlQuery query(*db1);
        query.exec("select name,email1,email2,active,phone from customers where id="+cusid);
        query.next();
        ui->lineEdit->setText(query.value(0).toString());
        ui->lineEmail1->setText(query.value(1).toString());
        ui->lineEmail2->setText(query.value(2).toString());
        if(query.value(3).toInt()==0)
            ui->checkActive->setCheckState(Qt::Unchecked);
        else
            ui->checkActive->setCheckState(Qt::Checked);
        ui->linePhone->setText((query.value(4).toString()));
        ui->pushCusInsert->setEnabled(FALSE);
        refresh_sql();
    }
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(text_changed()));
    connect(ui->lineEmail1,SIGNAL(textChanged(QString)),this,SLOT(text_changed()));
    connect(ui->lineEmail2,SIGNAL(textChanged(QString)),this,SLOT(text_changed()));
    connect(ui->linePhone,SIGNAL(textChanged(QString)),this,SLOT(text_changed()));
    connect(ui->pushCusInsert,SIGNAL(released()),this,SLOT(insert_customer()));
    connect(ui->pushAddDebit,SIGNAL(released()),this,SLOT(insert_debit_type()));
    connect(ui->checkActive,SIGNAL(clicked()),this,SLOT(check_clicked()));
    connect(ui->pushLeave,SIGNAL(released()),this,SLOT(cancel_clicked()));

}

customer::~customer()
{
    delete ui;
}

void customer::text_changed()
{
    ui->lineEdit->setText(ui->lineEdit->text().toUpper());
    if (ui->lineEdit->text()!="")
    {
        ui->pushCusInsert->setEnabled(TRUE);
    }
    else
        ui->pushCusInsert->setEnabled(FALSE);
}

void customer::insert_customer()
{
    qDebug()<<"M";
    QSqlQuery query(*db1);
    if (mode==1)
    {
        query.exec("UPDATE customers SET name='"+ui->lineEdit->text()+"' where id="+cusid);
        query.exec("UPDATE customers SET email1='"+ui->lineEmail1->text()+"' where id="+cusid);
        query.exec("UPDATE customers SET email2='"+ui->lineEmail2->text()+"' where id="+cusid);
        query.exec("UPDATE customers SET phone='"+ui->linePhone->text()+"' where id="+cusid);
        if (ui->checkActive->checkState()==Qt::Unchecked)
            query.exec("UPDATE customers SET active=0 where id="+cusid);
        else
            query.exec("UPDATE customers SET active=1 where id="+cusid);
        ui->pushCusInsert->setEnabled(FALSE);

    }

    if (mode==0)
    {
        query.exec("INSERT INTO customers (name,email1,email2,active,phone) VALUES ('"+ui->lineEdit->text()+"','"+ui->lineEmail1->text()+"','"+ui->lineEmail2->text()+"',1,'"+ui->linePhone->text()+"')");
        mode=1;
        ui->pushAddDebit->setEnabled(TRUE);
        ui->pushCusInsert->setEnabled(FALSE);
        ui->pushDeleteDebit->setEnabled(TRUE);
        ui->pushEditDebit->setEnabled(TRUE);

        query.exec("SELECT max(id) FROM customers");
        query.next();
        this->cusid=query.value(0).toString();
    }
    emit main_customers_refresh();

}

void customer::refresh_sql()
{
    QSqlQuery query(*db1);
    query.exec("SELECT p.description,d.amount from debit_categories d,places p where p.id=d.placeid and d.cusid="+cusid);
    QSqlQueryModel *m=new QSqlQueryModel();
    m->setQuery(query);
    ui->tableView->setModel(m);
}

void customer::insert_debit_type()
{
    debit_types *w=new debit_types(this,db1,0,cusid);
    w->show();
    connect(w,SIGNAL(refresh_table()),this,SLOT(refresh_sql()));
}

void customer::check_clicked()
{
    ui->pushCusInsert->setEnabled(TRUE);
}


void customer::cancel_clicked()
{
    delete(this);
}
