#ifndef ASTERISK_CALLERID_MONITOR_H
#define ASTERISK_CALLERID_MONITOR_H

#include <QObject>
#include <QtNetwork>
#include "constants.h"
extern QString g_ASTERISK_SERVER,g_ASTERISK_EXTENSION,g_ASTERISK_CONTEXT,g_ASTERISK_LOGIN,g_ASTERISK_SECRET;
extern int g_ASTERISK_PORT;
class Asterisk_CallerID_Monitor : public QObject
{
    Q_OBJECT
public:
    explicit Asterisk_CallerID_Monitor(QObject *parent = 0);
    void start_monitor();

private:
    QTcpSocket *asterisk;



signals:
    void incoming_call(QString callerid);

public slots:

private slots:
    void check_status();
    void asterisk_response();
};

#endif // ASTERISK_CALLERID_MONITOR_H
