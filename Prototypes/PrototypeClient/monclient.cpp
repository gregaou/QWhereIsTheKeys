#include"monclient.h"
void MonClient::Connection(QString adr, QString port)
{
   _socket->abort();
   _socket->connectToHost(adr, port.toShort());
   _socket->write("Bonjour!");

}

void MonClient::deConnection()
{
    _socket->close();
}
