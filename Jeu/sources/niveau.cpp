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
	/****************************************************************************/
	_objets.append(contourH);
	_objets.append(contourG);
	_objets.append(contourB);
	_objets.append(contourD);

	ObjetJeu *depart	= new OjPlateforme(10,50,60,15);
	ObjetJeu *mur			= new OjPlateforme(200,0,15,395);
	ObjetJeu *mur2		= new OjPlateforme(275,0,15,45);
	ObjetJeu *mur3		= new OjPlateforme(275,65,15,335);
	ObjetJeu *p1			= new OjPlateforme(80,160,120,15);
	ObjetJeu *g1			= new OjGarde(90,120,true);

	ObjetJeu *p2			= new OjPlateforme(10,270,120,15);
	ObjetJeu *g2			= new OjGarde(10,230,false);

	ObjetJeu *p3			= new OjPlateforme(40,380,160,15);
	ObjetJeu *g3			= new OjGarde(40,340,false);

	ObjetJeu *p4			= new OjPlateforme(200,550,80,15);
	ObjetJeu *p5			= new OjPlateforme(300,500,80,15);
	ObjetJeu *p6			= new OjPlateforme(230,450,50,15);

	ObjetJeu *p7			= new OjPlateforme(450,400,400,15);
	ObjetJeu *s1			= new OjSpider(440,370,true);
	ObjetJeu *s2			= new OjSpider(780,370,false);

	ObjetJeu *p8			= new OjPlateforme(275,400,100,15);
	ObjetJeu *p9			= new OjPlateforme(700,350,50,15);
	ObjetJeu *p10			= new OjPlateforme(500,250,225,15);

	ObjetJeu *clef    = new OjClef(700,140);




	_objets.append(depart);
	_objets.append(mur);
	_objets.append(mur2);
	_objets.append(mur3);
	_objets.append(p1);
	_objets.append(p2);
	_objets.append(p3);
	_objets.append(p4);
	_objets.append(p5);
	_objets.append(p6);
	_objets.append(p7);
	_objets.append(p8);
	_objets.append(p9);
	_objets.append(p10);

	_objets.append(clef);

	_objets.append(s1);
	_objets.append(s2);
	_objets.append(g1);
	_objets.append(g2);
	_objets.append(g3);

}

OjHeros* Niveau::getHeros()
{
	return dynamic_cast<OjHeros*> (_objets[0]);
}

QList<ObjetJeu *> Niveau::getObjets()
{
	return _objets;
}
