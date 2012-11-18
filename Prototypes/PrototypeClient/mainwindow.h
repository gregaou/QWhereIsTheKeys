#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:

	void dataIncoming();
	void connected();
	void disconnected();
	void errorSocket(QAbstractSocket::SocketError error);

	void on_boutonConnexion_clicked();

	void on_boutonDeconnexion_clicked();

	void on_boutonEnvoyer_clicked();

private:
	Ui::MainWindow *_ui;
	QTcpSocket *_s;

	quint16 _sizeMessage;

	void connectedState(bool state);
};

#endif // MAINWINDOW_H
