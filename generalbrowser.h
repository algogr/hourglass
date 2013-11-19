#ifndef GENERALBROWSER_H
#define GENERALBROWSER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
    class GeneralBrowser;
}

class GeneralBrowser : public QDialog
{
    Q_OBJECT

public:
    explicit GeneralBrowser(QWidget *parent = 0,QSqlDatabase *db1=0);
    ~GeneralBrowser();
    void set_title(QString title);
    void set_model(QString query_string);
    void set_hiddenCols(QList<int> cols);

private:


protected:
    Ui::GeneralBrowser *ui;
    QSqlDatabase *db1;
    QString title,m_query;
    QSqlQueryModel *model;
    QList <int> hiddenColumns;

public slots:
    virtual void add()=0;
    virtual void edit(const QModelIndex &index)=0;
    virtual void model_reset()=0;
};

#endif // GENERALBROWSER_H
