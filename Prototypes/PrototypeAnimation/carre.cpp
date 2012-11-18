#include "carre.h"

#include <QDebug>
#include <QGraphicsScene>

Carre::Carre() : _dx(0), _dy(0)
{
}

QRectF Carre::boundingRect() const
{
	return QRect(0,0,20,20);
}

QPainterPath Carre::shape() const
{
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

void Carre::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setBrush(Qt::black);
	painter->drawRect(boundingRect());
}

void Carre::advance(int step)
{
		if (!step)
				return;
		if(_dy < 3)
			_dy += 0.1;

		if(scene()->sceneRect().contains(boundingRect().translated(_dx,0).translated(pos())))
			moveBy(_dx,0);

		if(scene()->sceneRect().contains(boundingRect().translated(0,_dy).translated(pos())))
			moveBy(0,_dy);

}

void Carre::setDx(qreal r)
{
	_dx = r;
}

void Carre::setDy(qreal r)
{
	_dy= r;
}

void Carre::saut()
{
	if(_dy >= 3)
	_dy=-_dy;
}
