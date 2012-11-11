#include "monserveur.h"

MonServeur::MonServeur(QObject *parent) :
    QTcpServer(parent)
{
}

void MonServeur::startServer()
{
    if(!listen(QHostAddress::Any,1234))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening..." << serverAddress() << serverPort();
    }
}

void MonServeur::incomingConnection(int sDescriptor)
{
    qDebug() << sDescriptor << " Connecting...";
    MonThread *thread = new MonThread(sDescriptor,this);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();

}
