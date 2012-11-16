#include "vue_jeu.h"
#include "ui_vue_jeu.h"
#include <QDebug>
#include <QTimer>

VueJeu::VueJeu(QWidget *parent) :
	QWidget(parent),
	_scene(0, 0, 800, 600,this),
	_view(&_scene, this)
{
	c = new Carre();
	_scene.addItem(c);

	QTimer * timer = new QTimer();
	connect(timer,SIGNAL(timeout()),&_scene,SLOT(advance()));
	timer->start(15);
}

VueJeu::~VueJeu()
{
}


void VueJeu::keyPressEvent(QKeyEvent *event)
{
	switch(event->key())
	{
		case Qt::Key_Up :
			c->setDy(-1);
			break;
		case Qt::Key_Down :
			c->setDy(1);
			break;
		case Qt::Key_Right :
			c->setDx(1);
			break;
		case Qt::Key_Left :
			c->setDx(-1);
			break;

	}
}

void VueJeu::keyReleaseEvent(QKeyEvent *event)
{
	switch(event->key())
	{
		case Qt::Key_Up :
			c->setDy(0);
			break;
		case Qt::Key_Down :
			c->setDy(0);
			break;
		case Qt::Key_Right :
			c->setDx(0);
			break;
		case Qt::Key_Left :
			c->setDx(0);
			break;
	}
}
