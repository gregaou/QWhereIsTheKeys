#ifndef OJ_FLAMME_H
#define OJ_FLAMME_H

#include "objet_jeu_mobile.h"

class OjFlamme : public ObjetJeuMobile
{
public:
	explicit OjFlamme(const qreal x, const qreal y);
	QString toString() { return QString("OjFlamme"); }
	void process();

protected:
	QList<QPixmap> loadListPixmap() const;
	void animation();
	int tmp;
	int counter;/**< Permet de définir le vitesse de défilement des frames de objet jeu */
};

#endif // OJ_FLAMME_H
