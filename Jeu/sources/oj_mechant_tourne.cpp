#include "sources/headers/oj_mechant_tourne.h"

#include <QGraphicsScene>

//#define GRAVITE 5
//#define PGRAVITE 0.2

#define NB_FPS_ANIMATION(X)  ((1000/20)/X)

OjMechantTourne::OjMechantTourne(const qreal x, const qreal y, QString up1, QString up2, QString down1, QString down2, QString left1,QString left2,QString right1,QString right2, const bool deplacement=true) :
		ObjetJeuMobile(x,y,loadListPixmap(up1,up2,down1,down2,left1,left2,right1,right2)), counter(0),deplacement(deplacement)
{

		bas();
		pf = 0;
}

QList<QPixmap> OjMechantTourne::loadListPixmap(QString u1,QString u2,QString d1,QString d2,QString l1,QString l2,QString r1,QString r2) const
{
		QList<QPixmap> animation;
		animation.append(QPixmap(u1));
		animation.append(QPixmap(u2));
		animation.append(QPixmap(d1));
		animation.append(QPixmap(d2));
		animation.append(QPixmap(l1));
		animation.append(QPixmap(l2));
		animation.append(QPixmap(r1));
		animation.append(QPixmap(r2));

		return animation;
}


void OjMechantTourne::setPlateforme(OjPlateforme *p)
{
		pf = p;
}

OjPlateforme* OjMechantTourne::getPlateforme()
{
		return pf;
}


void OjMechantTourne::direction()
{
		qreal hx1,hy1,hx2,hy2,px1,py1,px2,py2;
		qreal hw,hh,pw,ph;

		hw = this->boundingRect().width(); //largeur garde
		hh = this->boundingRect().height(); // hauteur garde
		pw = pf->boundingRect().width();
		ph = pf->boundingRect().height();

		hx1 = x(); //position x du garde (gauche)
		hy1 = y(); //position y du garde(haut)
		hx2 = hx1 + hw; //point le plus Ã  droite du garde
		hy2 = hy1 + hh; //point le plus en bas du garde

		px1 = pf->x();
		py1 = pf->y();
		px2 = px1 + pw;
		py2 = py1 + ph;

		if (deplacement)
		{
				if (_dx >0) //la creature allait Ã  droite
				{
						if (hx1 >= px2)//si la creature depasse le point le plus Ã  droite de la plateforme elle descend
							 bas();
						else
								droite(); //sinon elle continue son chemin vers la droite
				}
				else if(_dx <0) //la creature allait Ã  gauche
				{
						if (hx2<= px1) //si la creature depasse le point le plus Ã  gauche de la plateforme elle monte
								haut();
						else
								gauche(); //sinon elle continue son chemin vers la gauche
				}
				else if(_dy >0)  //la creature descend
				{
						if(hy1>=py2) //si la creture depasse le point le plus en bas de la plateforme elle part Ã  gauche
								gauche();
						else
								bas(); //sinon elle continue de descendre

				}
				else if (_dy < 0) //la creature monte
				{
						if(hy2 <= py1) //si la creature depasse le point le plus haut, elle vas Ã  droite
								droite();
						else
								haut(); //sinonelle contine Ã  monter

				}
		}
		else
		{
				if (_dx < 0) //la creature allait Ã  gauche
				{
						if (hx2 <= px1)//si la creature depasse le point le plus Ã  gauche de la plateforme elle descend
							 bas();
						else
							 gauche(); //sinon elle continue son chemin vers la droite
				}
				else if(_dx >0) //la creature allait Ã  droite
				{
						if (hx1>= px2) //si la creature depasse le point le plus Ã  gauche de la plateforme elle monte
								haut();
						else
								droite(); //sinon elle continue son chemin vers la gauche
				}
				else if(_dy <0)  //la creature monte
				{
						if(hy2<=py1) //si la creture depasse le point le plus en bas de la plateforme elle part Ã  droite
								gauche();
						else
								haut(); //sinon elle continue de descendre

				}
				else if (_dy>  0) //la creature descend
				{
						if(hy1 >= py2) //si la creature depasse le point le plus haut, elle vas Ã  gauche
								droite();
						else
								bas(); //sinonelle contine Ã  monter

				}
		}


}

void OjMechantTourne::process()
{


		animation();
		QList<QGraphicsItem*> listCollision = collidingItems();

		if (getPlateforme()==0)
		{
				for(int i=0;i<listCollision.size();++i)
				{
						emit collision(dynamic_cast<ObjetJeu*>(this),dynamic_cast<ObjetJeu*>(listCollision.at(i)));
				}
		}
		if (getPlateforme() != 0)
		{

				direction();
		}

}

void OjMechantTourne::droite()
{
				_dx = 2;
				_dy = 0;
}

void OjMechantTourne::gauche()
{
				_dx = -2;
				_dy = 0;
}
void OjMechantTourne::bas()
{
				_dx = 0;
				_dy = 2;
}

void OjMechantTourne::haut()
{
				_dx = 0;
				_dy = -2;
}
bool OjMechantTourne::getDeplacement()
{
		return deplacement;
}


void OjMechantTourne::animation()
{
		counter++;
		if(_dx > 0 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 6)
				setFrame(6);
		else if(_dx > 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 7)
				setFrame(7);
		else if(_dx < 0 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 4)
				setFrame(4);
		else if(_dx < 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 5)
				setFrame(5);
		else if(_dy > 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 2)
				setFrame(2);
		else if(_dy > 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 3)
				setFrame(3);
		else if(_dy < 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 0)
				setFrame(0);
		else if(_dy < 0 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 1)
				setFrame(1);
}
