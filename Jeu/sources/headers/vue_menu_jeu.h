/**
 * \file	  vue_menu_jeu.h
 * \brief	  Classe vue menu jeu
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */


#ifndef VUE_MENU_JEU_H
#define VUE_MENU_JEU_H

#include "sources/headers/vue.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueMenuJeu;
}

/**
 * \class VueMenuJeu
 * \brief Classe de la vue Menu Jeu
 */
class VueMenuJeu : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueMenuJeu (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueMenuJeu(QWidget *parent = 0);

	/**
		*  \brief VueMenuJeu
		*	 \fn    ~VueMenuJeu ()
		*
		*  Destructeur de la classe VueAccueil
		*/
	~VueMenuJeu();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    QString toString();
		*/
	QString toString();

private slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton nouvelle partie
		*	 \fn    void onClicBoutonNouvellePartie();
		*/

	void onClicBoutonNouvellePartie();
	/**
		*  \brief Action lorsque l'on clic sur le bouton charger partie
		*	 \fn    void onClicBoutonChargerPartie();
		*/
	void onClicBoutonChargerPartie();
	/**
		*  \brief Action lorsque l'on clic sur le bouton creer partie en ligne
		*	 \fn    void onClicBoutonSupprimerProfil();
		*/
	void onClicBoutonCreerPartieMultijoueur();
	/**
		*  \brief Action lorsque l'on clic sur le bouton rejoindre partie en ligne
		*	 \fn    void onClicBoutonRejoindrePartieEnLigne();
		*/
	void onClicBoutonRejoindrePartieMultijoueur();

private:
	Ui::VueMenuJeu *_ui; /**< Interface graphique liée à la classe */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_MENU_JEU_H
