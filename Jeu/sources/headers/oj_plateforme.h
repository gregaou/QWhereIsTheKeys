#ifndef OJ_PLATEFORME_H
#define OJ_PLATEFORME_H

#include "sources/headers/objet_jeu.h"
#include "sources/headers/oj_heros.h"

class OjPlateforme : public ObjetJeu
{
public:
		explicit OjPlateforme(const qreal x, const qreal y, const qreal w ,
										 const qreal h);

		void process();

		void herosCollision(OjHeros *h);

};

#endif // OJ_PLATEFORME_H