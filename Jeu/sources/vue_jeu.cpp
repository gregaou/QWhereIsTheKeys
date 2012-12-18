#include "sources/headers/vue_jeu.h"
#include "ui_vue_jeu.h"

#define FPS_50 19

VueJeu::VueJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueJeu),
	_mJeu(ModelJeu::getInstance()),
	_mNiveau(ModelNiveau::getInstance()),
	_scene(0,0,798,598,this),
	_view(&_scene,this),
	_viewPause(),
	_temps(0,0,0,0)
{
	_view.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	_ui->setupUi(this);
	_ui->LayoutJeu->addWidget(&_view);
	_ui->LayoutJeu->addWidget(&_viewPause);
	_viewPause.hide();
	grabKeyboard();

	_scene.setItemIndexMethod(QGraphicsScene::NoIndex);

	_cOj = new CollisionOjHeros(this);
	_cOj->setNext(new CollisionOjMechantSimple);
	_cOj->setNext(new CollisionOjMechantTourne);

	_mNiveau->setScene(&_scene);
	_mNiveau->chargerNiveaux();
	Niveau *n;
	n = _mNiveau->getNiveaux()[_mJeu->getNiveauSelectionne()];
	QList<ObjetJeu*> objets = n->getObjets();
	_h = n->getHeros();
	for(int i = 0; i < objets.size(); i++)
	{
		_scene.addItem(objets[i]);
		connect(objets[i],SIGNAL(collision(ObjetJeu*,ObjetJeu*)),this,SLOT(collision(ObjetJeu*,ObjetJeu*)));
	}
		connexionAffichage();

	_tempsItem.setPos(700,20);
	_scene.addItem(&_tempsItem);
	demarrerTimer();
}

void VueJeu::collision(ObjetJeu *oj1, ObjetJeu *oj2)
{
	_cOj->collision(oj1,oj2);
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
	delete _h;
	delete _cOj;
	_mNiveau->kill();
}

void VueJeu::connexionAffichage()
{
	connect(&_viewPause,SIGNAL(reprendrePartie()),this,SLOT(resumePause()));
	connect(&_viewPause,SIGNAL(retourMenu()),this,SLOT(retourMenu()));
}

void VueJeu::retourMenu()
{
	emit setVue(VueJeuMenu::toString());
}

void VueJeu::collisionClef()
{
	emit setVue(VueJeuNiveauTermine::toString());
}

QString VueJeu::toString()
{
	return QString("VueJeu");
}

void VueJeu::keyPressEvent(QKeyEvent *event)
{
	OjHeros *monH = dynamic_cast<OjHeros*>(_h);

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
	OjHeros *monH = dynamic_cast<OjHeros*>(_h);
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
	_temps = _temps.addMSecs(FPS_50);
	Niveau *n = _mNiveau->getNiveaux()[_mJeu->getNiveauSelectionne()];
	QList<ObjetJeu*> objets = n->getObjets();

	_scene.advance();
	_tempsItem.setPlainText(_temps.toString("hh:mm:ss:zzz"));

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
