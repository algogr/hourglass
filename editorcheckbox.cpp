#include "editorcheckbox.h"

EditorCheckBox::EditorCheckBox(QWidget *parent) :
    QCheckBox(parent)
{

}

void EditorCheckBox::c_clicked()
{
    bool state;
    qDebug()<<this->checkState();
    if (this->checkState()==Qt::Unchecked)
            state=FALSE;
    else
        state=TRUE;

    emit clicked_new(state,index);
}
void EditorCheckBox::setIndex(const QModelIndex &index)
{
    connect(this,SIGNAL(clicked()),this,SLOT(c_clicked()));

    this->index=index;


}


