#include "sources/headers/niveau.h"

Niveau::Niveau(QGraphicsScene *scene)
{
	OjHeros *h = new OjHeros(30,30);
	_objets.append(h);

	ObjetJeu *contourH = new OjPlateforme(0,0,scene->width(),10);
	ObjetJeu *contourG = new OjPlateforme(0,scene->height()-10,scene->width(),10);
	ObjetJeu *contourB = new OjPlateforme(0,0,10,scene->height());
	ObjetJeu *contourD = new OjPlateforme(scene->width()-10,0,10,scene->height());



	_objets.append(contourH);
	_objets.append(contourG);
	_objets.append(contourB);
	_objets.append(contourD);

	ObjetJeu *p1 = new OjPlateforme(150,550,200,15);
	ObjetJeu *p2 = new OjPlateforme(120,500,200,15);
	ObjetJeu *p3 = new OjPlateforme(10,50,60,15);
	ObjetJeu *s1 = new OjSpider(120,400,true);
	ObjetJeu *s2 = new OjGarde(320,400,false);


	_objets.append(p1);
	_objets.append(p2);
	_objets.append(p3);
	_objets.append(s1);
	_objets.append(s2);
}

OjHeros* Niveau::getHeros()
{
	return dynamic_cast<OjHeros*> (_objets[0]);
}

QList<ObjetJeu *> Niveau::getObjets()
{
	return _objets;
}
