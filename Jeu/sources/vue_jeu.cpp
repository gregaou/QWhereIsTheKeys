#include "sources/headers/vue_jeu.h"
#include "ui_vue_jeu.h"

#define FPS_50 20

VueJeu::VueJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueJeu),
	_mJeu(ModelJeu::getInstance()),
	_mNiveau(ModelNiveau::getInstance()),
	_scene(0,0,798,598,this),
	_view(&_scene,this),
	_viewPause()
{
	_view.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	_ui->setupUi(this);
	_ui->LayoutJeu->addWidget(&_view);
	_ui->LayoutJeu->addWidget(&_viewPause);
	_viewPause.hide();
	grabKeyboard();

	_scene.setItemIndexMethod(QGraphicsScene::NoIndex);

	cOj = new CollisionOjHeros();
	cOj->setNext(new CollisionOjSpider());
	cOj->setNext(new CollisionOjGarde());
	//cOj->setNext(new CollisionOjGarde());
	// Et les mecs il faut faire une methode "getLast();" !!!JB

	Niveau *n = new Niveau(&_scene);
	_mNiveau->ajouterUnNiveau(n);
	n = _mNiveau->getNiveaux()[_mJeu->getNiveauSelectionne()];
	QList<ObjetJeu*> objets = n->getObjets();
	h = n->getHeros();
	for(int i = 0; i < objets.size(); i++)
	{
		_scene.addItem(objets[i]);
		connect(objets[i],SIGNAL(collision(ObjetJeu*,ObjetJeu*)),this,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	}
		connexionAffichage();

	demarrerTimer();
}

void VueJeu::collision(ObjetJeu *oj1, ObjetJeu *oj2)
{
	cOj->collision(oj1,oj2);
}

void VueJeu::resumePause()
{
	_viewPause.hide();
	_view.show();
	demarrerTimer();
}

VueJeu::~VueJeu()
{
	delete _ui;
}

void VueJeu::connexionAffichage()
{
	connect(&_viewPause,SIGNAL(reprendrePartie()),this,SLOT(resumePause()));
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
		case Qt::Key_Right: case Qt::Key_D :
			monH->droite(true);
			break;
		case Qt::Key_Left: case Qt::Key_Q :
			monH->gauche(true);
			break;
		case Qt::Key_Up:
		case Qt::Key_Space:
			monH->saut();
			break;
		case Qt::Key_P:
			setPause();
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
		case Qt::Key_Right: case Qt::Key_D :
			monH->droite(false);
			break;
		case Qt::Key_Left: case Qt::Key_Q :
			monH->gauche(false);
			break;
	}
}

void VueJeu::timerEvent(QTimerEvent *)
{

	Niveau *n = _mNiveau->getNiveaux()[_mJeu->getNiveauSelectionne()];
	QList<ObjetJeu*> objets = n->getObjets();

	_scene.advance();

	for(int i = 0; i < objets.size(); i++){

		objets[i]->process();
	}
}

void VueJeu::setPause()
{
	stopperTimer();
	_view.hide();
	_viewPause.show();
}

void VueJeu::demarrerTimer()
{
	_timer = startTimer(FPS_50);
}

void VueJeu::stopperTimer()
{
	killTimer(_timer);
}
