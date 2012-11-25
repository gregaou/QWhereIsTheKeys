#include "sources/headers/vue_jeu.h"
#include "ui_vue_jeu.h"

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

	h = new OjHeros(0,0);
	_scene.addItem(h);

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
