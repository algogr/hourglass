#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H

#include <Qt/QtGui>
#include <QItemDelegate>

class CheckBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit CheckBoxDelegate(QObject *parent = 0);
   QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
   // void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //int checkboxCol;

protected:
     //bool eventFilter ( QObject * editor, QEvent * event );
     //bool editorEvent ( QEvent * event, QAbstractItemModel * model, const QStyleOptionViewItem & option, const QModelIndex & index );

private:
    bool editor_clicked;
    bool editor_state;
    QMap <int,QWidget *> map;

signals:
    void transmit_diff(int diff);
    void editor_changed_state(bool state,const QModelIndex &index);
    void editor_spin_value(int value,const QModelIndex &index);

public slots:
    void echk_clicked(bool state,const QModelIndex& index);
    void espin_clicked(int value,const QModelIndex& index);
};

#endif // CHECKBOXDELEGATE_H
