#include "sources/headers/oj_mechant_simple.h"

#include <QGraphicsScene>

#define GRAVITE 5
#define PGRAVITE 0.2

#define NB_FPS_ANIMATION(X)  ((1000/20)/X)

OjMechantSimple::OjMechantSimple(const qreal x, const qreal y, QString left1,QString left2,QString right1,QString right2, const bool deplacement=true) :
	ObjetJeuMobile(x,y,loadListPixmap(left1,left2,right1,right2)), counter(0),deplacement(deplacement)
{
	if(deplacement)
			droite();
	else
		gauche();

}

QList<QPixmap> OjMechantSimple::loadListPixmap(QString l1,QString l2,QString r1,QString r2) const
{
	QList<QPixmap> animation;
	animation.append(QPixmap(l1));
	animation.append(QPixmap(l2));
	animation.append(QPixmap(r1));
	animation.append(QPixmap(r2));

	return animation;
}

void OjMechantSimple::process()
{

	_dy = (_dy < GRAVITE)? _dy+PGRAVITE : GRAVITE;

	animation();
	QList<QGraphicsItem*> listCollision = collidingItems();

	for(int i=0;i<listCollision.size();++i)
	{
		emit collision(dynamic_cast<ObjetJeu*>(this),dynamic_cast<ObjetJeu*>(listCollision.at(i)));
	}
}


void OjMechantSimple::droite()
{
		_dx = 2;
}

void OjMechantSimple::gauche()
{
		_dx = -2;
}


void OjMechantSimple::animation()
{
	counter++;
	if(_dx > 0 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 2)
		setFrame(2);
	else if(_dx > 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 3)
		setFrame(3);
	else if(_dx < 0 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 0)
		setFrame(0);
	else if(_dx < 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 1)
		setFrame(1);
}


