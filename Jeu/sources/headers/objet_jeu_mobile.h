/**
 * \file			collision_oj.h
 * \brief			Chaîne de
 * \author    RIT Grégoire
 * \version   1.0
 * \date      01/12/12
 */

#ifndef OBJET_JEU_MOBILE_H
#define OBJET_JEU_MOBILE_H

#include "sources/headers/objet_jeu.h"

class OjHeros;

class ObjetJeuMobile : public ObjetJeu
{
public:
	explicit ObjetJeuMobile(qreal x, qreal y, const QList<QPixmap> &animation);

public:
	inline void setVelocity(qreal dx, qreal dy) { _dx = dx; _dy = dy; }
	inline qreal xVelocity() const                  { return _dx; }
	inline qreal yVelocity() const                  { return _dy; }

	virtual void process() = 0;
	virtual QString toString() { return QString("ObjetJeuMobile"); }

protected:
	void advance(int phase);

	struct Frame {
		QPixmap pixmap;
		QPainterPath shape;
		QRectF boundingRect;
	};

	qreal _dx, _dy;
	int _currentFrame;
	QList<Frame> _frames;

	virtual QList<QPixmap> loadListPixmap() const { return QList<QPixmap>(); }
};

#endif // OBJET_JEU_MOBILE_H
