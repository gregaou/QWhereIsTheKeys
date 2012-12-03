#ifndef OJ_GARDE_H
#define OJ_GARDE_H

#include "objet_jeu_mobile.h"

class OjGarde : public ObjetJeuMobile
{
public:
	explicit OjGarde(const qreal x, const qreal y, const bool deplacement);
	QString toString() { return QString("OjGarde"); }
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

#endif // OJ_GARDE_H
