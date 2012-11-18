#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	_ui(new Ui::MainWindow)
{
	_ui->setupUi(this);

	_s = new QTcpSocket(this);

	connect(_s, SIGNAL(readyRead()), this, SLOT(dataIncoming()));
	connect(_s, SIGNAL(connected()), this, SLOT(connected()));
	connect(_s, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(_s, SIGNAL(error(QAbstractSocket::SocketError)), this,
					SLOT(errorSocket(QAbstractSocket::SocketError)));

	_sizeMessage = 0;
}

MainWindow::~MainWindow()
{
	delete _ui;
}

void MainWindow::on_boutonConnexion_clicked()
{
	_ui->chat->append("Try to connect");
	_ui->boutonConnexion->setEnabled(false);

	_s->abort();
	_s->connectToHost(_ui->adresseServer->text(),
										_ui->portServer->text().toInt());
}

void MainWindow::connected()
{
	_ui->chat->append("Connected !");
	connectedState(true);
}

void MainWindow::disconnected()
{
	_ui->chat->append("Disconnected");
	connectedState(false);
}

void MainWindow::errorSocket(QAbstractSocket::SocketError error)
{
	switch(error)
	{
		case QAbstractSocket::HostNotFoundError:
			_ui->chat->append("Server not found !");
			break;
		case QAbstractSocket::ConnectionRefusedError:
			_ui->chat->append("Server refuse the connection !");
			break;
		case QAbstractSocket::RemoteHostClosedError:
			_ui->chat->append("Server interrompt the connection !");
			break;
		default:
			_ui->chat->append("Error :" + _s->errorString());
			break;
	}

	connectedState(false);
}

void MainWindow::connectedState(bool state)
{
	_ui->boutonDeconnexion->setEnabled(state);
	_ui->boutonConnexion->setEnabled(!state);
	_ui->pseudoClient->setEnabled(!state);
	_ui->adresseServer->setEnabled(!state);
	_ui->portServer->setEnabled(!state);
	_ui->chat->setEnabled(state);
	_ui->message->setEnabled(state);
	_ui->boutonEnvoyer->setEnabled(state);
}

void MainWindow::dataIncoming()
{
	QDataStream in(_s);

	if (_sizeMessage == 0)
	{
		if (_s->bytesAvailable() < (int)sizeof(quint16))
			return;

		in >> _sizeMessage;
	}

	if (_s->bytesAvailable() < _sizeMessage)
		return;

	QString messageRecu;
	in >> messageRecu;

	_ui->chat->append(messageRecu);

	_sizeMessage = 0;

}

void MainWindow::on_boutonDeconnexion_clicked()
{
	_s->close();
}

void MainWindow::on_boutonEnvoyer_clicked()
{
	QByteArray paquet;
	QDataStream out(&paquet, QIODevice::WriteOnly);

	out << (quint16) 0;
	out << _ui->pseudoClient->text() + " : " +_ui->message->text();
	out.device()->seek(0);
	out << (quint16) (paquet.size() - sizeof(quint16));

	_s->write(paquet);
	_ui->message->clear();
}
