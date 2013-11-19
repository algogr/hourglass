#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include "constants.h"

namespace Ui {
    class Config;
}

class Config : public QDialog
{
    Q_OBJECT

public:
    explicit Config(QWidget *parent = 0,QFile *file=0);
    ~Config();

private:
    Ui::Config *ui;
    QFile *file;

private slots:
    void okPressed();
    void cancelPressed();

};

#endif // CONFIG_H
