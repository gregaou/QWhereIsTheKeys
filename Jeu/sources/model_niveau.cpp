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
	ObjetJeu *mur2		= new OjPlateforme(275,0,15,45);
	ObjetJeu *mur3		= new OjPlateforme(275,65,15,340);
	ObjetJeu *p1			= new OjPlateforme(80,160,120,15);
	ObjetJeu *g1			= GARDE(90,120,true);

	ObjetJeu *p2			= new OjPlateforme(10,270,120,15);
	ObjetJeu *g2			= GARDE(10,230,false);

	ObjetJeu *p3			= new OjPlateforme(40,380,160,15);
	ObjetJeu *g3			= GARDE(40,340,true);

	ObjetJeu *p4			= new OjPlateforme(250,530,20,15);
	ObjetJeu *p5			= new OjPlateforme(300,500,80,15);
	ObjetJeu *p6			= new OjPlateforme(230,450,50,15);

	ObjetJeu *p7			= new OjPlateforme(450,400,400,15);
	ObjetJeu *s1			= SPIDER(440,370,true);
	ObjetJeu *s2			= SPIDER(780,370,false);

	ObjetJeu *p8			= new OjPlateforme(275,400,100,15);
	ObjetJeu *p9			= new OjPlateforme(700,350,50,15);
	ObjetJeu *p10			= new OjPlateforme(500,250,225,15);

	ObjetJeu *clef    = new OjClef(700,140);

	ObjetJeu *p11			 = new OjPlateforme(9,575,20,15);
	ObjetJeu *lave1  = LAVE(30,575);
	ObjetJeu *lave2  = LAVE(55,575);
	ObjetJeu *lave3  = LAVE(80,575);
	ObjetJeu *lave4  = LAVE(105,575);
	ObjetJeu *lave5  = LAVE(130,575);
	ObjetJeu *lave6  = LAVE(155,575);
	ObjetJeu *lave7  = LAVE(180,575);
	ObjetJeu *lave8  = LAVE(205,575);
	ObjetJeu *p12			 = new OjPlateforme(230,575,24,15);
	ObjetJeu *lave11  = LAVE(255,575);
	ObjetJeu *lave21  = LAVE(280,575);
	ObjetJeu *lave31  = LAVE(305,575);
	ObjetJeu *lave41  = LAVE(330,575);
	ObjetJeu *lave51	= LAVE(355,575);
	ObjetJeu *lave61  = LAVE(380,575);
	ObjetJeu *lave71  = LAVE(405,575);
	ObjetJeu *lave81  = LAVE(430,575);
	ObjetJeu *p13			 = new OjPlateforme(455,575,20,15);

	ObjetJeu *p14			 = new OjPlateforme(100,530,20,15);



	n->addObject(depart);
	n->addObject(mur);
	n->addObject(mur2);
	n->addObject(mur3);
	n->addObject(p1);
	n->addObject(p2);
	n->addObject(p3);
	n->addObject(p4);
	n->addObject(p5);
	n->addObject(p6);
	n->addObject(p7);
	n->addObject(p8);
	n->addObject(p9);
	n->addObject(p10);
	n->addObject(p11);
	n->addObject(p12);
	n->addObject(p13);
	n->addObject(p14);


	n->addObject(clef);

	n->addObject(lave1);
	n->addObject(lave2);
	n->addObject(lave3);
	n->addObject(lave4);
	n->addObject(lave5);
	n->addObject(lave6);
	n->addObject(lave7);
	n->addObject(lave8);
	n->addObject(lave11);
	n->addObject(lave21);
	n->addObject(lave31);
	n->addObject(lave41);
	n->addObject(lave51);
	n->addObject(lave61);
	n->addObject(lave71);
	n->addObject(lave81);

	n->addObject(s1);
	n->addObject(s2);
	n->addObject(g1);
	n->addObject(g2);
	n->addObject(g3);

	ajouterUnNiveau(n);
}
