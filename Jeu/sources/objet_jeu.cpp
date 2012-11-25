#include "sources/headers/objet_jeu.h"
#include <QDebug>

ObjetJeu::ObjetJeu(qreal x, qreal y, const QList<QPixmap> &animation) :
	QGraphicsItem(0),
	_currentFrame(0)
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
}

void ObjetJeu::setFrame(int frame)
{
		if (!_frames.isEmpty()) {
				prepareGeometryChange();
				_currentFrame = frame % _frames.size();
		}
}

QRectF ObjetJeu::boundingRect() const
{
		return _frames.at(_currentFrame).boundingRect;
}

QPainterPath ObjetJeu::shape() const
{
		const Frame &f = _frames.at(_currentFrame);
		if (f.shape.isEmpty()) {
				QPainterPath path;
				path.addRegion(f.pixmap.createHeuristicMask());
				const_cast<Frame &>(f).shape = path;
		}
		return f.shape;
}

void ObjetJeu::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
															 QWidget *)
{
		painter->drawPixmap(0,0,_frames.at(_currentFrame).pixmap);
}

