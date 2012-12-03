#ifndef OJ_SPIDER_H
#define OJ_SPIDER_H

#include "objet_jeu_mobile.h"

class OjSpider : public ObjetJeuMobile
{
public:
	explicit OjSpider(const qreal x, const qreal y, const bool deplacement);
	QString toString() { return QString("OjSpider"); }
	void process();

	void droite();
	void gauche();

protected:
	QList<QPixmap> loadListPixmap() const;

	void animation();

	int counter;

	bool deplacement;

	qreal gravite;

};

#endif // OJ_SPIDER_H
