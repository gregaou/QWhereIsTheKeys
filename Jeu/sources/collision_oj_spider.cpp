#include "sources/headers/collision_oj_spider.h"

void CollisionOjSpider::gererCollision(ObjetJeu *oj1, ObjetJeu *oj2)
{
	OjSpider *s = dynamic_cast<OjSpider*>(oj1);

	if(oj2->toString() == "OjPlateforme")
	{
		OjPlateforme *p = dynamic_cast<OjPlateforme*>(oj2);
		collisionEntre(s,p);
	}
	if(oj2->toString() == "OjHeros")
	{
		OjHeros *h = dynamic_cast<OjHeros*>(oj2);
		collisionHeros(s,h);
	}
}

void CollisionOjSpider::collisionEntre(OjSpider *s, OjPlateforme *p)
{
	qreal sx1,sy1,sx2,sy2,px1,py1,px2,py2;
	qreal sw,sh,pw,ph;

	sw = s->boundingRect().width();
	sh = s->boundingRect().height();
	pw = p->boundingRect().width();
	ph = p->boundingRect().height();

	sx1 = s->x();
	sy1 = s->y();
	sx2 = sx1 + sw;
	sy2 = sy1 + sh;

	px1 = p->x();
	py1 = p->y();
	px2 = px1 + pw;
	py2 = py1 + ph;

	QRectF recI = QRectF(sx1,sy1,sw,sh).intersected(QRectF(px1,py1,pw,ph));

	//collision haut
	if( recI.y() == py1 && sy2-s->yVelocity() <= py1 )
	{
		s->setPos(sx1, py1-sh);
		s->setVelocity(s->xVelocity(),(s->yVelocity()<0)?s->yVelocity():0.1);
	}
	// pas forcement utile !
	//collision bas
	else if (recI.y() + recI.height() == py2 && sy1+s->xVelocity() <= py2)
	{
		s->setPos(sx1, sy2);
		s->setVelocity(s->xVelocity(),(s->yVelocity() < 0)? 0.1 : s->yVelocity());
	}
	//collision gauche
	else if(recI.x() == px1)
		s->setPos(px1-sw, sy1);
	//collision droite
	else if(recI.x()+recI.width() == px2)
		s->setPos(px2, sy1);

	if(sx2 == px2)
		s->setDeplacementDroite(false);
	else if(sx1 == px1)
		s->setDeplacementDroite(true);

}

void CollisionOjSpider::collisionHeros(OjSpider *s, OjHeros *h)
{
	//TODO
}

