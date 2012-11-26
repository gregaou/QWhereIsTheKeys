#include "sources/headers/objet_jeu_mobile.h"

ObjetJeuMobile::ObjetJeuMobile(qreal x, qreal y,const QList<QPixmap> &animation) :
	ObjetJeu(x,y,animation), _dx(0), _dy(0) {}

void ObjetJeuMobile::advance(int phase)
{
	if(phase == 0)
		return;

	moveBy(_dx,_dy);
}
