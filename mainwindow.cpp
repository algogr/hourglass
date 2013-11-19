#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->tracking_status=FALSE;

    QIcon* icon =new QIcon((QString)APATH+"clock.png");
    ui->pushHour->setEnabled(FALSE);
    ui->pushHour->setIcon(*icon);
    ui->pushHour->setIconSize(QSize( ui->pushHour->size().width()-5,ui->pushHour->size().height()-5 ));
    QIcon* icon1 =new QIcon((QString)APATH+"add.png");
    ui->pushAddEarlier->setIcon(*icon1);
    ui->pushAddEarlier->setIconSize(QSize( ui->pushAddEarlier->size().width()-5,ui->pushAddEarlier->size().height()-5 ));
    QIcon* icon3 =new QIcon((QString)APATH+"delete.png");
    ui->pushDelete->setIcon(*icon3);
    ui->pushDelete->setIconSize(QSize( ui->pushDelete->size().width()-5,ui->pushDelete->size().height()-5 ));
    ui->pushDelete->setFocusPolicy(Qt::NoFocus);
    ui->pushAddEarlier->setFocusPolicy(Qt::NoFocus);
    ui->pushDelete->setEnabled(FALSE);
    QIcon* icon2 =new QIcon((QString)APATH+"hourglass.png");
    this->setWindowIcon(*icon2);
    db1=QSqlDatabase::addDatabase("QMYSQL","hourglass");
    db1.setDatabaseName("hourglass");
    db1.setHostName(g_HOST);
    db1.setUserName(g_USER);
    db1.setPassword(g_PASS);
    db1=QSqlDatabase::database("hourglass");
   // QPluginLoader *thePlugin = new QPluginLoader("/home/jim/qt/qt-4.6.3/plugins/sqldrivers/libqsqlmysql.so");
    //qDebug() << thePlugin->load();
    //qDebug() << thePlugin->isLoaded();
    //qDebug() << thePlugin->errorString();

    if (!db1.open())
    {
        qDebug()<<"Απέτυχε η σύνδεση με τη βάση";
        exit(0);
    }
    db2=QSqlDatabase::addDatabase("QMYSQL","asterisk");
    db2.setDatabaseName("asterisk");
    db2.setHostName(g_ASTERISK_SERVER);
    db2.setUserName(g_AST_MYSQL_USER);
    db2.setPassword(g_AST_MYSQL_PASS);
    db2=QSqlDatabase::database("asterisk");
    if (!db2.open())
    {
        qDebug()<<"Απέτυχε η σύνδεση με τη βάση";
        //exit(0);
    }
    this->customer_model=new QSqlQueryModel();
    this->project_model=new QSqlQueryModel();
    this->places_model=new QSqlQueryModel();
    this->tasks_model=new QSqlQueryModel();
    this->tasks_full_model=new QSqlQueryModel();
    this->daily_calls_model=new QSqlQueryModel();
    this->full_calls_model=new QSqlQueryModel();
    refresh_customers();
    refresh_tasks();
    refresh_full_tasks();
    refresh_daily_calls();
    refresh_full_calls();
    this->timer=new QTimer;
    this->timer_asterisk=new QTimer;
    timer_asterisk->start(60000);
    QStringList sl;
    ui->comboGraph->insertItem(0,trUtf8("ΕΒΔΟΜΑΔΑ"));
    ui->comboGraph->insertItem(1,trUtf8("ΕΤΟΣ"));
    ui->comboGraph->insertItem(2,trUtf8("ΔΙΑΧΡΟΝΙΚΟ"));
    /*
    QDate simera;
    simera=QDate::currentDate();
    int dayno=simera.dayOfWeek();

    QList <int> minut;
    for (int i=0;i<dayno;++i)
    {
        QSqlQuery query(db1);
        query.exec("select sum(TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time)) from tasks t where date(start_time)='"+simera.addDays(-i).toString("yy/M/d")+"'");
        query.next();
        minut.prepend(query.value(0).toInt());
        qDebug()<<"MINUT:"<<minut;
    }


    WeekGraph *drb=new WeekGraph(this);
    drb->set_list(minut);
    drb->setFixedWidth(921);
    drb->setFixedHeight(181);
    drb->repaint();
    */
    drb=new WeekGraph(this);
    drb->setGeometry(180,10,611,151);
    //drb->setFixedWidth(621);
    //drb->setFixedHeight(161);

    connect(timer_asterisk,SIGNAL(timeout()),this,SLOT(refresh_calls()));
    connect(timer, SIGNAL(timeout()),this, SLOT(refresh_time()));
    connect(ui->action,SIGNAL(triggered()),this,SLOT(new_customer()));
    connect(ui->tableCustomers,SIGNAL(clicked(QModelIndex)),this,SLOT(customer_selection_changed()));
    connect(ui->tableCustomers,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(edit_customer()));
    connect(ui->pushHour,SIGNAL(released()),this,SLOT(tracking_pressed()));
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(remove_invalid_chars()));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(edit_task()));
    connect(ui->tableView_2,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(edit_task_full()));
    connect(ui->pushAddEarlier,SIGNAL(released()),this,SLOT(add_earlier_task()));
    connect(ui->actionMigration,SIGNAL(triggered()),this,SLOT(do_migration()));
    connect(ui->action_2,SIGNAL(triggered()),this,SLOT(invoicing()));
    connect(ui->actionEmail,SIGNAL(triggered()),this,SLOT(email_tasks()));
    connect(ui->comboGraph,SIGNAL(currentIndexChanged(int)),this,SLOT(change_graph(int)));
    connect(ui->actionProjects,SIGNAL(triggered()),this,SLOT(projects()));
    connect(ui->actionReview,SIGNAL(triggered()),this,SLOT(invoice_review()));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(table_clicked()));
    connect(ui->tableView_2,SIGNAL(clicked(QModelIndex)),this,SLOT(table2_clicked()));
    connect(ui->pushDelete,SIGNAL(released()),this,SLOT(delete_clicked()));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tab_changed(int)));

    ui->comboGraph->setCurrentIndex(-1);
    ui->comboGraph->setCurrentIndex(0);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableTodayCalls->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableAllCalls->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableCustomers->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(context_menu(const QPoint&)));
    connect(ui->tableView_2->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(sortbycolumn(int)));
    connect(ui->tableCustomers,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(dial_customer(const QPoint&)));
    connect(ui->tableTodayCalls,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(context_menu_daily_calls(QPoint)));
    connect(ui->tableAllCalls,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(context_menu_full_calls(QPoint)));

    Asterisk_CallerID_Monitor *ast_monitor=new Asterisk_CallerID_Monitor(this);
    connect (ast_monitor,SIGNAL(incoming_call(QString)),this,SLOT(incoming_call(QString)));
    ast_monitor->start_monitor();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_customer()
{
    customer* w=new customer(this,&db1,0,"");
    connect(w,SIGNAL(main_customers_refresh()),this,SLOT(refresh_customers()));
    w->show();


}

