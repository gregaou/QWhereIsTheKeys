/**
 * \file	  vue_menu_jeu.h
 * \brief	  Classe vue menu jeu
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      15/11/12
 */


#ifndef VUE_JEU_MENU_H
#define VUE_JEU_MENU_H

#include "sources/headers/vue.h"
#include "sources/headers/vue_jeu.h"
#include "sources/headers/vue_accueil.h"
#include "sources/headers/vue_jeu_nouveau.h"
#include "sources/headers/vue_jeu_charger.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueJeuMenu;
}

/**
 * \class VueJeuMenu
 * \brief Classe de la vue Jeu Menu
 */
class VueJeuMenu : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueJeuMenu (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueJeuMenu(QWidget *parent = 0);

	/**
		*  \brief VueJeuMenu
		*	 \fn    ~VueJeuMenu ()
		*
		*  Destructeur de la classe VueJeuMenu
		*/
	~VueJeuMenu();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();

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
		*	 \fn    void onClicBoutonCreerPartieMultijoueur();
		*/
	void onClicBoutonCreerPartieMultijoueur();
	/**
		*  \brief Action lorsque l'on clic sur le bouton rejoindre partie en ligne
		*	 \fn    void onClicBoutonRejoindrePartieMultijoueur();
		*/
	void onClicBoutonRejoindrePartieMultijoueur();
	/**
		*  \brief Action lorsque l'on clic sur le bouton Quitter Menu Jeu
		*	 \fn    void onClicBoutonQuitterMenuJeu();
		*/
	void onClicBoutonQuitterMenuJeu();

private:
	Ui::VueJeuMenu *_ui; /**< Interface graphique liée à la classe */
	ModelJeu *_mJeu; /**< Modèle de données du jeu */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_JEU_MENU_H
