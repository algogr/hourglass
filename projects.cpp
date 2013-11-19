#include "projects.h"
#include "ui_projects.h"
#include "constants.h"

Projects::Projects(QWidget *parent,QSqlDatabase *db1,int mode,int pid) :
    QDialog(parent),
    ui(new Ui::Projects)
{
    QVariant t_pid=pid;
    this->pid=t_pid.toString();
    ui->setupUi(this);
    QIcon* icon =new QIcon((QString)APATH+"add.jpg");
    ui->pushInsert->setIcon(*icon);
    ui->pushInsert->setIconSize(QSize( ui->pushInsert->size().width()-5,ui->pushInsert->size().height()-5 ));
    QIcon* icon1 =new QIcon((QString)APATH+"cancel.png");
    ui->pushCancel->setIcon(*icon1);
    ui->pushCancel->setIconSize(QSize( ui->pushCancel->size().width()-5,ui->pushCancel->size().height()-5 ));
    this->db1=db1;
    this->mode=mode;
    model=new QSqlQueryModel;
    QSqlQuery query(*db1);
    query.exec("select id,name from customers order by name");
    model->setQuery(query);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(1);
    if (mode==1)
    {
        /*
        for (int i=0;i<ui->comboCustomer->count();++i)
        {
            ui->comboCustomer->setCurrentIndex(i);

            if (customermodel->data(customermodel->index(ui->comboCustomer->currentIndex(),0))==testid)


                break;
        }
          */
        query.exec("select cusid,description,fee from subprojects where id="+this->pid);
        query.next();
        for (int i=0;i<ui->comboBox->count();++i)
        {
            ui->comboBox->setCurrentIndex(i);

            if (model->data(model->index(ui->comboBox->currentIndex(),0)).toInt()==query.value(0).toInt())
            {
                break;
            }
            ui->lineEdit->setText(query.value(1).toString());
            ui->spinBox->setValue(query.value(2).toInt());
        }
    }

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(customer_changed()));
    connect(ui->pushInsert,SIGNAL(released()),this,SLOT(insert()));
    connect(ui->pushCancel,SIGNAL(released()),this,SLOT(cancel()));

}

Projects::~Projects()
{
    delete ui;
}


void Projects::customer_changed()
{
    cusid=model->data(model->index(ui->comboBox->currentIndex(),0)).toString();


}

void Projects::insert()
{
    QSqlQuery query(*db1);
    QVariant v=ui->spinBox->value();
    switch (mode)
    {
        case 0:
            query.exec("insert into subprojects (cusid,description,fee) values ("+cusid+",'"+ui->lineEdit->text()+"',"+v.toString()+")");
            break;

        case 1:
            query.exec("update subprojects set cusid="+cusid+" where id="+pid);
            query.exec("update subprojects set description='"+ui->lineEdit->text()+"' where id="+pid);
            query.exec("update subprojects set fee="+v.toString()+" where id="+pid);
            break;
    }
    emit data_changed();
    delete (this);
}

void Projects::cancel()
{
    delete(this);
}

