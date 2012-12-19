/**
 * \file			oj_heros.h
 * \brief			Définit le héros
 * \author    RIT Grégoire
 * \version   1.0
 * \date      05/12/12
 */

#ifndef OJ_HEROS_H
#define OJ_HEROS_H

#include "objet_jeu_mobile.h"

class OjHeros : public ObjetJeuMobile
{
public:
	explicit OjHeros(const qreal x, const qreal y);
	QString toString() { return QString("OjHeros"); }
	void process();

	void droite(bool t);
	void gauche(bool t);
	void saut();

protected:
	QList<QPixmap> loadListPixmap() const;

	void animation();

	int _counter;

	qreal _gravite;

	bool _doubleSautGauche;
	bool _doubleSautDroite;


};

#endif // OJ_HEROS_H
