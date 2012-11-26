/**
 * \file	    vue_nouveau_jeu.h
 * \brief	    Classe vue nouveau jeu
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      15/11/12
 */

#ifndef VUE_JEU_NOUVEAU_H
#define VUE_JEU_NOUVEAU_H

#include "sources/headers/vue.h"
#include "sources/headers/vue_accueil.h"
#include "sources/headers/vue_jeu_menu.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueJeuNouveau;
}

/**
 * \class VueJeuNouveau
 * \brief Classe de la vue jeu nouveau
 */
class VueJeuNouveau : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueJeuNouveau (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueJeuNouveau(QWidget *parent = 0);

	/**
		*  \brief VueJeuNouveau
		*	 \fn    ~VueJeuNouveau ()
		*
		*  Destructeur de la classe VueJeuNouveau
		*/
	~VueJeuNouveau();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();

private slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton retour
		*	 \fn    void onClicBoutonRetour();
		*/

	void onClicBoutonRetour();


private:
	Ui::VueJeuNouveau *_ui; /**< Interface graphique liée à la classe */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_JEU_NOUVEAU_H
