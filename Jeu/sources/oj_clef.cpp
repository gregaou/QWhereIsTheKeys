#include "sources/headers/oj_clef.h"

#include <QDebug>
#include <QGraphicsScene>


OjClef::OjClef(const qreal x, const qreal y) :
	ObjetJeuMobile(x,y,loadListPixmap())
{

}

QList<QPixmap> OjClef::loadListPixmap() const
{
	QList<QPixmap> animation;
	animation.append(QPixmap(":/icon/key.png"));
	return animation;
}

void OjClef::process()
{}



