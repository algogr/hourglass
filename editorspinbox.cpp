#include "editorspinbox.h"

EditorSpinBox::EditorSpinBox(QWidget *parent) :
    QSpinBox(parent)
{
}

void EditorSpinBox::s_clicked()
{

    qDebug()<<"EDITING FINISHED";
    emit clicked_new(this->value(),index);
}
void EditorSpinBox::setIndex(const QModelIndex &index)
{
    connect(this,SIGNAL(editingFinished()),this,SLOT(s_clicked()));
    //connect(this,SIGNAL(valueChanged(int)),this,SLOT(s_clicked()));
    this->index=index;


}
