
/**
 * \file			oj_mechant_tourne.h
 * \brief			Structure de donnÃ©e d'un objet jeu mÃ©chant tourne
 * \author    Yannick Mahe
 * \version   1.0
 * \date      04/12/12
 */

#ifndef OJ_MECHANT_TOURNE_H
#define OJ_MECHANT_TOURNE_H
#include "oj_plateforme.h"
#include "objet_jeu_mobile.h"
/**
 * \class OjMechantTourne
 * \brief Structure de donnÃ©e reprÃ©sentant mÃ©chant tourne (dÃ©placement droite/gauche ou gauche/droite ).
 */
class OjMechantTourne : public ObjetJeuMobile
{
public:
		/**
				*  \brief Constructeur
				*	 \fn    explicit OjMechantTourne(qreal x, qreal y,QString left1,QString left2,QString right1,QString right2, const bool deplacement)
				*  \param x DÃ©finit l'abscisse de l'objet jeu
				*  \param y DÃ©finit l'ordonnÃ©e de l'objet jeu
				*  \param up1 Frame dÃ©placement haut 1
				*  \param up2 Frame dÃ©placement haut 2
				*  \param down1 Frame dÃ©placement bas 1
				*  \param down2 Frame dÃ©placement bas 2
				*  \param left1 Frame dÃ©placement gauche 1
				*  \param left2 Frame dÃ©placement gauche 2
				*  \param right Frame dÃ©placement droite 1
				*  \param right Frame dÃ©placement droite 2
				*  \param deplacement DÃ©finit le dÃ©placement initial de l'objet jeu (true = droite / false = gauche )
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
				*  \brief GÃšre l'animation de l'objet jeu
				*	 \fn    void animation()
				*/
		void animation();

		int counter;/**< Permet de dÃ©finir la vitesse de dÃ©filement des frames de l'objet jeu */

		bool deplacement;/**< Permet de dÃ©finir le dÃ©placement de l'objet jeu */

		qreal gravite;/**< Permet de dÃ©finir la gravitÃ© de l'objet jeu */

		OjPlateforme *pf; /**< Permet de dÃ©finir la plateforme rataché à l'objet jeu */
};






#endif // OJ_MECHANT_TOURNE_H
