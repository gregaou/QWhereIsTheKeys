/**
 * \file			oj_flamme.h
 * \brief			Structure de donnée d'un objet jeu flamme
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      05/12/12
 */
#ifndef OJ_FIX_ANIME_H
#define OJ_FIX_ANIME_H

#include "objet_jeu_mobile.h"
/**
 * \class OjFixAnime
 * \brief Structure de donnée représentant des flammes (objet immobile et animé).
 */
class OjFixAnime : public ObjetJeuMobile
{
public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit OjFixAnime(const qreal x, const qreal y, QString sprite1, QString sprite2, QString sprite3, QString sprite4)
		*  \param x Définit l'abscisse de l'objet jeu
		*  \param y Définit l'ordonnée de l'objet jeu
		*/
	explicit OjFixAnime(const qreal x, const qreal y, QString sprite1,QString sprite2,QString sprite3,QString sprite4);
	/**
		*  \brief Renvoi en QString le type de l'objet jeu
		*	 \fn    QString toString()
		*/
	QString toString() { return QString("OjFixAnime"); }
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
	QList<QPixmap> loadListPixmap(QString l1, QString l2, QString l3, QString l4) const;
	/**
		*  \brief Gère l'animation de l'objet jeu
		*	 \fn    void animation()
		*/
	void animation();
	int tmp;		/**< Permet de définir la vitesse de défilement des frames de l'objet jeu */
	int counter;/**< Permet de définir la vitesse de défilement des frames de l'objet jeu */
};

#endif // OJ_FLAMME_H
