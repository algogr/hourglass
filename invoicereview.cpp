#include "invoicereview.h"
#include "ui_invoicereview.h"
#include "mailsender.h"

InvoiceReview::InvoiceReview(QWidget *parent,QSqlDatabase *db1) :
    QDialog(parent),
    ui(new Ui::InvoiceReview)
{
    ui->setupUi(this);
    QIcon* icon =new QIcon((QString)APATH+"delete.png");
    ui->pushDelete->setIcon(*icon);
    ui->pushDelete->setIconSize(QSize( ui->pushDelete->size().width()-5,ui->pushDelete->size().height()-5 ));
    QIcon* icon1 =new QIcon((QString)APATH+"mail.png");
    ui->pushEmail->setIcon(*icon1);
    ui->pushEmail->setIconSize(QSize( ui->pushEmail->size().width()-5,ui->pushEmail->size().height()-5 ));
    //ui->pushDelete->setIconSize(QSize(ui->pushDelete->size.Width(),ui->pushDelete->size.Height()));
    this->db1=db1;
    this->fintrade_model=new QSqlQueryModel();
    this->lines_model=new QSqlQueryModel();

    ui->dateFrom->setDate(QDate::currentDate());
    ui->dateTo->setDate(QDate::currentDate());
    ui->pushDelete->setFocusPolicy(Qt::NoFocus);
    ui->pushEmail->setFocusPolicy(Qt::NoFocus);
    refresh_fintrade();
    refresh_lines();
    //ui->tableFintrade->setEnabled(TRUE);
    //ui->tableFintrade->setCurrentIndex(0,0);
    connect(ui->tableFintrade,SIGNAL(clicked(QModelIndex)),this,SLOT(invoice_changed()));
    connect(ui->dateFrom,SIGNAL(dateChanged(QDate)),this,SLOT(date_changed()));
    connect(ui->dateTo,SIGNAL(dateChanged(QDate)),this,SLOT(date_changed()));
    connect(ui->pushDelete,SIGNAL(released()),this,SLOT(delete_pressed()));
    connect(ui->pushEmail,SIGNAL(released()),this,SLOT(email_pressed()));
}

InvoiceReview::~InvoiceReview()
{
    delete ui;
}

void InvoiceReview::refresh_fintrade()
{
    QSqlQuery query(*db1);
    QString date_from=ui->dateFrom->date().toString("yy/MM/dd");
    QString date_to=ui->dateTo->date().toString("yy/MM/dd");
    query.exec("select f.id,date_format(f.ftrdate,'%d/%m/%Y') as "+trUtf8("ΗΜΕΡΟΜΗΝΙΑ")+",c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",(select sum(hours*price) from storetradelines where ftrid=f.id) as "+trUtf8("ΑΞΙΑ")+" from fintrade f,customers c where c.id=f.cusid and date(f.ftrdate)>='"+date_from+"' and date(f.ftrdate) <='"+date_to+"'");
    fintrade_model->setQuery(query);
    ui->tableFintrade->setModel(fintrade_model);
    ui->tableFintrade->resizeColumnToContents(1);
    ui->tableFintrade->resizeColumnToContents(2);
    ui->tableFintrade->resizeColumnToContents(3);
    ui->tableFintrade->hideColumn(0);
    ui->tableFintrade->setAlternatingRowColors(true);

}



void InvoiceReview::refresh_lines()
{
    QSqlQuery query(*db1);

    QString ftrid=fintrade_model->data(fintrade_model->index(ui->tableFintrade->currentIndex().row(),0)).toString();

    //customer_model->data(customer_model->index(ui->tableCustomers->currentIndex().row(),0)).toString();
    query.exec("select date_format(s.task_date,'%d/%m/%Y') as "+trUtf8("HMEΡΟΜΗΝΙΑ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",hours as "+trUtf8("ΩΡΕΣ")+",price as "+trUtf8("ΤΙΜΗ")+",price*hours as "+trUtf8("ΑΞΙΑ")+",comment as "+trUtf8("ΣΧΟΛΙΑ")+" from storetradelines s,places p where s.placeid=p.id and ftrid="+ftrid);
    lines_model->setQuery(query);
    ui->tableLines->setModel(lines_model);
    ui->tableLines->resizeColumnToContents(0);
    ui->tableLines->resizeColumnToContents(1);
    ui->tableLines->resizeColumnToContents(2);
    ui->tableLines->resizeColumnToContents(3);
    ui->tableLines->resizeColumnToContents(4);
    ui->tableLines->setAlternatingRowColors(true);
}

void InvoiceReview::invoice_changed()
{
    refresh_lines();
}

void InvoiceReview::date_changed()
{
    refresh_fintrade();
    refresh_lines();
}

void InvoiceReview::delete_pressed()
{
    QSqlQuery query(*db1),query1(*db1);
    QString ftrid=fintrade_model->data(fintrade_model->index(ui->tableFintrade->currentIndex().row(),0)).toString();
    query1.exec("select taskid from storetradelines where ftrid="+ftrid);
    while (query1.next())
    {
        query.exec("update tasks set invoice=0 where id="+query1.value(0).toString());

    }
    query.exec("delete from storetradelines where ftrid="+ftrid);
    query.exec("delete from fintrade where id="+ftrid);
    refresh_fintrade();

}

void InvoiceReview::email_pressed()
{
    QString from=g_MAIL_FROM;
    QString to=g_MAIL_INVOICER;
    QString subject="INVOICES";
    QString body,ftrid;
    QSqlQuery query(*db1);

    for (int i=0;i<fintrade_model->rowCount();++i)
    {
        ftrid=fintrade_model->data(fintrade_model->index(i,0)).toString();
        query.exec("select c.name from customers c,fintrade f where f.cusid=c.id and f.id="+ftrid);
        query.next();
        body.append(tr("ΠΕΛΑΤΗΣ:"+query.value(0).toString().toUtf8())+"\n");
        query.exec("select p.description,sum(s.hours),sum(s.hours*s.price) from storetradelines s,places p where p.id=s.placeid and ftrid="+ftrid+" group by p.description");
        while(query.next())
        {
            body.append(query.value(0).toString().toUtf8()+": "+tr("ΩΡΕΣ:")+query.value(1).toString()+"-"+tr("ΚΑΘΑΡΗ ΑΞΙΑ:")+query.value(2).toString()+"\n");
        }
        body.append("\n\n\n");

    }

    send_email(from,to,subject,body);
    delete (this);

}

void InvoiceReview::send_email(QString from,QString to,QString subject,QString body)
{
    QStringList to1;
    to1.append(to);
    to1.append(g_MAIL_FROM);
    MailSender test1(g_MAIL_SERVER,from,to1, subject, body);
    test1.setPriority(MailSender::high);
    test1.send();
    //delete(test1);
    //send(test1);
}
