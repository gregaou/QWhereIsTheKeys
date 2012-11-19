#include "carre.h"

#include <QDebug>
#include <QGraphicsScene>

Carre::Carre(qreal x , qreal y) :ObjetJeu(x,y), _dx(0), _dy(0)
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
	if(_dy < 5)
		_dy += 0.1;

	if(_dx) {
		if(_dx > 0 && _dx+0.2 < 2)
			_dx += 0.2;
		else if (_dx < 0 && _dx-0.2 > -2)
			_dx -= 0.2;
	}



	QList<QGraphicsItem *> list;

	if(scene()->sceneRect().contains(boundingRect().translated(_dx,0).translated(pos())))
		moveBy(_dx,0);

	if(scene()->sceneRect().contains(boundingRect().translated(0,_dy).translated(pos()))
		 && scene()->items(pos().x(),pos().y()+21,20,1).isEmpty()
		 && scene()->items(pos().x(),pos().y()-1,20,1).isEmpty())
		moveBy(0,_dy);

	list = collidingItems();




}

void Carre::droite(bool t)
{
	if(t)
		_dx = 0.2;
	else
		_dx = 0;
}

void Carre::gauche(bool t)
{
	if(t)
		_dx = -0.2;
	else
		_dx = 0;
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
	if(_dy >= 5)
		_dy=-_dy;
}
