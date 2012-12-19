/**
 * \file			oj_clef.h
 * \brief			Structure de donnée d'un objet clef
 * \author    PACHY Ravi, BUISSON Fabien
 * \version   1.0
 * \date      05/12/12
 */
#ifndef OJ_CLEF_H
#define OJ_CLEF_H

#include "objet_jeu_mobile.h"
/**
 * \class OjClef
 * \brief Structure de donnée représentant une clef.
 */
class OjClef : public ObjetJeuMobile
{
public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit OjClef(const qreal x, const qreal y)
		*  \param x Définit l'abscisse de l'objet jeu
		*  \param y Définit l'ordonnée de l'objet jeu
		*/
	explicit OjClef(const qreal x, const qreal y);
	/**
		*  \brief Renvoi en QString le type de l'objet jeu
		*	 \fn    QString toString()
		*/
	QString toString() { return QString("OjClef"); }
	/**
		*  \brief Fonction process de l'objet jeu
		*	 \fn    void process()
		*/
	void process();

protected:
	/**
		*  \brief Chargement des sprites pour l'objet jeu
		*	 \fn    QList<QPixmap> loadListPixmap() const
		*/
	QList<QPixmap> loadListPixmap() const;
};

#endif // OJ_CLEF_H
