#include "sources/headers/vue_jeu.h"
#include "ui_vue_jeu.h"

#define FPS_50 20

VueJeu::VueJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueJeu),
	_mJeu(ModelJeu::getInstance()),
	_mNiveau(ModelNiveau::getInstance()),
	_scene(0,0,798,598,this),
	_view(&_scene,this)

{
	_view.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	_view.setFocus();

	_ui->setupUi(this);
	_ui->LayoutJeu->addWidget(&_view);

	//_scene.setItemIndexMethod(QGraphicsScene::NoIndex);

	cOj = new CollisionOjHeros();
	Niveau *n = new Niveau(&_scene);
	_mNiveau->ajouterUnNiveau(n);
	n = _mNiveau->getNiveaux()[_mJeu->getNiveauSelectionne()];
	QList<ObjetJeu*> objets = n->getObjets();
	h = n->getHeros();
	for(int i = 0; i < objets.size(); i++)
	{
		_scene.addItem(objets[i]);
		//if(dynamic_cast<ObjetJeuMobile*> (objets[i]))
			connect(objets[i],SIGNAL(collision(ObjetJeu*,ObjetJeu*)),this,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	}
	connexionAffichage();

	//_view.setBackgroundBrush(QImage(":/fond/fond.png"));

	startTimer(FPS_50);
}

void VueJeu::collision(ObjetJeu *oj1, ObjetJeu *oj2)
{
	cOj->collision(oj1,oj2);
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