void MainWindow::refresh_customers()
{
    QSqlQuery query(db1);
    query.exec("select id,name as "+trUtf8("ΕΠΩΝΥΜΙΑ")+" from customers order by name");
    this->customer_model->setQuery(query);
    ui->tableCustomers->setModel(customer_model);
    ui->tableCustomers->setColumnHidden(0,TRUE);
    ui->tableCustomers->setAlternatingRowColors(true);
    ui->tableCustomers->resizeColumnToContents(1);
}

void MainWindow::customer_selection_changed()
{
    ui->pushHour->setEnabled(TRUE);
    this->cusid=customer_model->data(customer_model->index(ui->tableCustomers->currentIndex().row(),0)).toString();
    ui->label_customer->setText(customer_model->data(customer_model->index(ui->tableCustomers->currentIndex().row(),1)).toString());
    refresh_places();
    refresh_projects();
    ui->comboproject->setCurrentIndex(-1);
}

void MainWindow::edit_customer()
{
    customer* w=new customer(this,&db1,1,cusid);
    connect(w,SIGNAL(main_customers_refresh()),this,SLOT(refresh_customers()));
    w->show();
}

void MainWindow::refresh_places()
{
    QSqlQuery query(db1);
    query.exec("select d.id,d.placeid,d.amount,p.description from debit_categories d,places p where d.placeid=p.id and d.cusid="+cusid);
    if(query.size()>0)
    {
        places_model->setQuery(query);
        ui->comboplace->setModel(places_model);
        ui->comboplace->setModelColumn(3);
    }
}

