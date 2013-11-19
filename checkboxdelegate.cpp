#include "checkboxdelegate.h"
#include "editorcheckbox.h"
#include "editorspinbox.h"

CheckBoxDelegate::CheckBoxDelegate(QObject *parent) :
    QItemDelegate(parent)
{

    //QItemDelegate::QItemDelegate(parent);
    //this->checkboxCol=1;
    //qDebug()<<"construstor:";

}


QWidget *CheckBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    if (index.column()==1)
    {
        EditorCheckBox *editor =new EditorCheckBox(parent);
    //QCheckBox *editor = new QCheckBox(parent);
    editor->setText("");
    editor->setIndex(index);
    connect(editor,SIGNAL(clicked_new(bool,QModelIndex)),this,SLOT(echk_clicked(bool,QModelIndex)));
    editor->installEventFilter(const_cast<CheckBoxDelegate*>(this));


    return editor;
    }
    if (index.column()==6)
    {
        EditorSpinBox *editor=new EditorSpinBox(parent);
        editor->setIndex(index);
        connect(editor,SIGNAL(clicked_new(int,QModelIndex)),this,SLOT(espin_clicked(int,QModelIndex)));

        editor->installEventFilter(const_cast<CheckBoxDelegate*>(this));

        return editor;
    }
    //if(index.isValid() && index.column() == checkboxCol)
    //{
    //QCheckBox *editor = new QCheckBox(parent);
    //editor->installEventFilter(const_cast<CheckBoxDelegate*>(this));
    //return editor;
    //}
    else
    //{
    return QItemDelegate::createEditor(parent, option, index);
    //}
}

void CheckBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{

    if(index.isValid() && index.column() == 1)
    {

    QString value = index.model()->data(index, Qt::DisplayRole).toString();

    QCheckBox *checkBox = static_cast<QCheckBox*>(editor);

    //map.insert(0,checkBox);
    checkBox->setText("");
    if(value == "1")
    checkBox->setCheckState(Qt::Checked);
    else
    checkBox->setCheckState(Qt::Unchecked);
    }
    else
    {
    QItemDelegate::setEditorData(editor, index);
    }

}
//! [2]

//! [3]
void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const
{



}

//! [3]

//! [4]
 void CheckBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
    //qDebug()<<"updaegeometry";
    if(index.isValid() && index.column() == 1)
    editor->setGeometry(option.rect);
    else
    QItemDelegate::updateEditorGeometry(editor, option, index);

}



void CheckBoxDelegate::echk_clicked(bool state,const QModelIndex &index)
{
    emit editor_changed_state(state,index);
}

void CheckBoxDelegate::espin_clicked(int value,const QModelIndex &index)
{
    emit editor_spin_value(value,index);
}






//! [4]
