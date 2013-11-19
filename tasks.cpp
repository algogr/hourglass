#include "tasks.h"
#include "ui_tasks.h"

tasks::tasks(QWidget *parent,QSqlDatabase* db1,QString task_id,int mode) :
    QDialog(parent),
    ui(new Ui::tasks)
{
    ui->setupUi(this);
    connect(ui->comboCustomer,SIGNAL(currentIndexChanged(int)),this,SLOT(set_customer()));

    QIcon* icon =new QIcon((QString)APATH+"ok.png");
    QIcon* icon1 =new QIcon((QString)APATH+"cancel.png");
    ui->pushOK->setIcon(*icon);
    ui->pushCancel->setIcon(*icon1);
    ui->pushOK->setIconSize(QSize( ui->pushOK->size().width()-5,ui->pushOK->size().height()-5 ));
    ui->pushCancel->setIconSize(QSize( ui->pushCancel->size().width()-5,ui->pushCancel->size().height()-5 ));
    ui->lineDebit->setText("0");
    this->db1=db1;
    this->task_id=task_id;
    this->mode=mode;
    this->customermodel=new QSqlQueryModel;
    this->placesmodel=new QSqlQueryModel;
    this->projectmodel=new QSqlQueryModel;
    ui->pushOK->setFocusPolicy(Qt::NoFocus);
    ui->pushCancel->setFocusPolicy(Qt::NoFocus);
    populate_customers();
    populate_places();
    populate_projects();
    ui->comboProject->setCurrentIndex(-1);
    QSqlQuery query(*db1);
    if (mode==1)
    {
        query.exec("select cusid,placeid,projectid,comment,start_time,end_time,price from tasks where id="+task_id);
        query.next();
        int testid=query.value(0).toInt();
        for (int i=0;i<ui->comboCustomer->count();++i)
        {
            ui->comboCustomer->setCurrentIndex(i);

            if (customermodel->data(customermodel->index(ui->comboCustomer->currentIndex(),0))==testid)


                break;
        }
        testid=query.value(1).toInt();

        for (int i=0;i<ui->comboPlace->count();++i)
        {
            ui->comboPlace->setCurrentIndex(i);

            if (placesmodel->data(placesmodel->index(ui->comboPlace->currentIndex(),0))==testid)

                break;

        }

        testid=query.value(2).toInt();
        for (int i=0;i<ui->comboProject->count();++i)
        {
            ui->comboProject->setCurrentIndex(i);
            if (projectmodel->data(projectmodel->index(ui->comboProject->currentIndex(),0))==testid)


                break;
            else
                ui->comboProject->setCurrentIndex(-1);
        }

        ui->textEdit->setPlainText(query.value(3).toString());
        ui->dateTimeStart->setDateTime(query.value(4).toDateTime());
        ui->dateTimeStop->setDateTime(query.value(5).toDateTime());
        ui->lineDebit->setText(query.value(6).toString());
    }
    if (mode==0)
    {
        ui->dateTimeStart->setDateTime(QDateTime::currentDateTime());
        ui->dateTimeStop->setDateTime(QDateTime::currentDateTime());
    }
    connect(ui->pushOK,SIGNAL(released()),this,SLOT(ok_pressed()));
    connect(ui->pushCancel,SIGNAL(released()),this,SLOT(cancel_pressed()));
    connect(ui->dateTimeStop,SIGNAL(dateTimeChanged(QDateTime)),this,SLOT(stop_time_changed()));
}

tasks::~tasks()
{
    delete ui;
}

void tasks::populate_customers()
{
    QSqlQuery query(*db1);
    query.exec("select id,name from customers order by name");
    customermodel->setQuery(query);
    ui->comboCustomer->setModel(customermodel);
    ui->comboCustomer->setModelColumn(1);

}

void tasks::populate_places()
{
    QSqlQuery query(*db1);
    query.exec("select p.id,p.description from debit_categories d,places p where d.placeid=p.id and d.cusid="+cusid);
    //query.exec("select id,description from places");
    placesmodel->setQuery(query);
    ui->comboPlace->setModel(placesmodel);
    ui->comboPlace->setModelColumn(1);
}

void tasks::populate_projects()
{
    QSqlQuery query(*db1);
    query.exec("select id,description from subprojects where cusid="+cusid);
    //query.exec("select id,description from subprojects");
    projectmodel->setQuery(query);
    ui->comboProject->setModel(projectmodel);
    ui->comboProject->setModelColumn(1);

}

void tasks::set_customer()
{
    this->cusid=customermodel->data(customermodel->index(ui->comboCustomer->currentIndex(),0)).toString();
    populate_places();
    populate_projects();
    if (mode==0)
        ui->comboProject->setCurrentIndex(-1);
}

void tasks::ok_pressed()
{
    QSqlQuery query(*db1);
    QString placesid,projectid;
    if (ui->comboPlace->currentIndex() !=-1)
        placesid=placesmodel->data(placesmodel->index(ui->comboPlace->currentIndex(),0)).toString();
    else
        placesid="NULL";
    if (ui->comboProject->currentIndex()!=-1)
        projectid=projectmodel->data(projectmodel->index(ui->comboProject->currentIndex(),0)).toString();
    else
        projectid="NULL";

    if (mode==1)
    {
        query.exec("update tasks set cusid="+this->cusid+" where id="+task_id);
        query.exec("update tasks set placeid="+placesid+" where id="+task_id);
        query.exec("update tasks set projectid="+projectid+" where id="+task_id);
        query.exec("update tasks set comment='"+ui->textEdit->toPlainText()+"' where id="+task_id);
        query.exec("update tasks set start_time='"+ui->dateTimeStart->dateTime().toString("yy/M/d hh:mm")+"' where id="+task_id);
        query.exec("update tasks set end_time='"+ui->dateTimeStop->dateTime().toString("yy/M/d hh:mm")+"' where id="+task_id);
        query.exec("update tasks set price="+ui->lineDebit->text()+" where id="+task_id);
        emit refresh_tasks();
        delete(this);
    }
    if (mode==0)
    {

        query.exec("insert into tasks(cusid,placeid,projectid,comment,start_time,end_time,price) VALUES ("+cusid+","+placesid+","+projectid+",'"+ui->textEdit->toPlainText()+"','"+ui->dateTimeStart->dateTime().toString("yy/M/d hh:mm")+"','"+ui->dateTimeStop->dateTime().toString("yy/M/d hh:mm")+"',"+ui->lineDebit->text()+")");
        emit refresh_tasks();
        delete(this);
    }
}

void tasks::cancel_pressed()
{
    delete(this);
}

void tasks::stop_time_changed()
{
    qDebug()<<"NAII";
    if (ui->dateTimeStop->dateTime()<ui->dateTimeStart->dateTime())
    {
        qDebug()<<"NAII 1";
        QMessageBox::critical(this, qApp->tr("Προσοχή"), qApp->trUtf8("H ώρα λήξης είναι προγενέστερη της ώρας έναρξης."));
        ui->dateTimeStop->setDateTime(ui->dateTimeStart->dateTime());
        ui->dateTimeStop->setFocus();
        return;
    }
}
