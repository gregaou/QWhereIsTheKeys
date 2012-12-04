#include "sources/headers/model_niveau.h"

void ModelNiveau::ajouterUnNiveau(Niveau *n)
{
	_niveaux.append(n);
}

QList<Niveau*> ModelNiveau::getNiveaux()
{
	return _niveaux;
}

void ModelNiveau::setScene(QGraphicsScene* scene)
{
	_scene = scene;
}

QGraphicsScene *ModelNiveau::getScene()
{
	return _scene;
}

void ModelNiveau::chargerNiveaux()
{
	Niveau* n = new Niveau(_scene);

	ObjetJeu *depart	= new OjPlateforme(10,50,60,15);
	ObjetJeu *mur			= new OjPlateforme(200,0,15,395);
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
	ObjetJeu *p8			= new OjPlateforme(300,400,100,15);
	ObjetJeu *p9			= new OjPlateforme(700,350,50,15);
	ObjetJeu *key = new OjClef(700,320);

	n->addObject(depart);
	n->addObject(mur);
	n->addObject(p1);
	n->addObject(p2);
	n->addObject(p3);
	n->addObject(p4);
	n->addObject(p5);
	n->addObject(p6);
	n->addObject(p7);
	n->addObject(p8);
	n->addObject(p9);
	n->addObject(key);
	n->addObject(s1);
	n->addObject(s2);
	n->addObject(g1);
	n->addObject(g2);
	n->addObject(g3);
	ajouterUnNiveau(n);


}
