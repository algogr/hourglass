#include "projectsbrowser.h"

ProjectsBrowser::ProjectsBrowser(QWidget *parent,QSqlDatabase *db1) :
    GeneralBrowser(parent,db1)
{
}


void ProjectsBrowser::add()
{
    Projects *w =new Projects(this,db1,0,0);
    connect(w,SIGNAL(data_changed()),this,SLOT(model_reset()));
    w->show();
}

void ProjectsBrowser::edit(const QModelIndex &index)
{
    int pid= model->data(model->index(index.row(),0,QModelIndex())).toInt();
    Projects *w =new Projects(this,db1,1,pid);
    connect(w,SIGNAL(data_changed()),this,SLOT(model_reset()));
    w->show();
}

void ProjectsBrowser::model_reset()
{
    set_model(m_query);
}

