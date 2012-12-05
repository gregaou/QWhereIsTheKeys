/**
 * \file			oj_flamme.h
 * \brief			Structure de donnée d'un objet jeu flamme
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      05/12/12
 */
#ifndef OJ_FLAMME_H
#define OJ_FLAMME_H

#include "objet_jeu_mobile.h"
/**
 * \class OjFlamme
 * \brief Structure de donnée représentant des flammes (objet immobile et animé).
 */
class OjFlamme : public ObjetJeuMobile
{
public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit OjFlamme(const qreal x, const qreal y)
		*  \param x Définit l'abscisse de l'objet jeu
		*  \param y Définit l'ordonnée de l'objet jeu
		*/
	explicit OjFlamme(const qreal x, const qreal y);
	/**
		*  \brief Renvoi en QString le type de l'objet jeu
		*	 \fn    QString toString()
		*/
	QString toString() { return QString("OjFlamme"); }
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
	/**
		*  \brief Gère l'animation de l'objet jeu
		*	 \fn    void animation()
		*/
	void animation();
	int tmp;
	int counter;/**< Permet de définir le vitesse de défilement des frames de objet jeu */
};

#endif // OJ_FLAMME_H