void MainWindow::refresh_projects()
{
    QSqlQuery query(db1);
    query.exec("select id,description from subprojects where cusid="+cusid);
    if(query.size()>0)
    {
        project_model->setQuery(query);
        ui->comboproject->setModel(project_model);
        ui->comboproject->setModelColumn(1);
    }

}

void MainWindow::tracking_pressed()
{
    QSqlQuery query(db1);
    if(tracking_status==FALSE)
    {
        ui->comboplace->setEnabled(FALSE);
        ui->comboproject->setEnabled(FALSE);
        ui->tableCustomers->setEnabled(FALSE);
        ui->tableView->setEnabled(FALSE);
        ui->tableView_2->setEnabled(FALSE);
        QIcon* icon =new QIcon((QString)APATH+"clock_1.png");
        ui->pushHour->setIcon(*icon);
        ui->pushHour->setIconSize(QSize( ui->pushHour->size().width()-5,ui->pushHour->size().height()-5 ));
        ui->labelCustTime->setText(ui->label_customer->text());
        ui->labelTime->setText("00:00:00");
        QString placeid,projectid,price;
        if (ui->comboplace->currentIndex()!=-1)
            placeid=places_model->data(places_model->index(ui->comboplace->currentIndex(),1)).toString();
        else
            placeid="NULL";
        if (ui->comboproject->currentIndex()!=-1)
            projectid=project_model->data(project_model->index(ui->comboproject->currentIndex(),0)).toString();
        else
            projectid="NULL";
        tracking_status=TRUE;
        query.exec("select amount from debit_categories where cusid="+cusid+" and placeid="+placeid);
        if( query.next())
            price=query.value(0).toString();
        else
            price="0";
        query.exec("insert into tasks (cusid,placeid,projectid,start_time,price,comment) values ("+cusid+","+placeid+","+projectid+",NOW(),"+price+",'"+ui->textEdit->toPlainText()+"')");
        query.exec("select max(id) from tasks");
        query.next();
        current_task_id=query.value(0).toString();
        timer->start(1000);
        refresh_tasks();
        refresh_full_tasks();
        return;
    }

    if(tracking_status==TRUE)
    {
        tracking_status=FALSE;
        query.exec("update tasks set end_time=now() where id="+current_task_id);
        query.exec("update tasks set comment='"+ui->textEdit->toPlainText()+"' where id="+current_task_id);
        QIcon* icon =new QIcon((QString)APATH+"clock.png");
        ui->pushHour->setIcon(*icon);
        ui->pushHour->setIconSize(QSize( ui->pushHour->size().width()-5,ui->pushHour->size().height()-5 ));
        current_task_id="0";
        refresh_tasks();
        refresh_full_tasks();
        ui->comboGraph->setCurrentIndex(-1);
        ui->comboGraph->setCurrentIndex(0);

        timer->stop();
        ui->labelCustTime->setText("");
        ui->labelTime->setText("");
        ui->comboplace->setEnabled(TRUE);
        ui->comboproject->setEnabled(TRUE);
        ui->tableCustomers->setEnabled(TRUE);
        ui->tableView->setEnabled(TRUE);
        ui->tableView_2->setEnabled(TRUE);
        ui->textEdit->setPlainText("");
        return;
    }


}

void MainWindow::refresh_tasks()
{
    QSqlQuery query(db1);
    //query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",s.description as "+trUtf8("PROJECT")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",t.start_time as "+trUtf8("ΕΝΑΡΞΗ")+",t.end_time as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id,customers c where t.cusid=c.id order by t.start_time");
    query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",s.description as "+trUtf8("PROJECT")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id,customers c where t.cusid=c.id and date(start_time)=current_date order by t.start_time");
    if(query.size()>0)
    {
        tasks_model->setQuery(query);
        ui->tableView->setModel(tasks_model);
        ui->tableView->setColumnHidden(0,TRUE);
        ui->tableView->resizeColumnToContents(1);
        ui->tableView->resizeColumnToContents(2);
        ui->tableView->resizeColumnToContents(3);
        ui->tableView->resizeColumnToContents(4);
        ui->tableView->resizeColumnToContents(5);
        ui->tableView->resizeColumnToContents(6);
        ui->tableView->resizeColumnToContents(7);
        ui->tableView->resizeColumnToContents(8);
        ui->tableView->setAlternatingRowColors(true);


    }
    refresh_daysum();
}


