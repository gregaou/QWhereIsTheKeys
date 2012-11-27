#ifndef OBJETJEU_H
#define OBJETJEU_H

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QBitmap>

class OjHeros;

class ObjetJeu : public QGraphicsItem
{
public:
	explicit ObjetJeu(qreal x, qreal y, const QList<QPixmap> &animation);
	explicit ObjetJeu(qreal x, qreal y, qreal w, qreal h, const QPixmap & fond);

	virtual QRectF boundingRect() const;
	virtual QPainterPath shape() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
						 QWidget *widget);

	void setFrame(int frame);
	inline int frame() const                        { return _currentFrame; }
	inline int frameCount() const                   { return _frames.size(); }
	inline QPixmap image(int frame) const
	{ return _frames.isEmpty() ?QPixmap() :
															_frames.at(frame % _frames.size()).pixmap; }

	virtual void process() = 0;

	virtual void herosCollision(OjHeros *h) = 0;

protected:
		virtual void advance(int phase) { Q_UNUSED(phase) }

	struct Frame {
			QPixmap pixmap;
			QPainterPath shape;
			QRectF boundingRect;
	};

	QPixmap * _fond;

	int _currentFrame;
	QList<Frame> _frames;

	qreal _w,_h;

	virtual QList<QPixmap> loadListPixmap() const { return QList<QPixmap>(); }

};

#endif // OBJETJEU_H
