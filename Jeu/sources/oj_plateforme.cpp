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

	QRectF inters = boundingRect().intersect(h->boundingRect());

	// collision par le haut
	if(inters.x() == boundingRect().x())
		h->setPos(h->x(), y()-h->boundingRect().height());

}
