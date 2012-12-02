#ifndef OJ_SPIDER_H
#define OJ_SPIDER_H

#include "objet_jeu_mobile.h"

class OjSpider : public ObjetJeuMobile
{
public:
	explicit OjSpider(const qreal x, const qreal y);
	QString toString() { return QString("OjSpider"); }
	void setDeplacementDroite(bool t);
	void process();

	void droite(bool t);
	void gauche(bool t);

protected:
	QList<QPixmap> loadListPixmap() const;

	void animation();

	int counter;

	bool deplacementDroite;

	qreal gravite;


};

#endif // OJ_SPIDER_H
