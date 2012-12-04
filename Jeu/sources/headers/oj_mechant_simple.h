#ifndef OJ_MECHANT_SIMPLE_H
#define OJ_MECHANT_SIMPLE_H

#include "objet_jeu_mobile.h"

class OjMechantSimple : public ObjetJeuMobile
{
public:
	explicit OjMechantSimple(qreal x, qreal y,QString left1,QString left2,QString right1,QString right2, const bool deplacement);
	QString toString() { return QString("OjMechantSimple"); }
	void process();

	void droite();
	void gauche();

protected:

	QList<QPixmap> loadListPixmap(QString l1, QString l2, QString r1, QString r2) const;

	void animation();

	int counter;

	bool deplacement;

	qreal gravite;

};



#endif // OJ_MECHANT_SIMPLE_H
