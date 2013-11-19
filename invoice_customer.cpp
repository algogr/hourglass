#include "invoice_customer.h"
#include "ui_invoice_customer.h"
#include "checkboxdelegate.h"

invoice_customer::invoice_customer(QWidget *parent,QSqlDatabase *db1,QString cusid) :
    QDialog(parent),
    ui(new Ui::invoice_customer)
{
    //QStringList to;
    //to.append("jimpar@algo.gr");
    //MailSender test1("192.168.2.251","jimpar@algo.gr",to, "simerina", "φσδκξ");
    //test1.setPriority(MailSender::high);
    //test1.send();
    //send(test1);

    //Smtp *newMail  = new Smtp("jimpar@algo.gr","jimpar@algo.gr"," ΚαλαYour Subject","Και καλαMy body text");
    //delete(newMail);

    ui->setupUi(this);

    QIcon* icon =new QIcon((QString)APATH+"invoice.png");
    ui->pushInvoice->setFocusPolicy(Qt::NoFocus);
    ui->pushInvoice->setEnabled(FALSE);
    ui->pushInvoice->setIcon(*icon);

    ui->pushInvoice->setIconSize(QSize( ui->pushInvoice->size().width()-5,ui->pushInvoice->size().height()-5 ));
    this->db1=db1;
    this->cusid=cusid;

    tasks_model=new chechkablesqlquerymodel(0,db1);

    tasks_model_2=new QSqlQueryModel;
    tasks_model_3=new QSqlQueryModel;
    tasks_model_4=new QSqlQueryModel;
    QSqlQuery query(*db1);
    query.exec("select name from customers where id="+cusid);
    query.next();
    QPalette *palette=new QPalette();
    palette->setColor(QPalette::WindowText,Qt::green);
    ui->lcdAtimol->setPalette(*palette);
    QPalette *palette1=new QPalette();
    palette1->setColor(QPalette::WindowText,Qt::red);
    ui->lcdTimol->setPalette(*palette1);
    ui->label->setText(query.value(0).toString());
    ui->dateEdit->setEnabled(FALSE);
    ui->dateEdit_2->setEnabled(FALSE);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());

    connect(ui->checkBox,SIGNAL(released()),this,SLOT(check_clicked()));
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(date_from()));
    connect(ui->dateEdit_2,SIGNAL(dateChanged(QDate)),this,SLOT(date_to()));
    connect(ui->pushInvoice,SIGNAL(released()),this,SLOT(create_invoice()));


    refresh_tasks_analytic();
    refresh_tasks_summary();
    refresh_tasks_full();
    refresh_tasks_projects();

}

invoice_customer::~invoice_customer()
{
    delete ui;
}

