#include "vue_jeu.h"
#include "ui_vue_jeu.h"
#include <QDebug>
#include <QTimer>

VueJeu::VueJeu(QWidget *parent) :
	QWidget(parent),
	_scene(0, 0, 800, 600,this),
	_view(&_scene, this)
{
	ObjetJeu *p = new Plateforme(0,550,200,25);
	c = new Carre(10,10);
	_scene.addItem(c);
	//_scene.addItem(p);

	_view.setBackgroundBrush(QImage(":/fond/fond"));

	QTimer * timer = new QTimer();
	connect(timer,SIGNAL(timeout()),&_scene,SLOT(advance()));
	timer->start(15);
}

VueJeu::~VueJeu()
{
}


void VueJeu::keyPressEvent(QKeyEvent *event)
{
	if(event->isAutoRepeat())
	{
		event->ignore();
		return;
	}

	switch(event->key())
	{
		case Qt::Key_Right :
			c->droite(true);
			break;
		case Qt::Key_Left :
			c->gauche(true);
			break;
		case Qt::Key_Space :
			c->saut();
			break;

	}
}

void VueJeu::keyReleaseEvent(QKeyEvent *event)
{

	if(event->isAutoRepeat())
	{
		event->ignore();
		return;
	}

	switch(event->key())
	{
		case Qt::Key_Right :
			c->gauche(false);
			break;
		case Qt::Key_Left :
			c->gauche(false);
			break;
	}
}
