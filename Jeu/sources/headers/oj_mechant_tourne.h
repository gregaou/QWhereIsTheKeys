
/**
 * \file			oj_mechant_tourne.h
 * \brief			Structure de donnée d'un objet jeu méchant tourne
 * \author    MAHE Yannick
 * \version   1.0
 * \date      04/12/12
 */

#ifndef OJ_MECHANT_TOURNE_H
#define OJ_MECHANT_TOURNE_H
#include "oj_plateforme.h"
#include "objet_jeu_mobile.h"
/**
 * \class OjMechantTourne
 * \brief Structure de donnée représentant méchant tourne (déplacement droite/gauche ou gauche/droite ).
 */
class OjMechantTourne : public ObjetJeuMobile
{
public:
		/**
				*  \brief Constructeur
				*	 \fn    explicit OjMechantTourne(qreal x, qreal y,QString left1,QString left2,QString right1,QString right2, const bool deplacement)
				*  \param x Définit l'abscisse de l'objet jeu
				*  \param y Définit l'ordonnée de l'objet jeu
				*  \param up1 Frame déplacement haut 1
				*  \param up2 Frame déplacement haut 2
				*  \param down1 Frame déplacement bas 1
				*  \param down2 Frame déplacement bas 2
				*  \param left1 Frame déplacement gauche 1
				*  \param left2 Frame déplacement gauche 2
				*  \param right Frame déplacement droite 1
				*  \param right Frame déplacement droite 2
				*  \param deplacement Définit le déplacement initial de l'objet jeu (true = droite / false = gauche )
				*/
		explicit OjMechantTourne(qreal x, qreal y,QString up1, QString up2, QString down1, QString down2,QString left1,QString left2,QString right1,QString right2, const bool deplacement);
		/**
				*  \brief Renvoi en QString le type de l'objet jeu
				*	 \fn    QString toString()
				*/
		QString toString() { return QString("OjMechantTourne"); }
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
				*  \brief Deplacement de l'objet jeu vers le haut
				*	 \fn    void gauche()
				*/
		void haut();
		/**
				*  \brief Deplacement de l'objet jeu vers le bas
				*	 \fn    void gauche()
				*/
		void bas();
		/**
				*  \brief Deplacement de l'objet jeu sur la gauche
				*	 \fn    void gauche()
				*/
		void gauche();

		/**
				*  \brief Indique sur quel plateforme la creature sera rataché.
				*	 \fn void setPlateforme(OjPlateforme *p)

				*/
		void setPlateforme(OjPlateforme *p);



		/**
				*  \brief Accede à la plateforme rataché à la creature.
				*	 \fn OjPlateforme* getPlateforme()

				*/
		OjPlateforme* getPlateforme();



		/**
				*  \brief Decide du prochain deplacement de la creature.
				*	 \fn    void direction()
				*/
		void direction();


		/**
				*  \brief Permet de connaitre le sens de deplacement de l'objet.
				*	 \fn    bool getDeplacement()
				*/
		bool getDeplacement();



protected:

		/**
				*  \brief Chargement des sprites pour l'objet jeu
				*	 \fn    QList<QPixmap> loadListPixmap(QString u1, QString u2, QString d1, QString d2, QString l1, QString l2, QString r1, QString r2) const
				*	 \param l1 sprite 1
				*  \param l2 sprite 2
				*  \param l3 sprite 3
				*  \param l4 sprite 4
				*  \param l5 sprite 5
				*  \param l6 sprite 6
				*  \param l7 sprite 7
				*  \param l8 sprite 8
				*/
		QList<QPixmap> loadListPixmap(QString u1, QString u2, QString d1, QString d2,QString l1, QString l2, QString r1, QString r2) const;
		/**
				*  \brief Gère l'animation de l'objet jeu
				*	 \fn    void animation()
				*/
		void animation();

		int counter;/**< Permet de définir la vitesse de défilement des frames de l'objet jeu */

		bool deplacement;/**< Permet de définir le déplacement de l'objet jeu */

		qreal gravite;/**< Permet de définir la gravité de l'objet jeu */

		OjPlateforme *pf; /**< Permet de définir la plateforme rataché à l'objet jeu */
};






#endif // OJ_MECHANT_TOURNE_H
