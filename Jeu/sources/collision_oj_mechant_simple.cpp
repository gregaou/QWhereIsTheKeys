#include "sources/headers/collision_oj_mechant_simple.h"
void CollisionOjMechantSimple::gererCollision(ObjetJeu *oj1, ObjetJeu *oj2)
{
	OjMechantSimple *s = dynamic_cast<OjMechantSimple*>(oj1);
	if(oj2->toString() == "OjPlateforme")
	{
		OjPlateforme *p = dynamic_cast<OjPlateforme*>(oj2);
		collisionEntre(s,p);
	}

}

void CollisionOjMechantSimple::collisionEntre(OjMechantSimple *h, OjPlateforme *p)
{
	qreal hx1,hy1,hx2,hy2,px1,py1,/*px2,*/py2;
	qreal hw,hh,pw,ph;

	hw = h->boundingRect().width(); //largeur garde
	hh = h->boundingRect().height(); // hauteur garde
	pw = p->boundingRect().width();
	ph = p->boundingRect().height();

	hx1 = h->x(); //position x du garde (gauche)
	hy1 = h->y(); //position y du garde(haut)
	hx2 = hx1 + hw; //point le plus à droite du garde
	hy2 = hy1 + hh; //point le plus en bas du garde

	px1 = p->x();
	py1 = p->y();
//	px2 = px1 + pw;
	py2 = py1 + ph;

	QRectF recI = QRectF(hx1,hy1,hw,hh).intersected(QRectF(px1,py1,pw,ph));

	//collision haut
	//si la hauteur du rectangle de colision = plushaut point de la plateforme
	//et point le plus en bas du hero -
	if( recI.y() == py1 && hy2-h->yVelocity() <= py1 )
	{
			h->setPos(hx1, py1-hh);
			h->setVelocity(h->xVelocity(),(h->yVelocity()<0)?h->yVelocity():0.1);
			if(recI.x()+recI.width() < hx2)
					h->gauche();
			if(recI.x()> hx1)
					h->droite();
	}
	//collision bas
	// si la hauteur de la collision + taille collision  == point le plus en bas de la plateforme
	//else if ( recI.y() + recI.height() == py2 && hy1+h->xVelocity() <= py2)
	else if ( recI.y() == py2 && hy1+h->xVelocity() <= py2)
	{
			h->setVelocity(h->xVelocity(),(h->yVelocity() < 0)? 0.1 : h->yVelocity());
	}
	//collision gauche
	else if(recI.x() == hx1 )
			h->droite();
	//collision droite
	else if(recI.x()+recI.width() == hx2)
			h->gauche();

}


