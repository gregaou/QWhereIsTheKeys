#ifndef OJ_PLATEFORME_H
#define OJ_PLATEFORME_H

#include <QString>

#include "sources/headers/objet_jeu.h"
#include "sources/headers/oj_heros.h"

class OjPlateforme : public ObjetJeu
{
public:
	explicit OjPlateforme(const qreal x, const qreal y, const qreal w ,
												const qreal h);

	void process();
	QString toString() { return QString("OjPlateforme"); }

};

#endif // OJ_PLATEFORME_H
