#include "plateforme.h"
#include <QDebug>
Plateforme::Plateforme(qreal x, qreal y, qreal w, qreal h):
	ObjetJeu(x,y), _w(w), _h(h)
{
}

QRectF Plateforme::boundingRect() const
{
	return QRect(0,0,_w,_h);
}

QPainterPath Plateforme::shape() const
{
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

void Plateforme::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setBrush(Qt::white);
	painter->drawRect(boundingRect());
}

void Plateforme::advance(int step)
{

}
