#ifndef EDITORCHECKBOX_H
#define EDITORCHECKBOX_H

#include <QWidget>
#include <QCheckBox>
#include <QAbstractItemModel>
#include <QtCore>

class EditorCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit EditorCheckBox(QWidget *parent = 0);
    QModelIndex index;
    void setIndex(const QModelIndex &index);

signals:
    void clicked_new(bool state,const QModelIndex &index);

public slots:
    void c_clicked();

};

#endif // EDITORCHECKBOX_H
