#ifndef VUE_CHARGEMENT_JEU_H
#define VUE_CHARGEMENT_JEU_H

#include "sources/headers/vue.h"
#include "sources/headers/vue_profil.h"
#include "sources/headers/vue_menu_jeu.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueChargementJeu;
}

/**
 * \class VueChargementJeu
 * \brief Classe de la Vue Chargement Jeu
 */
class VueChargementJeu : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueChargementJeu (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueChargementJeu(QWidget *parent = 0);

	/**
		*  \brief VueChargementJeu
		*	 \fn    ~VueChargementJeu ()
		*
		*  Destructeur de la classe VueChargementJeu
		*/
	~VueChargementJeu();

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
	Ui::VueChargementJeu *_ui; /**< Interface graphique liée à la classe */
	ModelJeu *_mJeu;					/**< Modèle de données du jeu */
	QList<QPushButton> _listeB;

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
	/**
		*  \brief Actualise la liste des niveaux débloqués
		*  \fn void actualiseListeNiveaux
		*/
	void actualiseListeNiveaux();
};


#endif // VUE_CHARGEMENT_JEU_H
