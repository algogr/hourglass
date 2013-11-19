#include "config.h"
#include "ui_config.h"
#include <QtCore>

Config::Config(QWidget *parent,QFile *file) :
    QDialog(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
    QIcon* icon =new QIcon((QString)APATH+"ok.png");
    ui->pushOk->setIcon(*icon);
    ui->pushOk->setIconSize(QSize( ui->pushOk->size().width()-5,ui->pushOk->size().height()-5 ));
    QIcon* icon1 =new QIcon((QString)APATH+"cancel.png");
    ui->pushCancel->setIcon(*icon1);
    ui->pushCancel->setIconSize(QSize( ui->pushCancel->size().width()-5,ui->pushCancel->size().height()-5 ));
    this->file=file;
    connect(ui->pushOk,SIGNAL(released()),this,SLOT(okPressed()));
    connect(ui->pushCancel,SIGNAL(released()),this,SLOT(cancelPressed()));
}

Config::~Config()
{
    delete ui;

}

void Config::okPressed()
{
    if (ui->linemysqlhost->text()=="" || ui->linemysqluser->text()=="" || ui->linemysqlpass->text()=="" ||
            ui->lineemail->text()=="" || ui->lineemailinv->text()=="" || ui->linemailserver->text()=="" ||
            ui->lineastserver->text()=="" || ui->lineastport->text()=="" || ui->lineastextension->text()=="" ||
            ui->lineastcontext->text()=="" || ui->lineasteriskprefix->text()=="" ||
            ui->lineamilogin->text()=="" || ui->lineamisecret->text()=="" || ui->lineastmysqlport->text()=="" ||
            ui->lineastmysqluser->text()=="" || ui->lineastmysqlpass->text()=="" || ui->lineastmysqlcdr->text()=="")
        exit(0);
    qDebug()<<file;
    file->open(QIODevice::ReadWrite | QIODevice::Text);
    qDebug()<<"TTT";
    QTextStream out(file);
    out<<ui->linemysqlhost->text()<<"\n"<<ui->linemysqluser->text()<<"\n"<<ui->linemysqlpass->text()<<"\n";
    out<<ui->lineemail->text()<<"\n"<<ui->lineemailinv->text()<<"\n"<<ui->linemailserver->text()<<"\n";
    out<<ui->lineastserver->text()<<"\n"<<ui->lineastport->text()<<"\n"<<ui->lineastextension->text()<<"\n";
    out<<ui->lineastcontext->text()<<"\n"<<ui->lineasteriskprefix->text()<<"\n"<<ui->lineamilogin->text()<<"\n";
    out<<ui->lineamisecret->text()<<"\n"<<ui->lineastmysqlport->text()<<"\n"<<ui->lineastmysqluser->text()<<"\n";
    out<<ui->lineastmysqlpass->text()<<"\n"<<ui->lineastmysqlcdr->text();
    file->close();
    delete(this);
}

void Config::cancelPressed()
{
    exit(0);
}
