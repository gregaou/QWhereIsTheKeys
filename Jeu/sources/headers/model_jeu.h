/**
 * \file	    model_jeu.h
 * \brief	    Structure de donnÃ©e reprÃ©sentant le jeu.
 * \author    BOSSOLA Grégory
 * \version   1.0
 * \date      16/11/12
 */
#ifndef MODEL_JEU_H
#define MODEL_JEU_H

#include "sources/headers/model_profil.h"
#include <QTime>
/**
 * \class ModelJeu
 * \brief Structure de donnÃ©e reprÃ©sentant un jeu.
 */
class ModelJeu : public Singleton<ModelJeu>
{
	friend class Singleton<ModelJeu>;
private:
	ModelProfil * _profils; /**< ModÃšle de profils de joueurs */
	int _idProfil; /**< Identifiant du profil chargÃ© */
	int _niveauSelectionne; /**< Identifiant du niveau sÃ©lectionnÃ© */
	QTime _tempsNiveau; /**< Temps rÃ©alisÃ© du niveau sÃ©lectionnÃ© */
	/**
		*  \fn    ModelJeu()
		*  \brief Constructeur
		*/
	ModelJeu();
public:
	/**
		*  \brief Mutateur de la donnÃ©e membre idProfil
		*	 \fn    void setIdProfil(int id)
		*	 \param id Identifiant du profil chargÃ©
		*/
	void setIdProfil(int id);
	/**
		*  \brief Mutateur de la donnÃ©e membre niveauSelectionne
		*	 \fn    void setNiveauSelectionne(int niveauSelectionne)
		*	 \param niveauSelectionne Identifiant du niveau sÃ©lectionnÃ©
		*/
	void setNiveauSelectionne(int niveauSelectionne);
	/**
		*  \brief RÃ©cupÃšre le niveau sÃ©lectionnÃ©
		*	 \fn    int getNiveauSelectionne()
		*  \return Le niveau sÃ©lectionnÃ©
		*/
	int getNiveauSelectionne();
	/**
		*  \brief RÃ©cupÃšre le nom du profil
		*	 \fn    void getNomProfil()
		*  \return QString le nom du profil
		*/
	QString getNomProfil();
	/**
		*  \brief Mutateur de la donnÃ©e membre _tempsNiveau
		*	 \fn    void setTempsNiveau(QTime temps)
		*  \param temps Temps rÃ©alisÃ© sur le niveau sÃ©lectionnÃ©
		*/
	void setTempsNiveau(QTime temps);
	/**
		*  \brief RÃ©cupÃšre le temps du niveau
		*	 \fn    QTime getTempsNiveau()
		*  \return QTime le temps du niveau
		*/
	QTime getTempsNiveau();

	/**
		*  \brief Retourne le dernier niveau terminÃ© et sauvegardÃ©
		*	 \fn    virtual int getDernierNiveauTermine()
		*	 \return Dernier niveau terminÃ© et sauvegardÃ©
		*/
	int getDernierNiveauTermine();
	/**
		*  \brief Ajoute un score associÃ© Ã  un niveau dans le profil joueur
		*	 \fn    virtual bool ajouterScore(int idNiveau, int temps)
		*  \param idNiveau Identifiant du niveau
		*  \param temps Temps Ã  ajoutÃ©
		*	 \return Vrai le score est sauvegardÃ© sinon Faux
		*/
	bool ajouterScore(int idNiveau, QTime temps);
};

#endif // MODEL_JEU_H
