/**
 * \file			oj_mechant_simple.h
 * \brief			Structure de donnée d'un objet jeu méchant simple
 * \author    GALLO Jean-Bernard
 * \version   1.0
 * \date      04/12/12
 */
#ifndef OJ_MECHANT_SIMPLE_H
#define OJ_MECHANT_SIMPLE_H

#include "objet_jeu_mobile.h"
/**
 * \class OjMechantSimple
 * \brief Structure de donnée représentant méchant simple (déplacement droite/gauche ou gauche/droite ).
 */
class OjMechantSimple : public ObjetJeuMobile
{
public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit OjMechantSimple(qreal x, qreal y,QString left1,QString left2,QString right1,QString right2, const bool deplacement)
		*  \param x Définit l'abscisse de l'objet jeu
		*  \param y Définit l'ordonnée de l'objet jeu
		*  \param left1 Frame déplacement gauche 1
		*  \param left2 Frame déplacement gauche 2
		*  \param right Frame déplacement droite 1
		*  \param right Frame déplacement droite 2
		*  \param deplacement Définit le déplacement initial de l'objet jeu (true = droite / false = gauche )
		*/
	explicit OjMechantSimple(qreal x, qreal y,QString left1,QString left2,QString right1,QString right2, const bool deplacement);
	/**
		*  \brief Renvoi en QString le type de l'objet jeu
		*	 \fn    QString toString()
		*/
	QString toString() { return QString("OjMechantSimple"); }
	/**
		*  \brief Fonction process de l'objet jeu
		*	 \fn    void process()
		*/
	void process();
	/**
		*  \brief Deplacement de l'objet jeu sur la droite
		*	 \fn    void droite()
		*/
	void droite();
	/**
		*  \brief Deplacement de l'objet jeu sur la gauche
		*	 \fn    void gauche()
		*/
	void gauche();

protected:

	/**
		*  \brief Chargement des sprites pour l'objet jeu
		*	 \fn    QList<QPixmap> loadListPixmap(QString l1, QString l2, QString r1, QString r2) const
		*	 \param l1 sprite 1
		*  \param l2 sprite 2
		*  \param l3 sprite 3
		*  \param l4 sprite 4
		*/
	QList<QPixmap> loadListPixmap(QString l1, QString l2, QString r1, QString r2) const;
	/**
		*  \brief Gère l'animation de l'objet jeu
		*	 \fn    void animation()
		*/
	void animation();

	int counter;/**< Permet de définir la vitesse de défilement des frames de l'objet jeu */

	bool deplacement;/**< Permet de définir le déplacement de l'objet jeu */

	qreal gravite;/**< Permet de définir la gravité de l'objet jeu */

};



#endif // OJ_MECHANT_SIMPLE_H
