#include "sources/headers/oj_plateforme.h"

#include <QDebug>
#include <QWidget>

OjPlateforme::OjPlateforme(const qreal x, const qreal y, const qreal w,
													 const qreal h) :

	ObjetJeu(x,y,w,h,QPixmap(":/fond/fond.png"))
{

}

void OjPlateforme::process()
{

}

void OjPlateforme::herosCollision(OjHeros *h)
{
	if(!collidesWithItem(h))
		return;

	qreal hx1,hy1,hx2,hy2,px1,py1,px2,py2;
	qreal hw,hh,pw,ph;

	hw = h->boundingRect().width();
	hh = h->boundingRect().height();
	pw = boundingRect().width();
	ph = boundingRect().height();

	hx1 = h->x();
	hy1 = h->y();
	hx2 = hx1 + hw;
	hy2 = hy1 + hh;

	px1 = x();
	py1 = y();
	px2 = px1 + pw;
	py2 = py1 + ph;

	QRectF recI = QRectF(hx1,hy1,hw,hh).intersected(QRectF(px1,py1,pw,ph));

	//collision haut
	if( recI.y() == py1 && hy2-h->yVelocity() <= py1 )
	{
		h->setPos(hx1, py1-hh);
		h->setVelocity(h->xVelocity(),(h->yVelocity()<0)?h->yVelocity():0.1);
	}
	//collision bas
	else if (recI.y() + recI.height() == py2 && hy1+h->xVelocity() <= py2)
	{
		h->setPos(hx1, py2);
		h->setVelocity(h->xVelocity(),(h->yVelocity() < 0)? 0.1 : h->yVelocity());
	}
	//collision gauche
	else if(recI.x() == px1)
		h->setPos(px1-hw, hy1);
	//collision droite
	else if(recI.x()+recI.width() == px2)
		h->setPos(px2, hy1);

}