void MainWindow::refresh_full_tasks()
{
    QSqlQuery query(db1);
    //query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",s.description as "+trUtf8("PROJECT")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",t.start_time as "+trUtf8("ΕΝΑΡΞΗ")+",t.end_time as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id,customers c where t.cusid=c.id order by t.start_time");
    query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",s.description as "+trUtf8("PROJECT")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %H:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id,customers c where t.cusid=c.id order by t.start_time");
    if(query.size()>0)
    {
        tasks_full_model->setQuery(query);
        ui->tableView_2->setModel(tasks_full_model);
        ui->tableView_2->setColumnHidden(0,TRUE);
        ui->tableView_2->resizeColumnToContents(1);
        ui->tableView_2->resizeColumnToContents(2);
        ui->tableView_2->resizeColumnToContents(3);
        ui->tableView_2->resizeColumnToContents(4);
        ui->tableView_2->resizeColumnToContents(5);
        ui->tableView_2->resizeColumnToContents(6);
        ui->tableView_2->resizeColumnToContents(7);
        ui->tableView_2->resizeColumnToContents(8);
        ui->tableView_2->setAlternatingRowColors(true);


    }
    refresh_daysum();
}


void MainWindow::remove_invalid_chars()
{
    // ui->textEdit->setPlainText(ui->textEdit->toPlainText().replace("K","L"));
}

void MainWindow::refresh_time()
{
    QSqlQuery query(db1);
    query.exec("select start_time from tasks where id="+current_task_id);
    query.next();
    QDateTime st=query.value(0).toDateTime();
    QDateTime cu=QDateTime::currentDateTime();
    QVariant diff=st.secsTo(cu);
    //QString sdiff=diff.toString();
    QDate nulldate(2012,2,26);
    QDateTime tdiff=QDateTime(nulldate);
    QTime timeTime = tdiff.addSecs(diff.toInt()).time();
    QVariant hours = timeTime.hour();
    if (hours.toInt()<10)
        hours="0"+hours.toString();
    QVariant minutes = timeTime.minute();
    if(minutes.toInt()<10)
        minutes="0"+minutes.toString();
    QVariant secs = timeTime.second();
    if (secs.toInt()<10)
        secs="0"+secs.toString();
    ui->labelTime->setText(hours.toString()+":"+minutes.toString()+":"+secs.toString());

}

void MainWindow::edit_task()
{
    QString tk_id=tasks_model->data(tasks_model->index(ui->tableView->currentIndex().row(),0)).toString();
    tasks *w=new tasks(this,&db1,tk_id,1);
    connect(w,SIGNAL(refresh_tasks()),this,SLOT(refresh_tasks()));
    connect(w,SIGNAL(refresh_tasks()),this,SLOT(refresh_full_tasks()));
    w->show();
}


void MainWindow::edit_task_full()
{
    QString tk_id=tasks_full_model->data(tasks_full_model->index(ui->tableView_2->currentIndex().row(),0)).toString();
    tasks *w=new tasks(this,&db1,tk_id,1);
    connect(w,SIGNAL(refresh_tasks()),this,SLOT(refresh_tasks()));
    connect(w,SIGNAL(refresh_tasks()),this,SLOT(refresh_full_tasks()));
    w->show();
}

void MainWindow::add_earlier_task()
{

    tasks *w=new tasks(this,&db1,"0",0);
    connect(w,SIGNAL(refresh_tasks()),this,SLOT(refresh_tasks()));
    connect(w,SIGNAL(refresh_tasks()),this,SLOT(refresh_full_tasks()));
    w->show();
}

void MainWindow::do_migration()
{
    migration *w=new migration(this,&db1);
    w->show();
}

void MainWindow::invoicing()
{
    invoice_browser *w=new invoice_browser(this,&db1);
    w->show();
}

void MainWindow::email_tasks()
{
    Email_tasks *w=new Email_tasks(this,&db1);
    w->show();
}

void MainWindow::refresh_daysum()
{
    QSqlQuery query(db1);
    query.exec("select sum(TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time)) from tasks t where date(start_time)=current_date");
    query.next();
    ui->labelDaySum->setText(query.value(0).toString());

}

void MainWindow::invoice_review()
{
    InvoiceReview *w=new InvoiceReview(this,&db1);
    w->show();
}

