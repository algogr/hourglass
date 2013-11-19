#include "debit_types.h"
#include "ui_debit_types.h"

debit_types::debit_types(QWidget *parent,QSqlDatabase *db1,int mode,QString cusid) :
    QDialog(parent),
    ui(new Ui::debit_types)
{
    this->db1=db1;
    this->mode=mode;
    this->cusid=cusid;

    QSqlQuery query(*db1);
    query.exec("select id,description from places");
    this->m=new QSqlQueryModel();
    m->setQuery(query);

    ui->setupUi(this);

    ui->comboBox->setModel(m);
    ui->comboBox->setModelColumn(1);
    if (mode==0)
    {
        ui->pushInsert->setEnabled(FALSE);

    }
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(text_changed()));
    connect(ui->pushInsert,SIGNAL(released()),this,SLOT(insert_debit_type()));

}

debit_types::~debit_types()
{
    delete ui;
}

void debit_types::text_changed()
{

    bool ok;

    int w=ui->lineEdit->text().toInt(&ok,10);
    if (ok==FALSE)
    {
        ui->lineEdit->setText("");
        return;
    }
    if (ui->comboBox->currentIndex()!=-1)
    {
        if (ui->lineEdit->text()!="")
            ui->pushInsert->setEnabled(TRUE);
    }
}

void debit_types::insert_debit_type()
{
    QSqlQuery query(*db1);

    QString placeid=m->data(m->index(ui->comboBox->currentIndex(),0)).toString();
    query.exec("select * from debit_categories where cusid="+cusid+" and placeid="+placeid);
    if (query.next())
    {
        QMessageBox::critical(this, qApp->tr("Προσοχή"), qApp->tr("O συνδιασμός έχει ήδη καταχωρηθεί"));
        return;
    }
    query.exec("insert into debit_categories (cusid,placeid,amount) values ("+this->cusid+","+placeid+","+ui->lineEdit->text()+")");
    emit refresh_table();
    delete(this);
}
