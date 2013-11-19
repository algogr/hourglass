#include "asterisk_callerid_monitor.h"

Asterisk_CallerID_Monitor::Asterisk_CallerID_Monitor(QObject *parent) :
    QObject(parent)
{
    QHostAddress addr(g_ASTERISK_SERVER);
    this->asterisk = new QTcpSocket;
    asterisk->connectToHost(addr,g_ASTERISK_PORT);
    //this->timer=new QTimer;
    connect(asterisk,SIGNAL(readyRead()),this,SLOT(asterisk_response()));
    //connect(timer,SIGNAL(timeout()),this,SLOT(check_status()));
    QTextStream str( asterisk );
    str << "ACTION: Login\r\nUsername: "+g_ASTERISK_LOGIN+"\r\nSecret: "+g_ASTERISK_SECRET+"\r\n\r\n";
    str.flush();
    str.reset();

}


void Asterisk_CallerID_Monitor::start_monitor()
{
    QTextStream str( asterisk );
    str << "ACTION: Login\r\nUsername: "+g_ASTERISK_LOGIN+"\r\nSecret: "+g_ASTERISK_SECRET+"\r\n\r\n";
    str.flush();
    str.reset();
}


void Asterisk_CallerID_Monitor::check_status()
{
    QTextStream str( asterisk );
        //str << "Action: Originate\r\nChannel: SIP/15\r\nExten: 96947613893\r\nContext: algo_DLPN_Internal\r\nPriority: 1\r\n\r\n";
    str << "Action: ExtensionState\r\nContext: "+g_ASTERISK_CONTEXT+"\r\nExten: "+g_ASTERISK_EXTENSION+"\r\nActionID: 1\r\n\r\n";
    str.flush();
    str.reset();
}


void Asterisk_CallerID_Monitor::asterisk_response()
{
    QTextStream in(asterisk);
    QString response;
            //=in.readAll();
    while(!in.atEnd())
    {
        response=in.readLine();
        if (response.contains("SubEvent: Begin"))
        {
            in.readLine();
            QString dest=in.readLine();
            if (dest.contains("Destination: "+g_ASTERISK_EXTENSION))

            {

                QString callerid=in.readLine();
                callerid=callerid.mid(callerid.compare(":")+4,15);
                emit incoming_call(callerid);

            }
        }


}
}
