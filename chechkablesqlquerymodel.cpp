#include <Qt/QtGui>
#include "chechkablesqlquerymodel.h"

chechkablesqlquerymodel::chechkablesqlquerymodel(QObject *parent,QSqlDatabase *db1) :
    QSqlQueryModel(parent)
{
    this->db1=db1;
}

 Qt::ItemFlags chechkablesqlquerymodel::flags ( const QModelIndex & index ) const
    {
    /*
      if(!index.isValid())
      return 0;*/

    if(index.column()==1 || index.column()==6)
    {

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;

    }
    else
    {

    return QAbstractItemModel::flags(index);
    }
    }

QVariant chechkablesqlquerymodel::data(const QModelIndex &index, int role) const
{
    //if(index.column()==1)
      //  {
            //return index.data(Qt::DisplayRole);
        //QVariant value=FALSE;
        //return value;
       // }
    //else




   // if (index.column()==1 || role==Qt::EditRole || role==Qt::DisplayRole)
     //        return (QSqlQueryModel::data(index).toInt() != 0) ? Qt::Checked : Qt::Unchecked;
    //{
        //if(QSqlQueryModel::data(index).toInt()==0)
            //return tr("Όχι");
        //else
            //return tr("Ναι");

    //}
             //return QSqlQueryModel::data(index,Qt::DisplayRole);

       //  else

             return QSqlQueryModel::data(index, role);
            /* QVariant value = QSqlQueryModel::data(index, role);
             if (index.column() == 1)
             {
             if (role == Qt::EditRole)
             return (QSqlQueryModel::data(index).toInt() != 0) ? Qt::Checked : Qt::Unchecked;
             else if (role == Qt::DisplayRole)
            return (QSqlQueryModel::data(index).toInt() != 0) ? Qt::Checked : Qt::Unchecked;
                 //return ""; // Don't show value !!
             }
             return value;
*/
}

bool chechkablesqlquerymodel::setData(const QModelIndex &index,const QVariant &value, int role)
{
    QSqlQuery query(*db1);
    QString task_id=this->data(index.model()->index(index.row(),0),Qt::DisplayRole).toString();
    if(index.column()==1 && role==Qt::EditRole)
{

    query.exec("update tasks set invoice="+value.toString()+" where id="+task_id);


}
    if(index.column()==6 && role==Qt::EditRole)
{

    query.exec("update tasks set price="+value.toString()+" where id="+task_id);


}

    return TRUE;
}


QModelIndex chechkablesqlquerymodel::index(int row, int column, const QModelIndex &parent) const
{
    return QAbstractTableModel::index(row,column,parent);
}

