#ifndef CARRE_H
#define CARRE_H

#include "objet_jeu.h"

class Carre : public ObjetJeu
{
public:
		Carre();

		QRectF boundingRect() const;
		QPainterPath shape() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
							 QWidget *widget);

		void droite(bool t);
		void gauche(bool t);

		void setDx(qreal r);
		void setDy(qreal r);
		void saut();

protected:
		void advance(int step);

private:
		qreal _dx;
		qreal _dy;
};

#endif // CARRE_H
