#include "sources/headers/vue_jeu.h"
#include "ui_vue_jeu.h"

#include "sources/headers/collision_oj.h"
#include "sources/headers/collision_oj_heros.h"

#define FPS_50 20

VueJeu::VueJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueJeu),
	_mJeu(ModelJeu::getInstance()),
	_scene(0,0,798,598,this),
	_view(&_scene,this)

{
	_view.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	_view.setFocus();

	_ui->setupUi(this);
	_ui->LayoutJeu->addWidget(&_view);

	CollisionOj *cOj = new CollisionOjHeros();

	ObjetJeu *p = new OjPlateforme(150,550,200,15);
	ObjetJeu *p6 = new OjPlateforme(120,500,200,15);
	ObjetJeu *p7 = new OjPlateforme(170,420,200,15);
	ObjetJeu *p8 = new OjPlateforme(120,370,200,15);
	_scene.addItem(p);

	ObjetJeu *p2 = new OjPlateforme(0,0,_scene.width(),10);
	ObjetJeu *p3 = new OjPlateforme(0,_scene.height()-10,_scene.width(),10);
	ObjetJeu *p4 = new OjPlateforme(0,0,10,_scene.height());
	ObjetJeu *p5 = new OjPlateforme(_scene.width()-10,0,10,_scene.height());

	_scene.addItem(p2);
	_scene.addItem(p3);
	_scene.addItem(p4);
	_scene.addItem(p5);
	_scene.addItem(p6);
	_scene.addItem(p7);
	_scene.addItem(p8);

	h = new OjHeros(25,25);
	_scene.addItem(h);

	connect(h,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	connect(p,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	connect(p2,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	connect(p3,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	connect(p4,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	connect(p5,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	connect(p6,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	connect(p7,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	connect(p8,SIGNAL(collision(ObjetJeu*,ObjetJeu*)),cOj,SLOT(collision(ObjetJeu*,ObjetJeu*)));

	qDebug() ;
	connexionAffichage();

	//_view.setBackgroundBrush(QImage(":/fond/fond.png"));

	startTimer(FPS_50);
}

VueJeu::~VueJeu()
{
	delete _ui;
}


void VueJeu::connexionAffichage()
{
}

QString VueJeu::toString()
{
	return QString("VueJeu");
}

void VueJeu::keyPressEvent(QKeyEvent *event)
{
	if(event->isAutoRepeat())
		event->ignore();

	OjHeros *monH = dynamic_cast<OjHeros*>(h);

	switch(event->key())
	{
		case Qt::Key_Right:
			monH->droite(true);
			break;
		case Qt::Key_Left:
			monH->gauche(true);
			break;
		case Qt::Key_Space:
			monH->saut();
			break;

	}
}

void VueJeu::keyReleaseEvent(QKeyEvent *event)
{
	if(event->isAutoRepeat())
		event->ignore();


	OjHeros *monH = dynamic_cast<OjHeros*>(h);
	switch(event->key())
	{
		case Qt::Key_Right:
			monH->droite(false);
			break;
		case Qt::Key_Left:
			monH->gauche(false);
			break;
	}
}

void VueJeu::timerEvent(QTimerEvent *)
{
	_scene.advance();

	h->process();
}
