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
	ObjetJeu *g1			= new OjMechantSimple(90,120,QString(":/garde/g_l1.png"),QString(":/garde/g_l2.png"),QString(":/garde/g_r1.png"),QString(":/garde/g_r2.png"),true);

	ObjetJeu *p2			= new OjPlateforme(10,270,120,15);
	ObjetJeu *g2			= new OjMechantSimple(10,230,QString(":/garde/g_l1.png"),QString(":/garde/g_l2.png"),QString(":/garde/g_r1.png"),QString(":/garde/g_r2.png"),false);

	ObjetJeu *p3			= new OjPlateforme(40,380,160,15);
	ObjetJeu *g3			= new OjMechantSimple(40,340,QString(":/garde/g_l1.png"),QString(":/garde/g_l2.png"),QString(":/garde/g_r1.png"),QString(":/garde/g_r2.png"),true);

	ObjetJeu *p4			= new OjPlateforme(250,530,20,15);
	ObjetJeu *p5			= new OjPlateforme(300,500,80,15);
	ObjetJeu *p6			= new OjPlateforme(230,450,50,15);

	ObjetJeu *p7			= new OjPlateforme(450,400,400,15);
	ObjetJeu *s1			= new OjMechantSimple(440,370,QString(":/spider/s_l1.png"),QString(":/spider/s_l2.png"),QString(":/spider/s_r1.png"),QString(":/spider/s_r2.png"),true);
	ObjetJeu *s2			= new OjMechantSimple(780,370,QString(":/spider/s_l1.png"),QString(":/spider/s_l2.png"),QString(":/spider/s_r1.png"),QString(":/spider/s_r2.png"),false);

	ObjetJeu *p8			= new OjPlateforme(275,400,100,15);
	ObjetJeu *p9			= new OjPlateforme(700,350,50,15);
	ObjetJeu *p10			= new OjPlateforme(500,250,225,15);

	ObjetJeu *clef    = new OjClef(700,140);

	ObjetJeu *p11			 = new OjPlateforme(9,575,20,15);
	ObjetJeu *flamme1  = new OjFlamme(30,575);
	ObjetJeu *flamme2  = new OjFlamme(55,575);
	ObjetJeu *flamme3  = new OjFlamme(80,575);
	ObjetJeu *flamme4  = new OjFlamme(105,575);
	ObjetJeu *flamme5  = new OjFlamme(130,575);
	ObjetJeu *flamme6  = new OjFlamme(155,575);
	ObjetJeu *flamme7  = new OjFlamme(180,575);
	ObjetJeu *flamme8  = new OjFlamme(205,575);
	ObjetJeu *p12			 = new OjPlateforme(230,575,24,15);
	ObjetJeu *flamme11  = new OjFlamme(255,575);
	ObjetJeu *flamme21  = new OjFlamme(280,575);
	ObjetJeu *flamme31  = new OjFlamme(305,575);
	ObjetJeu *flamme41  = new OjFlamme(330,575);
	ObjetJeu *flamme51 = new OjFlamme(355,575);
	ObjetJeu *flamme61  = new OjFlamme(380,575);
	ObjetJeu *flamme71  = new OjFlamme(405,575);
	ObjetJeu *flamme81  = new OjFlamme(430,575);
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

	n->addObject(flamme1);
	n->addObject(flamme2);
	n->addObject(flamme3);
	n->addObject(flamme4);
	n->addObject(flamme5);
	n->addObject(flamme6);
	n->addObject(flamme7);
	n->addObject(flamme8);
	n->addObject(flamme11);
	n->addObject(flamme21);
	n->addObject(flamme31);
	n->addObject(flamme41);
	n->addObject(flamme51);
	n->addObject(flamme61);
	n->addObject(flamme71);
	n->addObject(flamme81);

	n->addObject(s1);
	n->addObject(s2);
	n->addObject(g1);
	n->addObject(g2);
	n->addObject(g3);

	ajouterUnNiveau(n);
}
