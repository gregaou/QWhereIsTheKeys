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
