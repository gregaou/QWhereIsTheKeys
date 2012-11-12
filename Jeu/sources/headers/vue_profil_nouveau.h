/**
 * \file	    vue_profil_nouveau.h
 * \brief	    Classe vue création nouveau profil
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      12/11/12
 */


#ifndef VUE_PROFIL_NOUVEAU_H
#define VUE_PROFIL_NOUVEAU_H

#include "sources/headers/vue.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueProfilNouveau;
}

/**
 * \class VueProfilNouveau
 * \brief Classe de la vue nouveau profil
 */
class VueProfilNouveau : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueProfilNouveau (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueProfilNouveau(QWidget *parent = 0);

	/**
		*  \brief VueProfilNouveau
		*	 \fn    ~VueProfilNouveau ()
		*
		*  Destructeur de la classe VueProfilNouveau
		*/
	~VueProfilNouveau();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    QString toString();
		*/
	QString toString();

private slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton annuler
		*	 \fn    void onClicBoutonAnnuler();
		*/
	void onClicBoutonAnnuler();


private:
	Ui::VueProfilNouveau *_ui; /**< Interface graphique liée à la classe */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_PROFIL_NOUVEAU_H
