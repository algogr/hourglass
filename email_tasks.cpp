#include "email_tasks.h"
#include "ui_email_tasks.h"
#include "mailsender.h"

Email_tasks::Email_tasks(QWidget *parent,QSqlDatabase *db1) :
    QDialog(parent),
    ui(new Ui::Email_tasks)
{
    ui->setupUi(this);
    this->db1=db1;
    ui->dateEditfrom->setDate(QDate::currentDate());
    ui->dateEditto->setDate(QDate::currentDate());
    QIcon* icon =new QIcon((QString)APATH+"mail.png");
    QIcon* icon1 =new QIcon((QString)APATH+"cancel.png");

    ui->pushSend->setIcon(*icon);
    ui->pushCancel->setIcon(*icon1);
    ui->pushSend->setIconSize(QSize( ui->pushSend->size().width()-5,ui->pushSend->size().height()-5 ));
    ui->pushCancel->setIconSize(QSize( ui->pushCancel->size().width()-5,ui->pushCancel->size().height()-5 ));
    ui->pushSend->setFocusPolicy(Qt::NoFocus);
    ui->pushCancel->setFocusPolicy(Qt::NoFocus);
    model=new QSqlQueryModel;
    refresh_table();
    connect (ui->dateEditfrom,SIGNAL(dateChanged(QDate)),this,SLOT(date_changed()));
    connect (ui->dateEditto,SIGNAL(dateChanged(QDate)),this,SLOT(date_changed()));
    connect (ui->pushSend,SIGNAL(released()),this,SLOT(prepare_emails()));
    connect (ui->pushCancel,SIGNAL(released()),this,SLOT(cancel_pressed()));
}

Email_tasks::~Email_tasks()
{
    delete ui;
}

void Email_tasks::refresh_table()
{
    QSqlQuery query(*db1);
    query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",c.email1 as "+trUtf8("EMAIL")+",date_format(start_time,'%d/%m/%Y') as "+trUtf8("HMΕΡΟΜΗΝΙΑ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t, places p, customers c where t.cusid=c.id and p.id=t.placeid and date(start_time)>='"+ui->dateEditfrom->date().toString("yy/M/d")+"' and date(end_time)<='"+ui->dateEditto->date().toString("yy/M/d")+"' and c.email1 <>'' order by c.name,t.start_time");
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnToContents(0);
    ui->tableView->resizeColumnToContents(1);
    ui->tableView->resizeColumnToContents(2);
    ui->tableView->resizeColumnToContents(3);
    ui->tableView->resizeColumnToContents(4);
    ui->tableView->resizeColumnToContents(5);
    ui->tableView->resizeColumnToContents(6);
    ui->tableView->resizeColumnToContents(7);
    ui->tableView->hideColumn(0);
}

void Email_tasks::date_changed()
{
    refresh_table();
}

void Email_tasks::prepare_emails()
{
    QString test_customer="";
    QString from=g_MAIL_FROM;
    QString subject="SERVICE REPORT";
    QString customer,email,body,task_date,topos,ores,duration,comment;

    for(int i=0;i<model->rowCount();++i)
    {
        customer=model->data(model->index(i,1,QModelIndex())).toString();
        email=model->data(model->index(i,2,QModelIndex())).toString();
        //email="dim_par@yahoo.gr";
        task_date=model->data(model->index(i,3,QModelIndex())).toString();
        topos=model->data(model->index(i,4,QModelIndex())).toString();
        ores=model->data(model->index(i,5,QModelIndex())).toString();
        duration=model->data(model->index(i,6,QModelIndex())).toString();
        comment=model->data(model->index(i,7,QModelIndex())).toString();

        if (test_customer!=customer)
        {
            if (i>0)
            {
                prepare_footer(body);
                send_email(from,email,subject,body);
            }

            //qDebug()<<body;
            body=tr("Εργασίες που έγιναν από ")+ui->dateEditfrom->date().toString("d/M/yy")+tr(" έως ")+ui->dateEditto->date().toString("d/M/yy")+":\n \n";
        }
        body.append(task_date.toUtf8()+" ");
        body.append(topos.toUtf8()+" ");
        body.append(ores+tr(" λεπτά "));
        body.append(comment.toUtf8()+"\n");
        test_customer=customer;



    }
    prepare_footer(body);
    send_email(from,email,subject,body);
    delete (this);
}

void Email_tasks::send_email(QString from,QString to,QString subject,QString body)
{
    QStringList to1;
    to1.append(to);
    MailSender test1(g_MAIL_SERVER,from,to1, subject, body);
    test1.setPriority(MailSender::high);
    test1.send();
    //delete(test1);
    //send(test1);
}

void  Email_tasks::prepare_footer(QString &body)
{
    body.append("\n \n");
    body.append(tr("Δημήτρης Παράσχου"));
    body.append("\n \n \n");
    body.append(tr("Σημείωση:ΕΝΤΟΣ σημαίνει ότι η εργασία έγινε απομακρυσμένα και ΕΚΤΟΣ στο χώρο του πελάτη"));

}

void Email_tasks::cancel_pressed()
{
    delete (this);
}
