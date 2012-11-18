#ifndef MONCLIENT_H
#define MONCLIENT_H

#include <QTcpSocket>
#include <QString>

class MonClient
{

public:
    void Connection(QString adr, QString port);
    void deConnection();

    explicit MonClient(QString adr, QString port)
    {
        _socket = new QTcpSocket();
        Connection(adr, port);
    }
    protected:
    QTcpSocket * _socket;


};

#endif // MONCLIENT_H
