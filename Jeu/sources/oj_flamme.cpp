#include "sources/headers/oj_flamme.h"

#include <QDebug>
#include <QGraphicsScene>

#define NB_FPS_ANIMATION(X)  ((1000/1)/X)

OjFlamme::OjFlamme(const qreal x, const qreal y) :
	ObjetJeuMobile(x,y,loadListPixmap()),counter(0)
{
	tmp = 0;
}

QList<QPixmap> OjFlamme::loadListPixmap() const
{
	QList<QPixmap> animation;
	animation.append(QPixmap(":/flamme/flame1.png"));
	animation.append(QPixmap(":/flamme/flame2.png"));
	animation.append(QPixmap(":/flamme/flame3.png"));
	animation.append(QPixmap(":/flamme/flame4.png"));
	return animation;
}

void OjFlamme::process()
{
	animation();
}


void OjFlamme::animation()
{
	counter++;
	if(tmp == 40)
		tmp = 0;

	if(tmp >= 0 && tmp < 10 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 0)
		setFrame(0);
	else if(tmp >= 10 && tmp < 20 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 3)
		setFrame(3);
	else if(tmp >= 20 && tmp < 30 && counter % NB_FPS_ANIMATION(5) < NB_FPS_ANIMATION(5)/2 && frame() != 2)
		setFrame(2);
	else if(tmp >= 30 && tmp < 40 && counter % NB_FPS_ANIMATION(5) >= NB_FPS_ANIMATION(5)/2 && frame() != 1)
		setFrame(1);

	tmp++;
}
