/**
 * \file	    vue_jeu_pause.h
 * \brief	    Classe vue jeu pause
 * \author    BUISSON Fabien, BOSSOLA Gr�gory
 * \version   1.0
 * \date      01/12/12
 */

#ifndef VUE_JEU_PAUSE_H
#define VUE_JEU_PAUSE_H

#include <QWidget>

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueJeuPause;
}
/**
 * \class VueJeuPause
 * \brief Classe de la vue jeu pause
 */
class VueJeuPause : public QWidget
{
	Q_OBJECT
private:
	Ui::VueJeuPause* _ui; /**< Interface graphique liée �  la classe */
public:
	/**
		*  \brief Constructeur
		*	 \fn    VueJeuPause()
		*/
	VueJeuPause();
	/**
		*  \brief Destructeur
		*	 \fn   ~VueJeuPause()
		*/
	~VueJeuPause();
	/**
		*  \brief Connecte les signaux des éléments de l'interface �
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();

signals:
	/**
		*  \brief Signal émit lorsque le bouton reprendrePartie est cliqué
		*  \fn void reprendrePartie()
		*/
	void reprendrePartie();

	/**
		*  \brief Signal émit lorsque le bouton retour au niveau est cliqué
		*  \fn void retourMenu()
		*/
	void retourMenu();


private slots:
	void onClicBoutonReprendrePartie();
	void onClicBoutonRetourMenu();
};
#endif // VUE_JEU_PAUSE_H
