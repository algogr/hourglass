#include "incoming_call.h"
#include "ui_incoming_call.h"

Incoming_Call::Incoming_Call(QWidget *parent,QSqlDatabase *db1,QString phonebookid,QString phoneno) :
    QDialog(parent),
    ui(new Ui::Incoming_Call)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    this->db1=db1;
    QIcon* icon =new QIcon((QString)APATH+"ok.png");
    ui->pushOk->setIcon(*icon);
    ui->pushOk->setIconSize(QSize( ui->pushOk->size().width()-5,ui->pushOk->size().height()-5 ));
    QIcon* icon1 =new QIcon((QString)APATH+"cancel.png");
    ui->pushDismiss->setIcon(*icon1);
    ui->pushDismiss->setIconSize(QSize( ui->pushDismiss->size().width()-5,ui->pushDismiss->size().height()-5 ));
    QSqlQuery query(*this->db1);
    this->phonebookid=phonebookid;
    this->phoneno=phoneno;
    ui->labelPhone->setText(phoneno);
    edit=TRUE;
    customer_model=new QSqlQueryModel;

    query.exec("select id,name from customers");
    customer_model->setQuery(query);
    ui->comboBox->setModel(customer_model);
    ui->comboBox->setModelColumn(1);
    ui->comboBox->setCurrentIndex(-1);
    if (this->phonebookid=="")
    {

        edit=FALSE;
    }
    else
    {
        query.exec("select cusid from phonebook where id="+this->phonebookid);
        query.next();
        this->cusid=query.value(0).toString();
    }

    if (cusid!="")
    {
        for (int i=0;i<ui->comboBox->count();++i)
        {
            ui->comboBox->setCurrentIndex(i);

            if (customer_model->data(customer_model->index(ui->comboBox->currentIndex(),0)).toString()==cusid)


                break;
        }
    }

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(customer_changed()));
    connect(ui->pushOk,SIGNAL(released()),this,SLOT(ok_pushed()));
    connect(ui->pushDismiss,SIGNAL(released()),this,SLOT(dismiss_pushed()));
    if (edit)
        ui->pushOk->setVisible(FALSE);

    ui->pushOk->setFocusPolicy(Qt::NoFocus);
    ui->pushDismiss->setFocusPolicy(Qt::NoFocus);

}

Incoming_Call::~Incoming_Call()
{
    delete ui;
}


void Incoming_Call::customer_changed()
{
    ui->pushOk->setVisible(TRUE);
    cusid=customer_model->data(customer_model->index(ui->comboBox->currentIndex(),0)).toString();

}


void Incoming_Call::dismiss_pushed()
{
    delete(this);
}

void Incoming_Call::ok_pushed()
{
    QSqlQuery query(*db1);
    if (!edit)
        query.exec("insert into phonebook (cusid,phoneno) values ('"+cusid+"','"+phoneno+"')");
    else
        query.exec("update phonebook set cusid="+cusid+" where id="+phonebookid);
    delete(this);

}