void MainWindow::projects()
{
    ProjectsBrowser *w =new ProjectsBrowser(this,&db1);
    w->set_title("Projects");
    w->set_model("select s.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",s.description as "+trUtf8("PROJECT")+",s.fee as "+trUtf8("AMOIBH")+" from subprojects s,customers c where c.id=s.cusid");
    QList <int> cols;
    cols.append(0);
    w->set_hiddenCols(cols);
    w->show();
}


void MainWindow::change_graph(int i)
{
    QDate simera;
    simera=QDate::currentDate();
    QList <int> minut;
    QList <QString> label;
    QSqlQuery query(db1);

    switch(i)
    {

    case 0:
    {
        int dayno=simera.dayOfWeek();


        for (int i=0;i<dayno;++i)
        {

            query.exec("select dayname(start_time),sum(TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time)) from tasks t where date(start_time)='"+simera.addDays(-i).toString("yy/M/d")+"' group by dayname(start_time)");
            if(query.next())
            {

                minut.prepend(query.value(1).toInt());
                label.prepend(query.value(0).toString());
            }

        }

        //if(query.size()>=0)
        //{
        //WeekGraph *drb=new WeekGraph(this);
        drb->set_list(minut,label);

        //drb->setFixedWidth(611);
        // drb->setFixedHeight(181);
        drb->repaint();
        //}
        break;
    }

    case 1:
    {

        QVariant month,year;
        for (int i=1;i<=simera.month();++i)
        {
            month=i;
            year=simera.year();

            query.exec("select monthname(start_time),sum(TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time)) from tasks t where month(start_time)="+month.toString()+" and year(start_time)="+year.toString()+" group by monthname(start_time)");
            if(query.next())
            {
            minut.append(query.value(1).toInt());
            label.append(query.value(0).toString());
            }
        }
        if(query.size()>0)
        {
        drb->set_list(minut,label);
        drb->repaint();
        }
        break;
    }

    case 2:
    {
        query.exec("select min(year(start_time)) from tasks");
        query.next();
        QVariant min_year=query.value(0);
        query.exec("select max(year(start_time)) from tasks");
        query.next();
        QVariant max_year=query.value(0);
        QVariant month,year;
        for (int i=min_year.toInt();i<=max_year.toInt();++i)
        {
            year=i;

            for (int j=1;j<=12;++j)
            {
                month=j;
                query.exec("select concat_ws('/',month(start_time),substr(year(start_time) from 3)),sum(TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time)) from tasks t where month(start_time)="+month.toString()+" and year(start_time)="+year.toString()+" group by concat_ws('/',month(start_time),substr(year(start_time) from 3))");

                if (query.next())
                {
                    minut.append(query.value(1).toInt());
                    label.append(query.value(0).toString());
                }
            }
            drb->set_list(minut,label);
            drb->repaint();
        }

    }


    }
}

void MainWindow::context_menu(const QPoint& pos)
{
    // for most widgets
       QPoint globalPos = ui->tableView->mapToGlobal(pos);
               //myWidget->mapToGlobal(pos);
       // for QAbstractScrollArea and derived classes you would use:
       // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);

       QMenu myMenu;
       myMenu.setFocusPolicy(Qt::NoFocus);
       myMenu.addAction(trUtf8("Συνέχιση εργασίας"));

       myMenu.addAction(trUtf8("Kλήση πελάτη"));
       // ...

       QAction* selectedItem = myMenu.exec(globalPos);
       if (selectedItem)
       {

           QSqlQuery query(db1);
           QString t_id=tasks_model->data(tasks_model->index(ui->tableView->currentIndex().row(),0)).toString();
           query.exec("select t.cusid,t.placeid,t.projectid,t.comment from tasks t where id="+t_id);
           query.next();
           this->cusid=query.value(0).toString();
           QString t_cusid=cusid=query.value(0).toString();

           if(selectedItem->text()==trUtf8("Συνέχιση εργασίας"))
           {

           refresh_places();
           refresh_projects();

           ui->label_customer->setText(tasks_model->data(tasks_model->index(ui->tableView->currentIndex().row(),1)).toString());
           ui->textEdit->setPlainText(query.value(3).toString());
           for (int i=0;i<ui->comboplace->count();++i)
           {
               ui->comboplace->setCurrentIndex(i);

               if (places_model->data(places_model->index(ui->comboplace->currentIndex(),0))==query.value(1).toInt())

                   break;

           }
           for (int i=0;i<ui->comboproject->count();++i)
           {
               ui->comboproject->setCurrentIndex(i);

               if (project_model->data(project_model->index(ui->comboproject->currentIndex(),0))==query.value(2).toInt())

                   break;

           }
           ui->pushHour->setEnabled(TRUE);
           }
           else
           {
               query.exec("select phone from customers where id="+t_cusid);
               query.next();
               QString phone=query.value(0).toString();
               dial(phone);

           }

       }

       return;

}



void MainWindow::table_clicked()
{
    //ui->pushDelete->setEnabled(TRUE);
}

void MainWindow::table2_clicked()
{
    ui->pushDelete->setEnabled(TRUE);
}

void MainWindow::delete_clicked()
{
    QString tk_id;
    if (current_tab==2)
    {
        //tk_id=tasks_model->data(tasks_model->index(ui->tableView->currentIndex().row(),0)).toString();
    //else
        tk_id=tasks_full_model->data(tasks_full_model->index(ui->tableView_2->currentIndex().row(),0)).toString();

    QMessageBox m;
    m.setText(trUtf8("Θέλετε να διαγράψετε την επιλεγμένη κίνηση"));
    m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
    QAbstractButton *acc = m.addButton(trUtf8("Ναί"),
                    QMessageBox::ActionRole);
    QAbstractButton *rej = m.addButton(trUtf8("Όχι"), QMessageBox::ActionRole);

    m.move(100, 100);
    QFont serifFont("Times", 18, QFont::Bold);
    m.setFont(serifFont);
    m.setDefaultButton((QPushButton*)rej);

    m.exec();
    if (m.clickedButton() == rej)
        return;

    if (m.clickedButton() == acc)
    {
        QSqlQuery query(db1);
        //qDebug()<<"TID"<<tk_id;
        query.exec("delete from tasks where id="+tk_id);
    }
    refresh_tasks();
    refresh_full_tasks();
    ui->pushDelete->setEnabled(FALSE);
    }
}

void MainWindow::tab_changed(int tab)
{
    current_tab=tab;
    if (tab!=2)
        ui->pushDelete->setEnabled(FALSE);

}

void MainWindow::sortbycolumn(int column)
{
    qDebug()<<"SORT"<<column;
    ui->tableView_2->setSortingEnabled(TRUE);
    if (column==1)
        tasks_full_model->sort(column);
}

void MainWindow::dial_customer(const QPoint& pos)
{
    QPoint globalPos = ui->tableCustomers->mapToGlobal(pos);
            //myWidget->mapToGlobal(pos);
    // for QAbstractScrollArea and derived classes you would use:
    // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.setFocusPolicy(Qt::NoFocus);
    myMenu.addAction(trUtf8("Κλήση πελάτη"));
    // ...

    QAction* selectedItem = myMenu.exec(globalPos);

    QString phone;
    if (selectedItem)
    {
        QSqlQuery query(db1);
        QString c_id=customer_model->data(customer_model->index(ui->tableCustomers->currentIndex().row(),0)).toString();
        query.exec("select phone from customers where id="+c_id);
        query.next();
        phone=query.value(0).toString();
        dial(phone);
    }



}

void MainWindow::dial(QString phone)
{
    QHostAddress addr(g_ASTERISK_SERVER);
    QTcpSocket *client = new QTcpSocket;
    client->connectToHost(addr,g_ASTERISK_PORT);
    QTextStream str( client );
    str << "ACTION: Login\r\nUsername: "+g_ASTERISK_LOGIN+"\r\nSecret: "+g_ASTERISK_SECRET+"\r\n\r\n";
    str.flush();
    str.reset();


    //str << "Action: Originate\r\nChannel: SIP/15\r\nExten: 96947613893\r\nContext: algo_DLPN_Internal\r\nPriority: 1\r\n\r\n";
    str << "Action: Originate\r\nChannel: "+g_ASTERISK_EXTENSION+"\r\nExten: "+g_ASTERISK_DIAL_PREFIX+phone+"\r\nContext: "+(QString)g_ASTERISK_CONTEXT+"\r\nPriority: 1\r\n\r\n";
    str.flush();
    client->disconnectFromHost();
}


void MainWindow::incoming_call(QString callerid)
{
    QSqlQuery query(db1);
    query.exec("select id from phonebook where phoneno='"+callerid+"'");

    QString phonebookid="";
    if (query.next())
        phonebookid=query.value(0).toString();

    Incoming_Call *w =new Incoming_Call(this,&db1,phonebookid,callerid);
    w->show();
}

void MainWindow::refresh_daily_calls()
{
    QSqlQuery query(db2);
    query.exec("CREATE TEMPORARY TABLE `tmp_phonebook` (`phoneno` varchar(50) NOT NULL,`cusname` varchar(50) NOT NULL DEFAULT '') ENGINE=MEMORY DEFAULT CHARSET=utf8;");
    query.exec("CREATE TEMPORARY TABLE `tmp_phonebook_1` (`phoneno` varchar(50) NOT NULL,`cusname` varchar(50) NOT NULL DEFAULT '') ENGINE=MEMORY DEFAULT CHARSET=utf8;");
    QSqlQuery query1(db1);
    query1.exec("select p.phoneno,c.name from phonebook p, customers c where c.id=p.cusid");
    while(query1.next())
    {
        query.exec("insert into tmp_phonebook (phoneno,cusname) values('"+query1.value(0).toString()+"','"+query1.value(1).toString()+"')");
        query.exec("insert into tmp_phonebook_1 (phoneno,cusname) values('"+query1.value(0).toString()+"','"+query1.value(1).toString()+"')");

    }
    //query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",s.description as "+trUtf8("PROJECT")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",t.start_time as "+trUtf8("ΕΝΑΡΞΗ")+",t.end_time as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id,customers c where t.cusid=c.id order by t.start_time");
    query.exec("select date_format(c.calldate,'%H:%i') as '"+trUtf8("ΩΡΑ ΚΛΗΣΗΣ")+"',c.src as '"+trUtf8("ΚΑΛΩΝ")+"',c.dst as '"+trUtf8("ΚΑΛΟΥΜΕΝΟΣ")+"',c.duration as '"+trUtf8("ΔΙΑΡΚΕΙΑ")+"',concat(ifnull((select cusname from tmp_phonebook where phoneno=c.src),''),ifnull((select cusname from tmp_phonebook_1 where phoneno=substring(c.dst,2,15)),'')) as '"+trUtf8("ΠΕΛΑΤΗΣ")+"' from cdr c where date(calldate)=current_date and (c.dstchannel like '"+g_ASTERISK_EXTENSION+"%' or c.channel like '"+g_ASTERISK_EXTENSION+"%') order by c.calldate");
    //        query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",s.description as "+trUtf8("PROJECT")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %h:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %h:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id,customers c where t.cusid=c.id and date(start_time)=current_date order by t.start_time");
    if(query.size()>0)
    {

        daily_calls_model->setQuery(query);
        ui->tableTodayCalls->setModel(daily_calls_model);
        ui->tableTodayCalls->resizeColumnToContents(0);
        ui->tableTodayCalls->resizeColumnToContents(1);
        ui->tableTodayCalls->resizeColumnToContents(2);
        ui->tableTodayCalls->resizeColumnToContents(3);
        ui->tableTodayCalls->resizeColumnToContents(4);
        ui->tableTodayCalls->setAlternatingRowColors(true);
        ui->tableTodayCalls->scrollToBottom();

    }
    query.exec("drop temporary table tmp_phonebook");
    query.exec("drop temporary table tmp_phonebook_1");


}

void MainWindow::refresh_full_calls()
{
    QSqlQuery query(db2);
    query.exec("CREATE TEMPORARY TABLE `tmp_phonebook_2` (`phoneno` varchar(50) NOT NULL,`cusname` varchar(50) NOT NULL DEFAULT '') ENGINE=MEMORY DEFAULT CHARSET=utf8;");
    query.exec("CREATE TEMPORARY TABLE `tmp_phonebook_3` (`phoneno` varchar(50) NOT NULL,`cusname` varchar(50) NOT NULL DEFAULT '') ENGINE=MEMORY DEFAULT CHARSET=utf8;");
    QSqlQuery query1(db1);
    query1.exec("select p.phoneno,c.name from phonebook p, customers c where c.id=p.cusid");
    while(query1.next())
    {
        query.exec("insert into tmp_phonebook_2 (phoneno,cusname) values('"+query1.value(0).toString()+"','"+query1.value(1).toString()+"')");
        query.exec("insert into tmp_phonebook_3 (phoneno,cusname) values('"+query1.value(0).toString()+"','"+query1.value(1).toString()+"')");

    }


    //query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",s.description as "+trUtf8("PROJECT")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",t.start_time as "+trUtf8("ΕΝΑΡΞΗ")+",t.end_time as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id,customers c where t.cusid=c.id order by t.start_time");

    query.exec("select date_format(c.calldate,'%d/%m/%y %H:%i') as '"+trUtf8("ΩΡΑ ΚΛΗΣΗΣ")+"',c.src as '"+trUtf8("ΚΑΛΩΝ")+"',c.dst as '"+trUtf8("ΚΑΛΟΥΜΕΝΟΣ")+"',c.duration as '"+trUtf8("ΔΙΑΡΚΕΙΑ")+"',concat(ifnull((select cusname from tmp_phonebook_2 where phoneno=c.src),''),ifnull((select cusname from tmp_phonebook_3 where phoneno=substring(c.dst,2,15)),'')) as '"+trUtf8("ΠΕΛΑΤΗΣ")+"' from cdr c where c.dstchannel like '"+g_ASTERISK_EXTENSION+"%' or c.channel like '"+g_ASTERISK_EXTENSION+"%'order by c.calldate");

    //        query.exec("select t.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",p.description as "+trUtf8("ΤΟΠΟΣ")+",s.description as "+trUtf8("PROJECT")+",TIMESTAMPDIFF(MINUTE,t.start_time,t.end_time) as "+trUtf8("ΔΙΑΡΚΕΙΑ")+",date_format(t.start_time,'%d/%m/%Y %h:%i') as "+trUtf8("ΕΝΑΡΞΗ")+",date_format(t.end_time,'%d/%m/%Y %h:%i') as "+trUtf8("ΛΗΞΗ")+",t.price as "+trUtf8("ΧΑΩ")+",t.comment as "+trUtf8("ΣΧΟΛΙΑ")+" from tasks t left outer join subprojects s on t.projectid=s.id left outer join places p on t.placeid=p.id,customers c where t.cusid=c.id and date(start_time)=current_date order by t.start_time");
    if(query.size()>0)
    {
        full_calls_model->setQuery(query);
        ui->tableAllCalls->setModel(full_calls_model);
        ui->tableAllCalls->resizeColumnToContents(0);
        ui->tableAllCalls->resizeColumnToContents(1);
        ui->tableAllCalls->resizeColumnToContents(2);
        ui->tableAllCalls->resizeColumnToContents(3);
        ui->tableAllCalls->setAlternatingRowColors(true);
        ui->tableAllCalls->scrollToBottom();
    }
    query.exec("drop temporary table tmp_phonebook_2");
    query.exec("drop temporary table tmp_phonebook_3");

}



void MainWindow::refresh_calls()
{
    refresh_daily_calls();
    refresh_full_calls();
}

void MainWindow::context_menu_daily_calls(const QPoint &pos)
{
    QPoint globalPos = ui->tableTodayCalls->mapToGlobal(pos);


    QMenu myMenu;
    myMenu.setFocusPolicy(Qt::NoFocus);
    myMenu.addAction(trUtf8("Κλήση πελάτη"));


    QAction* selectedItem = myMenu.exec(globalPos);

    QString phone;
    if (selectedItem)
    {
        QString src=daily_calls_model->data(daily_calls_model->index(ui->tableTodayCalls->currentIndex().row(),1)).toString();
        QString dst=daily_calls_model->data(daily_calls_model->index(ui->tableTodayCalls->currentIndex().row(),2)).toString();
        if (src.length()>dst.length())
            phone=src;
        else
            phone=dst.mid(1,15);
        dial(phone);
    }
}

void MainWindow::context_menu_full_calls(const QPoint &pos)
{
    QPoint globalPos = ui->tableAllCalls->mapToGlobal(pos);


    QMenu myMenu;
    myMenu.setFocusPolicy(Qt::NoFocus);
    myMenu.addAction(trUtf8("Κλήση πελάτη"));


    QAction* selectedItem = myMenu.exec(globalPos);

    QString phone;
    if (selectedItem)
    {
        QString src=full_calls_model->data(full_calls_model->index(ui->tableAllCalls->currentIndex().row(),1)).toString();
        QString dst=full_calls_model->data(full_calls_model->index(ui->tableAllCalls->currentIndex().row(),2)).toString();
        if (src.length()>dst.length())
            phone=src;
        else
            phone=dst.mid(1,15);

        dial(phone);
    }

}
