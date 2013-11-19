#include "generalbrowser.h"
#include "ui_generalbrowser.h"
#include "constants.h"

GeneralBrowser::GeneralBrowser(QWidget *parent,QSqlDatabase *db1) :
    QDialog(parent),
    ui(new Ui::GeneralBrowser)
{
    ui->setupUi(this);
    this->db1=db1;
    QIcon* icon =new QIcon((QString)APATH+"add.png");
    ui->pushButton->setIcon(*icon);
    ui->pushButton->setIconSize(QSize( ui->pushButton->size().width()-5,ui->pushButton->size().height()-5 ));
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(add()));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(edit(QModelIndex)));
    model=new QSqlQueryModel;
    ui->tableView->setAlternatingRowColors(true);

}

GeneralBrowser::~GeneralBrowser()
{
    delete ui;
}

void GeneralBrowser::set_title(QString title)
{
    this->setWindowTitle(title);
}

void GeneralBrowser::set_model(QString query_string)
{
    QSqlQuery query(*db1);
    this->m_query=query_string;
    query.exec(m_query);
    model->setQuery(query);
    ui->tableView->setModel(model);
    int i=model->columnCount();
    for (int j=0;j<i;++j)
    {
        ui->tableView->resizeColumnToContents(j);
    }

}

void GeneralBrowser::set_hiddenCols(QList<int> cols)
{
    for (int i=0;i<cols.size();++i)
    {
        ui->tableView->setColumnHidden(cols.value(i),TRUE);


    }
}


