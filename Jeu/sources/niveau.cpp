#include "sources/headers/niveau.h"

Niveau::Niveau(QGraphicsScene *scene)
{
	OjHeros *h = new OjHeros(30,30);
	_objets.append(h);

	/****************************************************************************/
	ObjetJeu *contourH = new OjPlateforme(0,0,scene->width(),10);
	ObjetJeu *contourG = new OjPlateforme(0,scene->height()-10,scene->width(),10);
	ObjetJeu *contourB = new OjPlateforme(0,0,10,scene->height());
	ObjetJeu *contourD = new OjPlateforme(scene->width()-10,0,10,scene->height());

	_objets.append(contourH);
	_objets.append(contourG);
	_objets.append(contourB);
	_objets.append(contourD);
}

OjHeros* Niveau::getHeros()
{
	return dynamic_cast<OjHeros*> (_objets[0]);
}

QList<ObjetJeu *> Niveau::getObjets()
{
	return _objets;
}

void Niveau::addObject(ObjetJeu *obj)
{
	_objets.append(obj);
}