void invoice_customer::refresh_tasks_analytic()
{
    QSqlQuery query(*db1);
    QDate da;
    da=QDate::currentDate();
    da.toString("yy/M/dd");
    if(ui->checkBox->checkState()==Qt::Unchecked)
        //query.exec("select t.id,t.invoice as "+trUtf8("ΤΙΜΟΛΟΓΗΣΗ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %h:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %h:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+",s.description as "+trUtf8("PROJECT")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id where t.invoice=0 and t.cusid="+cusid+" order by t.start_time");
        query.exec("select t.id,t.invoice as "+trUtf8("ΤΙΜΟΛΟΓΗΣΗ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join places p on t.placeid=p.id where t.projectid is null and t.invoice=0 and t.cusid="+cusid+" order by t.start_time");
    else
        //query.exec("select t.id,t.invoice as "+trUtf8("ΤΙΜΟΛΟΓΗΣΗ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %h:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time'%d/%m/%Y %h:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+",s.description as "+trUtf8("PROJECT")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id where t.invoice=0 and t.cusid="+cusid+" and date(start_time)>='"+ui->dateEdit->date().toString("yy/M/d")+"' and date(start_time)<='"+ui->dateEdit_2->date().toString("yy/M/d")+"' order by t.start_time");
        query.exec("select t.id,t.invoice as "+trUtf8("ΤΙΜΟΛΟΓΗΣΗ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time'%d/%m/%Y %H:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join places p on t.placeid=p.id where t.projectid is null and t.invoice=0 and t.cusid="+cusid+" and date(start_time)>='"+ui->dateEdit->date().toString("yy/M/d")+"' and date(start_time)<='"+ui->dateEdit_2->date().toString("yy/M/d")+"' order by t.start_time");
    if (query.size()>0)
    {
        tasks_model->setQuery(query);


        //for (int i=0;i<query.size();++i)
        //{
            //tasks_model->setData(tasks_model->index(i, 1), "Y", Qt::CheckStateRole);


        //}


        ui->tableView->setModel(tasks_model);


        CheckBoxDelegate*delegate =new CheckBoxDelegate(this);
        ui->tableView->setItemDelegate(delegate);
        connect(delegate,SIGNAL(editor_changed_state(bool,QModelIndex)),this,SLOT(editor_changed(bool,QModelIndex)));
        connect(delegate,SIGNAL(editor_spin_value(int,QModelIndex)),this,SLOT(editor_spin_changed(int,QModelIndex)));
        for (int i=0; i<tasks_model->rowCount(); i++)
        {
         ui->tableView->openPersistentEditor(tasks_model->index(i, 1, QModelIndex()));
         ui->tableView->openPersistentEditor(tasks_model->index(i, 6, QModelIndex()));
        }


        //ui->tableView->setModel(tasks_model);
        ui->tableView->resizeColumnToContents(0);
        ui->tableView->resizeColumnToContents(1);
        ui->tableView->resizeColumnToContents(2);
        ui->tableView->resizeColumnToContents(3);
        ui->tableView->resizeColumnToContents(4);
        ui->tableView->resizeColumnToContents(5);
        ui->tableView->resizeColumnToContents(6);
        ui->tableView->resizeColumnToContents(7);
        //ui->tableView->resizeColumnToContents(8);
        ui->tableView->hideColumn(0);
        //ui->tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
        ui->tableView->setAlternatingRowColors(true);
        //ui->tableView->scrollToBottom();
        //ui->tableView->setColumnHidden(0,TRUE);
        ui->tableView->setEditTriggers(QAbstractItemView::SelectedClicked);
    }
    qDebug()<<"1";
}

void invoice_customer::check_clicked()
{
    if(ui->checkBox->checkState()==Qt::Checked)
    {
        ui->dateEdit->setEnabled(TRUE);
        ui->dateEdit_2->setEnabled(TRUE);
    }
    else
    {
        ui->dateEdit->setEnabled(FALSE);
        ui->dateEdit_2->setEnabled(FALSE);
        refresh_tasks_analytic();
        refresh_tasks_summary();
        refresh_tasks_full();

    }
}

void invoice_customer::refresh_tasks_summary()
{
    QSqlQuery query(*db1);
    if(ui->checkBox->checkState()==Qt::Unchecked)
        query.exec("select p.description as "+trUtf8("ΤΟΠΟΣ")+",sum(TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time)) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+" from tasks t, places p where t.placeid=p.id and t.projectid is null and t.invoice=0 and t.cusid="+cusid+" group by p.description");
    else
        query.exec("select p.description as "+trUtf8("ΤΟΠΟΣ")+",sum(TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time)) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+" from tasks t, places p where t.placeid=p.id and t.projectid is null and t.invoice=0 and t.cusid="+cusid+" and date(start_time)>'"+ui->dateEdit->date().toString("yy/M/d")+"' and date(start_time)<='"+ui->dateEdit_2->date().toString("yy/M/d")+"' group by p.description");
    if (query.size()>0)
    {
        tasks_model_2->setQuery(query);


        //for (int i=0;i<query.size();++i)
        //{
            //tasks_model->setData(tasks_model->index(i, 1), "Y", Qt::CheckStateRole);


        //}


        ui->tableView_2->setModel(tasks_model_2);


        //CheckBoxDelegate*delegate =new CheckBoxDelegate(this);
        //ui->tableView->setItemDelegate(delegate);
        //for (int i=0; i<tasks_model->rowCount(); i++)
        //{
         //ui->tableView->openPersistentEditor(tasks_model->index(i, 1, QModelIndex()));
         //ui->tableView->openPersistentEditor(tasks_model->index(i, 6, QModelIndex()));
        //}
        //ui->tableView->setModel(tasks_model);
        ui->tableView->resizeColumnToContents(0);
        ui->tableView->resizeColumnToContents(1);
        //ui->tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
        ui->tableView->setAlternatingRowColors(true);
        //ui->tableView->scrollToBottom();
        //ui->tableView->setColumnHidden(0,TRUE);
        //ui->tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
        int ores=0;
        while(query.next())
        {
            ores+=query.value(1).toInt();
            QVariant ores1=ores;
            qDebug()<<"ORES"<<ores;
            ui->lcdAtimol->display(ores1.toString());
        }

    }

}

void invoice_customer::refresh_tasks_full()
{
    QSqlQuery query(*db1);
    if(ui->checkBox->checkState()==Qt::Unchecked)
        query.exec("select t.id,t.invoice as "+trUtf8("ΤΙΜΟΛΟΓΗΣΗ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+",s.description as "+trUtf8("PROJECT")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id where t.cusid="+cusid+" order by t.start_time");
    else
        query.exec("select t.id,t.invoice as "+trUtf8("ΤΙΜΟΛΟΓΗΣΗ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+",s.description as "+trUtf8("PROJECT")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id where t.cusid="+cusid+" and date(start_time)>='"+ui->dateEdit->date().toString("yy/M/d")+"' and date(start_time)<='"+ui->dateEdit_2->date().toString("yy/M/d")+"' order by t.start_time");
    if (query.size()>0)
    {
        tasks_model_3->setQuery(query);


        //for (int i=0;i<query.size();++i)
        //{
            //tasks_model->setData(tasks_model->index(i, 1), "Y", Qt::CheckStateRole);


        //}


        ui->tableView_3->setModel(tasks_model_3);


        CheckBoxDelegate*delegate =new CheckBoxDelegate(this);
        ui->tableView_3->setItemDelegate(delegate);

        for (int i=0; i<tasks_model_3->rowCount(); i++)
        {
         ui->tableView_3->openPersistentEditor(tasks_model_3->index(i, 1, QModelIndex()));
         ui->tableView_3->openPersistentEditor(tasks_model_3->index(i, 6, QModelIndex()));
        }

        //ui->tableView->setModel(tasks_model);
        ui->tableView_3->resizeColumnToContents(0);
        ui->tableView_3->resizeColumnToContents(1);
        ui->tableView_3->resizeColumnToContents(2);
        ui->tableView_3->resizeColumnToContents(3);
        ui->tableView_3->resizeColumnToContents(4);
        ui->tableView_3->resizeColumnToContents(5);
        ui->tableView_3->resizeColumnToContents(6);
        ui->tableView_3->resizeColumnToContents(7);
        ui->tableView_3->resizeColumnToContents(8);
        ui->tableView_3->hideColumn(0);
        //ui->tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
        ui->tableView->setEditTriggers(QAbstractItemView::SelectedClicked);
        ui->tableView_3->setAlternatingRowColors(true);
        //ui->tableView->scrollToBottom();
        //ui->tableView->setColumnHidden(0,TRUE);
        //ui->tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    }

}

void invoice_customer::refresh_tasks_projects()
{


    QSqlQuery query(*db1);
    if(ui->checkBox->checkState()==Qt::Unchecked)
        query.exec("select t.id,p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+",s.description as "+trUtf8("PROJECT")+" from tasks t ,subprojects s,places p  where t.placeid=p.id  and t.projectid=s.id and t.cusid="+cusid+" order by t.start_time");
    else
        query.exec("select t.id,p.description as "+trUtf8("ΤΟΠΟΣ")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+",s.description as "+trUtf8("PROJECT")+" from tasks t ,subprojects s,places p  where t.placeid=p.id and t.projectid=s.id and t.cusid="+cusid+" and date(start_time)>='"+ui->dateEdit->date().toString("yy/M/d")+"' and date(start_time)<='"+ui->dateEdit_2->date().toString("yy/M/d")+"' order by t.start_time");
    if (query.size()>0)
    {
        tasks_model_4->setQuery(query);


        //for (int i=0;i<query.size();++i)
        //{
            //tasks_model->setData(tasks_model->index(i, 1), "Y", Qt::CheckStateRole);


        //}


        ui->tableView_4->setModel(tasks_model_4);


        //CheckBoxDelegate*delegate =new CheckBoxDelegate(this);
        //ui->tableView_3->setItemDelegate(delegate);

        //for (int i=0; i<tasks_model_3->rowCount(); i++)
        //{
        // ui->tableView_3->openPersistentEditor(tasks_model_3->index(i, 1, QModelIndex()));
         //ui->tableView_3->openPersistentEditor(tasks_model_3->index(i, 6, QModelIndex()));
        //}

        //ui->tableView->setModel(tasks_model);
        ui->tableView_4->resizeColumnToContents(0);
        ui->tableView_4->resizeColumnToContents(1);
        ui->tableView_4->resizeColumnToContents(2);
        ui->tableView_4->resizeColumnToContents(3);
        ui->tableView_4->resizeColumnToContents(4);
        ui->tableView_4->resizeColumnToContents(5);
        ui->tableView_4->resizeColumnToContents(6);
        ui->tableView_4->resizeColumnToContents(7);
        //ui->tableView_4->resizeColumnToContents(8);
        ui->tableView_4->hideColumn(0);
        //ui->tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
        //ui->tableView->setEditTriggers(QAbstractItemView::SelectedClicked);
        ui->tableView_4->setAlternatingRowColors(true);
        //ui->tableView->scrollToBottom();
        //ui->tableView->setColumnHidden(0,TRUE);
        //ui->tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    }


}


void invoice_customer::date_from()
{
    qDebug()<<"DATAF";
    refresh_tasks_analytic();
    refresh_tasks_summary();
    refresh_tasks_full();
    refresh_tasks_projects();
}

void invoice_customer::date_to()
{
    qDebug()<<"DATAT";
    refresh_tasks_analytic();
    refresh_tasks_summary();
    refresh_tasks_full();
    refresh_tasks_projects();
}




void::invoice_customer::editor_changed(bool state, const QModelIndex &index)

{
    ui->pushInvoice->setEnabled(TRUE);

    int v=ui->lcdTimol->value();
    int v1=tasks_model->data(tasks_model->index(index.row(),3),Qt::DisplayRole).toInt();
    int va=ui->lcdAjia->value();
    int va2;
    qDebug()<<spins;
    if (spins.contains(index.row()))
    {
        qDebug()<<"NAI YPARXEI";
        va2=spins.value(index.row());
    }
    else
        va2=tasks_model->data(tasks_model->index(index.row(),6),Qt::EditRole).toInt();
    qDebug()<<"VA2"<<va2;
    qDebug()<<"STATE"<<v1;
    if (state==TRUE)
    {
       checks[index.row()]=1;
       v=v+v1;
       va=va+(v1*va2/60);
    }
    else
    {
       checks[index.row()]=0;
       v=v-v1;
       va=va-(v1*va2/60);
    }

    ui->lcdTimol->display(v);
    ui->lcdAjia->display(va);

}

void::invoice_customer::editor_spin_changed(int value, const QModelIndex &index)

{
    spins[index.row()]=value;

    int v=ui->lcdAjia->value();
    int v1=tasks_model->data(tasks_model->index(index.row(),3),Qt::EditRole).toInt();
    int va2;
    if (checks.contains(index.row()))
        va2=checks.value(index.row());
    else
        return;
    qDebug()<<"VA2"<<va2;
    qDebug()<<"STATE"<<v1;
    if (va2==1)
    {
       v=v+(v1*value/60);
    }
    else
    {
       v=v-(v1*value/60);
    }

    ui->lcdAjia->display(v);



}


void invoice_customer::create_invoice()
{
    QHashIterator<int,int> invoice(checks);
    QSqlQuery query(*db1);
    query.exec("insert into fintrade (ftrdate,cusid) values (current_date(),"+cusid+")");
    query.exec("select max(id) from fintrade");
    query.next();
    QString ftrid=query.value(0).toString();
    QString t_id,placeid,comment,taskdate,price;
    QVariant minutes;
    while (invoice.hasNext())
    {
        invoice.next();
        t_id=tasks_model->data(tasks_model->index(invoice.key(),0),Qt::DisplayRole).toString();
        query.exec("select placeid,date(start_time),comment,TIMESTAMPDIFF(MINUTE,start_time,end_time) from tasks where id="+t_id);
        query.exec();
        query.next();
        placeid=query.value(0).toString();
        comment=query.value(2).toString();
        taskdate=query.value(1).toString();
        minutes=query.value(3).toFloat()/60;
        price=tasks_model->data(tasks_model->index(invoice.key(),6),Qt::EditRole).toString();
        query.exec("insert into storetradelines (ftrid,taskid,placeid,comment,task_date,hours,price) values ("+ftrid+","+t_id+","+placeid+",'"+comment+"','"+taskdate+"',"+minutes.toString()+","+price+")");

    }
    QHashIterator<int, int> i(checks);
     while (i.hasNext())
     {
         i.next();
         tasks_model->setData(tasks_model->index(i.key(),1,QModelIndex()),i.value(),Qt::EditRole);

     }
     QHashIterator<int, int> j(spins);

      while (j.hasNext())
      {
          j.next();
          tasks_model->setData(tasks_model->index(j.key(),6,QModelIndex()),j.value(),Qt::EditRole);

      }



}


