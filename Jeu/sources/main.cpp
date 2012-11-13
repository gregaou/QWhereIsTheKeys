#include <QtGui/QApplication>
#include <QDebug>
#include <QTextCodec>
#include <QTranslator>
#include <QLibraryInfo>
#include "sources/headers/qwitk.h"
#include "sources/headers/model_profil.h"

int main(int argc, char *argv[])
{

	/* Encodage UTF-8 , prise en charge des accents */
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	QApplication a(argc, argv);

	/* Traduction du programme en français */
	QTranslator translator;
	translator.load("qt_fr_FR",
									QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	a.installTranslator(&translator);


	QWITK w;
	w.show();

	return a.exec();
}
