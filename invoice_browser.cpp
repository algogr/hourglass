#include "invoice_browser.h"
#include "ui_invoice_browser.h"

invoice_browser::invoice_browser(QWidget *parent,QSqlDatabase *db1) :
    QDialog(parent),
    ui(new Ui::invoice_browser)
{
    ui->setupUi(this);
    this->db1=db1;
    this->invoice_model=new QSqlQueryModel();
    refresh_invoices();
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(show_customer()));
}

invoice_browser::~invoice_browser()
{
    delete ui;
}

void invoice_browser::refresh_invoices()
{
    QSqlQuery query(*db1);
    query.exec("select c.id,c.name as "+trUtf8("ΠΕΛΑΤΗΣ")+",(select sum(TIMESTAMPDIFF(SECOND,start_time,end_time))/3600 from tasks t where t.cusid=c.id and t.invoice=0) as "+trUtf8("ΩΡΕΣ")+",(select date_format(max(date(start_time)),'%d/%m/%y') from tasks t where t.cusid=c.id and t.invoice=1 and t.projectid is null) as "+trUtf8("ΤΙΜΟΛΟΓΗΘΗΚΕ")+",(select date_format(min(date(start_time)),'%d/%m/%Y') from tasks t where t.cusid=c.id and t.invoice=0 and t.projectid is null) as "+trUtf8("ΑΠΟ")+" from customers c where c.active=1 group by c.name order by c.name");
    if (query.size()>0)
    {

        invoice_model->setQuery(query);
        ui->tableView->setModel(invoice_model);
        ui->tableView->setColumnHidden(0,TRUE);
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->resizeColumnToContents(1);
        ui->tableView->resizeColumnToContents(2);
        ui->tableView->resizeColumnToContents(3);
        ui->tableView->resizeColumnToContents(4);
    }

}


void invoice_browser::show_customer()
{
    cusid=invoice_model->data(invoice_model->index(ui->tableView->currentIndex().row(),0)).toString();
    invoice_customer *w=new invoice_customer(this,db1,cusid);
    w->show();

}
