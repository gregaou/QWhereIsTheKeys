#include "monthread.h"

MonThread::MonThread(int sDescriptor, QObject *parent) :
    QThread(parent),
    _sDescriptor(sDescriptor) {}

void MonThread::run()
{
    // thread start here
    qDebug() << _sDescriptor << " Starting thread !" ;
    _socket = new QTcpSocket();
    if(!_socket->setSocketDescriptor(_sDescriptor)){
        emit error(_socket->error());
        return;
    }

    connect(_socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(_socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << _sDescriptor << " Client connected";

    exec();
}

void MonThread::readyRead()
{
    QByteArray data = _socket->readAll();

    qDebug() << _sDescriptor << " Data in : " << data;

    _socket->write(data);
}

void MonThread::disconnected()
{
    qDebug() << _sDescriptor << " disconnected";

    _socket->deleteLater();
    exit(0);
}
