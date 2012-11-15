/**
 * \file	  vue_nouvelle_jeu.h
 * \brief	  Classe vue nouveau jeu
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      15/11/12
 */

#ifndef VUE_NOUVEAU_JEU_H
#define VUE_NOUVEAU_JEU_H

#include "sources/headers/vue.h"
#include "sources/headers/vue_accueil.h"
#include "sources/headers/vue_menu_jeu.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueNouveauJeu;
}

/**
 * \class VueNouveauJeu
 * \brief Classe de la vue nouveau jeu
 */
class VueNouveauJeu : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueNouveauJeu (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueNouveauJeu(QWidget *parent = 0);

	/**
		*  \brief VueNouveauJeu
		*	 \fn    ~VueNouveauJeu ()
		*
		*  Destructeur de la classe VueNouveauJeu
		*/
	~VueNouveauJeu();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    QString toString();
		*/
	QString toString();

private slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton retour
		*	 \fn    void onClicBoutonRetour();
		*/

	void onClicBoutonRetour();


private:
	Ui::VueNouveauJeu *_ui; /**< Interface graphique liée à la classe */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_NOUVEAU_JEU_H
