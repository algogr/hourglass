#ifndef CHECHKABLESQLQUERYMODEL_H
#define CHECHKABLESQLQUERYMODEL_H

#include <QSqlQueryModel>
#include <QtSql>
#include <QMessageBox>
#include <QString>
#include <QAbstractItemModel>

#include <iostream>

class chechkablesqlquerymodel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit chechkablesqlquerymodel(QObject *parent = 0,QSqlDatabase *db1=0);

    virtual Qt::ItemFlags flags ( const QModelIndex & index ) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index,const QVariant &value, int role);
    virtual QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
    bool doit;
    QSqlDatabase *db1;

signals:


public slots:

};

#endif // CHECHKABLESQLQUERYMODEL_H
