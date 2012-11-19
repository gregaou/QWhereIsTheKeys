#ifndef OBJETJEU_H
#define OBJETJEU_H

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>

class ObjetJeu : public QGraphicsItem
{
public:
	explicit ObjetJeu(qreal x, qreal y);

public:
	virtual QRectF boundingRect() const = 0;
	virtual QPainterPath shape() const = 0;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
						 QWidget *widget) = 0;

protected:
	virtual void advance(int phase) {}
};

#endif // OBJETJEU_H
