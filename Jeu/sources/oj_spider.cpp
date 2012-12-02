#include "sources/headers/oj_spider.h"

#include <QDebug>
#include <QGraphicsScene>

#define GRAVITE 5
#define PGRAVITE 0.2

#define NB_FPS_ANIMATION(X)  ((1000/20)/X)

OjSpider::OjSpider(const qreal x, const qreal y) :
	ObjetJeuMobile(x,y,loadListPixmap()), counter(0), deplacementDroite(true)
{}

QList<QPixmap> OjSpider::loadListPixmap() const
{
	QList<QPixmap> animation;
//	animation.append(QPixmap(":/spider/spd_lf1.png"));
//	animation.append(QPixmap(":/spider/spd_lf2.png"));
//	animation.append(QPixmap(":/spider/spd_rt1.png"));
//	animation.append(QPixmap(":/spider/spd_rt2.png"));
	animation.append(QPixmap(":/heros/h_d1.png"));
	animation.append(QPixmap(":/heros/h_d2.png"));
	animation.append(QPixmap(":/heros/h_l1.png"));
	animation.append(QPixmap(":/heros/h_l2.png"));
	animation.append(QPixmap(":/heros/h_r1.png"));
	animation.append(QPixmap(":/heros/h_r2.png"));
	return animation;
}

void OjSpider::process()
{

	_dy = (_dy < GRAVITE)? _dy+PGRAVITE : GRAVITE;

	if(deplacementDroite){
		gauche(false);
		droite(true);
	}else{
		droite(false);
		gauche(true);
	}


	animation();
	QList<QGraphicsItem*> listCollision = collidingItems();

	for(int i=0;i<listCollision.size();++i)
	{
			qDebug()<<"avant";emit collision(this,dynamic_cast<ObjetJeu*>(listCollision.at(i)));qDebug()<<"apres";
	}
}

void OjSpider::setDeplacementDroite(bool t)
{
	deplacementDroite = t;
}

void OjSpider::droite(bool t)
{
	if(t)
		_dx = 2;
	else
		_dx = 0;
}

void OjSpider::gauche(bool t)
{
	if(t)
		_dx = -2;
	else
		_dx = 0;
}


void OjSpider::animation()
{
	counter++;
	if(_dx > 0 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 4)
		setFrame(2);
	else if(_dx > 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 5)
		setFrame(3);
	else if(_dx < 0 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 2)
		setFrame(0);
	else if(_dx < 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 3)
		setFrame(1);
}
