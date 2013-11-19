#include "weekgraph.h"

WeekGraph::WeekGraph(QWidget *parent) :
    QWidget(parent)
{

}

void WeekGraph::paintEvent(QPaintEvent *event)
{
    if (this->list.size()>0)
    {
    int max_height=150;
    int max_value=0;

    int v=0;

    for (int i=0;i<this->list.size();++i)
    {

        v=this->list[i];

        if (max_value<this->list[i])
                max_value=this->list[i];
        //list_sum+=this->list[i];

    }


    QPainter painter(this);
    QVariant trans;
    float height,width;
    for (int j=0;j<this->list.size();++j)
    {


        height=(this->list[j]*100/max_value)*(max_height/100);
        width=610/list.size();
        trans=list[j]/60;
        trans=trans.toFloat();
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(QPen(Qt::black, 1, Qt::DotLine, Qt::RoundCap));
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));

        painter.drawRect(1+(width*j),150,width,-height);
        painter.drawText(1+(width*j),130, wordlist[j]);
        painter.drawText(1+(width*j),120,trans.toString());



    }
}
}

void WeekGraph::set_list(QList<int> &list,QList<QString> &list1)
{
    this->list=list;
    this->wordlist=list1;
    this->repaint();

}


