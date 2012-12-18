#include "sources/headers/oj_fix_anime.h"
#include <QGraphicsScene>

#define NB_FPS_ANIMATION(X)  ((1000/1)/X)

OjFixAnime::OjFixAnime(const qreal x, const qreal y, QString sprite1,QString sprite2,QString sprite3,QString sprite4) :
	ObjetJeuMobile(x,y,loadListPixmap(sprite1,sprite2,sprite3,sprite4)),counter(0)
{
	tmp = 0;
}

QList<QPixmap> OjFixAnime::loadListPixmap(QString l1,QString l2,QString l3,QString l4) const
{
	QList<QPixmap> animation;
	animation.append(QPixmap(l1));
	animation.append(QPixmap(l2));
	animation.append(QPixmap(l3));
	animation.append(QPixmap(l4));

	return animation;
}
/*
QList<QPixmap> OjFlamme::loadListPixmap() const
{
	QList<QPixmap> animation;
	animation.append(QPixmap(":/flamme/flame1.png"));
	animation.append(QPixmap(":/flamme/flame2.png"));
	animation.append(QPixmap(":/flamme/flame3.png"));
	animation.append(QPixmap(":/flamme/flame4.png"));
	QString(:/flamme/flame1.png),QString(":/flamme/flame2.png"),QString(":/flamme/flame3.png"),QString(":/flamme/flame4.png")
	return animation;
}
*/
void OjFixAnime::process()
{
	animation();
}


void OjFixAnime::animation()
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
