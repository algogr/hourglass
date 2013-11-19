#include "mainwindow.h"
#include "constants.h"
#include "config.h"
#include <QtCore>
#include <QtGui>
#include <QApplication>

QString g_HOST,g_USER,g_PASS,g_MAIL_FROM,g_MAIL_INVOICER,g_MAIL_SERVER,g_ASTERISK_SERVER,g_ASTERISK_EXTENSION;
QString g_ASTERISK_CONTEXT,g_ASTERISK_DIAL_PREFIX,g_ASTERISK_LOGIN,g_ASTERISK_SECRET,g_AST_MYSQL_USER;
QString g_AST_MYSQL_PASS,g_AST_MYSQL_CDR;
int g_ASTERISK_PORT,g_AST_MYSQL_PORT;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QFile file("configuration.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        Config * w=new Config(0,&file);
        w->exec();
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    g_HOST=in.readLine();
    g_USER=in.readLine();
    g_PASS=in.readLine();
    g_MAIL_FROM=in.readLine();
    g_MAIL_INVOICER=in.readLine();
    g_MAIL_SERVER=in.readLine();
    g_ASTERISK_SERVER=in.readLine();
    g_ASTERISK_PORT=in.readLine().toInt();
    g_ASTERISK_EXTENSION=in.readLine();
    g_ASTERISK_CONTEXT=in.readLine();
    g_ASTERISK_DIAL_PREFIX=in.readLine();
    g_ASTERISK_LOGIN=in.readLine();
    g_ASTERISK_SECRET=in.readLine();
    g_AST_MYSQL_PORT=in.readLine().toInt();
    g_AST_MYSQL_USER=in.readLine();
    g_AST_MYSQL_PASS=in.readLine();
    g_AST_MYSQL_CDR=in.readLine();


    file.close();

    MainWindow w;
    w.show();
    return a.exec();
}
