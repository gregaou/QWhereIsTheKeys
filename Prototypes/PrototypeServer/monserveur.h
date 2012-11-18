#ifndef MONSERVEUR_H
#define MONSERVEUR_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class MonServeur : public QTcpServer
{
	Q_OBJECT
public:
	explicit MonServeur(QObject *parent = 0);
	void startServer();

signals:

public slots:
	void dataIncoming();
	void clientDisconnected();

protected slots:
	void newClientConnection();

private:
	void sendAll (const QString &message);
	QList<QTcpSocket *> _clients;
	quint16 _sizeMessage;

};

#endif // MONSERVEUR_H
