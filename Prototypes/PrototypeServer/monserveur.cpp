#include "monserveur.h"

MonServeur::MonServeur(QObject *parent) :
	QTcpServer(parent)
{
}

void MonServeur::startServer()
{
	qDebug() << "Start server :";
			if(!listen(QHostAddress::Any,1234))
	{
		qDebug() << "Could not start server";
	}
	else
	{
		qDebug() << "Listening on port : " << serverPort();
	}
}

void MonServeur::incomingConnection(int sDescriptor)
{
	qDebug() << sDescriptor <<" New Client";

	QTcpSocket *newClient;
	newClient->setSocketDescriptor(sDescriptor);

	_clients << newClient;

	connect(newClient,SIGNAL(readyRead()),this,SLOT(dataIncoming()));
	connect(newClient,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));
}

void MonServeur::sendAll(const QString &message)
{
		QByteArray paquet;
		QDataStream out(&paquet, QIODevice::WriteOnly);

		out << (quint16) 0;
		out << message;
		out.device()->seek(0);
		out << (quint16) (paquet.size() - sizeof(quint16));

		for (int i = 0; i < _clients.size(); i++)
		{
				_clients[i]->write(paquet);
		}
}

void MonServeur::clientDisconnected()
{
	sendAll("Un client vient de se déconnecter");

	QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
	if (socket == 0)
			return;

	qDebug() << socket->socketDescriptor() << " disconnected";

	_clients.removeOne(socket);
	socket->deleteLater();
}

void MonServeur::dataIncoming()
{
		QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
		if (socket == 0)
				return;

		QDataStream in(socket);

		if (_sizeMessage == 0)
		{
				if (socket->bytesAvailable() < (int)sizeof(quint16))
						 return;

				in >> _sizeMessage;
		}

		if (socket->bytesAvailable() < _sizeMessage)
				return;

		QString message;
		in >> message;

		sendAll(message);

		_sizeMessage = 0;
}
