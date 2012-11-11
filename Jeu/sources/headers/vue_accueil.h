/**
 * \file	  vue_accueil.h
 * \brief	  Classe vue accueil
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */

#ifndef VUE_ACCUEIL_H
#define VUE_ACCUEIL_H

#include "sources/headers/vue.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueAccueil;
}

/**
 * \class VueAccueil
 * \brief Classe de la vue accueil
 */
class VueAccueil : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueAccueil (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueAccueil(QWidget *parent = 0);

	/**
		*  \brief VueAccueil
		*	 \fn    ~QWITK ()
		*
		*  Destructeur de la classe VueAccueil
		*/
	~VueAccueil();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    QString toString();
		*/
	QString toString();

private:
	Ui::VueAccueil *_ui; /**< Interface graphique liée à la classe */
};

#endif // VUE_ACCUEIL_H
