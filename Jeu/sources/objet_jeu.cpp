#include "sources/headers/objet_jeu.h"
#include <QDebug>

ObjetJeu::ObjetJeu(qreal x, qreal y, const QList<QPixmap> &animation) :
	QGraphicsItem(0),
	_fond(0),
	_currentFrame(0),
	_w(0),
	_h(0)
{
	setPos(x,y);

	for (int i = 0; i < animation.size(); ++i) {
		QPixmap pixmap = animation.at(i);
		Frame frame;
		frame.pixmap = pixmap;
		frame.shape = QPainterPath();
		frame.boundingRect = pixmap.rect();
		_frames << frame;
	}

	qDebug() << animation.size();
}

ObjetJeu::ObjetJeu(qreal x, qreal y, qreal w, qreal h, const QPixmap &fond) :
	QGraphicsItem(0),
	_fond(new QPixmap(fond)),
	_currentFrame(0),
	_w(w),
	_h(h)
{
	setPos(x,y);
}


void ObjetJeu::setFrame(int frame)
{
	if(_fond) return;
	if (!_frames.isEmpty()) {
		prepareGeometryChange();
		_currentFrame = frame % _frames.size();
	}
}

QRectF ObjetJeu::boundingRect() const
{
	if(!_fond)
		return _frames.at(_currentFrame).boundingRect;
	else
		return
				QRectF(0,0,_w,_h);
}

QPainterPath ObjetJeu::shape() const
{
	if(!_fond)
	{
		const Frame &f = _frames.at(_currentFrame);
		if (f.shape.isEmpty()) {
			QPainterPath path;
			path.addRegion(f.pixmap.createHeuristicMask());
			const_cast<Frame &>(f).shape = path;
		}
		return f.shape;
	} else
	{
		QPainterPath path;
		path.addRect(boundingRect());
		return path;
	}
}

void ObjetJeu::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
										 QWidget *)
{
	if(!_fond)
	{
		painter->drawPixmap(0,0,_frames.at(_currentFrame).pixmap);
	}
	else
	{
		painter->setBrush(QBrush(*_fond));
		painter->drawRect(boundingRect());
	}
}

