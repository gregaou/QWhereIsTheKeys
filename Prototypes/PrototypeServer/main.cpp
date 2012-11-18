#include <QtCore/QCoreApplication>
#include "monserveur.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	MonServeur server;
	server.startServer();

	return a.exec();
}
