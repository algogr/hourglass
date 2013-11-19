#ifndef WEEKGRAPH_H
#define WEEKGRAPH_H

#include <QWidget>
#include <Qt/QtGui>

class WeekGraph : public QWidget
{
    Q_OBJECT
public:
    explicit WeekGraph(QWidget *parent = 0);
    void set_list(QList<int> &list,QList<QString> &list1);
    void set_word_list(QList<QString> &list);
protected:
    void paintEvent(QPaintEvent *);

private:
    QList<int> list;
    QList<QString> wordlist;
signals:

public slots:

};

#endif // WEEKGRAPH_H
