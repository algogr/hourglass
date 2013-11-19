#ifndef EDITORSPINBOX_H
#define EDITORSPINBOX_H

#include <QWidget>
#include <QtCore>
#include <QSpinBox>
#include <QAbstractItemModel>


class EditorSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit EditorSpinBox(QWidget *parent = 0);
    QModelIndex index;
    void setIndex(const QModelIndex &index);


signals:
    void clicked_new(int value,const QModelIndex &index);

public slots:
    void s_clicked();

};

#endif // EDITORSPINBOX_H
