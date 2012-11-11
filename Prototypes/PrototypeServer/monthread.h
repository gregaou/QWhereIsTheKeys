#ifndef MONTHREAD_H
#define MONTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class MonThread : public QThread
{
    Q_OBJECT
public:
    explicit MonThread(int sDescriptor, QObject *parent = 0);
    void run();
    
signals:
    void error(QTcpSocket::SocketError error);

    
public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *_socket;
    int _sDescriptor;
    
};

#endif // MONTHREAD_H
