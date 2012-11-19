#ifndef PLATEFORME_H
#define PLATEFORME_H

#include "objet_jeu.h"

class Plateforme : public ObjetJeu
{
public:
		Plateforme(qreal x, qreal y, qreal w, qreal h);


		QRectF boundingRect() const;
		QPainterPath shape() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
							 QWidget *widget);

protected:
		void advance(int step);

private:
		qreal _x, _y, _w, _h;
};

#endif // PLATEFORME_H
