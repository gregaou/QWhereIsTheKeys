#include "sources/headers/oj_spider.h"

#include <QDebug>
#include <QGraphicsScene>

#define GRAVITE 5
#define PGRAVITE 0.2

#define NB_FPS_ANIMATION(X)  ((1000/20)/X)

OjSpider::OjSpider(const qreal x, const qreal y, const bool deplacement) :
	ObjetJeuMobile(x,y,loadListPixmap()), counter(0),deplacement(deplacement)
{
	if(deplacement)
		droite();
	else
		gauche();
}

QList<QPixmap> OjSpider::loadListPixmap() const
{
	QList<QPixmap> animation;
	animation.append(QPixmap(":/spider/s_l1.png"));
	animation.append(QPixmap(":/spider/s_l2.png"));
	animation.append(QPixmap(":/spider/s_r1.png"));
	animation.append(QPixmap(":/spider/s_r2.png"));
	return animation;
}

void OjSpider::process()
{

	_dy = (_dy < GRAVITE)? _dy+PGRAVITE : GRAVITE;

	animation();
	QList<QGraphicsItem*> listCollision = collidingItems();

	for(int i=0;i<listCollision.size();++i)
	{
		emit collision(dynamic_cast<ObjetJeu*>(this),dynamic_cast<ObjetJeu*>(listCollision.at(i)));
	}
}


void OjSpider::droite()
{
		_dx = 2;
}

void OjSpider::gauche()
{
		_dx = -2;
}


void OjSpider::animation()
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
