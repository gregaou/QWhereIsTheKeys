#include "sources/headers/oj_heros.h"

#include <QDebug>
#include <QGraphicsScene>

#define GRAVITE 5
#define PGRAVITE 0.2

#define NB_FPS_ANIMATION(X)  ((1000/20)/X)

OjHeros::OjHeros(const qreal x, const qreal y) :
	ObjetJeuMobile(x,y,loadListPixmap()), counter(0)
{}


QList<QPixmap> OjHeros::loadListPixmap() const
{
	QList<QPixmap> animation;
	animation.append(QPixmap(":/heros/h_d1.png"));
	animation.append(QPixmap(":/heros/h_d2.png"));
	animation.append(QPixmap(":/heros/h_l1.png"));
	animation.append(QPixmap(":/heros/h_l2.png"));
	animation.append(QPixmap(":/heros/h_r1.png"));
	animation.append(QPixmap(":/heros/h_r2.png"));
	return animation;
}

void OjHeros::process()
{

	_dy = (_dy < GRAVITE)? _dy+PGRAVITE : GRAVITE;

//	if(!scene()->sceneRect().contains(boundingRect().translated(pos())))
//	{
//		int w,h,sw,sh;
//		w=boundingRect().width();
//		h=boundingRect().height();
//		sw=scene()->width();
//		sh=scene()->height();

//		setPos( ( x() < 0 ) ? 0 : ( x() + w > sw )? sw - w : x(),
//						( y() < 0 ) ? 0 : ( y() + h > sh )? sh - h : y());

//	}

	animation();

	QList<QGraphicsItem*> listCollision = collidingItems();

	for(int i=0;i<listCollision.size();++i)
	{
		ObjetJeu *oj = dynamic_cast<ObjetJeu*>(listCollision.at(i));
		oj->herosCollision(this);
	}
}

void OjHeros::droite(bool t)
{
	if(t)
		_dx = 2;
	else if ( _dx > 0)
		_dx = 0;
}

void OjHeros::gauche(bool t)
{
	if(t)
		_dx = -2;
	else if ( _dx < 0)
		_dx = 0;
}

void OjHeros::saut()
{
		if(!scene()->items(mapToScene(0,boundingRect().height()+1,
																	boundingRect().width(),0.1)).isEmpty()
			 && _dy  > 0 )
		_dy = -GRAVITE;
}

void OjHeros::animation()
{
	counter++;
	if(_dx > 0 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 4)
		setFrame(4);
	else if(_dx > 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 5)
		setFrame(5);
	else if(_dx < 0 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 2)
		setFrame(2);
	else if(_dx < 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 3)
		setFrame(3);
	else if( _dx == 0 )
		setFrame(0);
}



