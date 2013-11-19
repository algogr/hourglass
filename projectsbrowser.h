#ifndef PROJECTSBROWSER_H
#define PROJECTSBROWSER_H

#include "generalbrowser.h"
#include "projects.h"
class ProjectsBrowser : public GeneralBrowser
{
    Q_OBJECT
public:
    explicit ProjectsBrowser(QWidget *parent = 0,QSqlDatabase *db1=0);
    void add();
    void edit(const QModelIndex &index);
    void model_reset();

signals:

public slots:

};

#endif // PROJECTSBROWSER_H
