/**
 * \file	  model_jeu.h
 * \brief	  Structure de donnée représentant le jeu.
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      16/11/12
 */
#ifndef MODEL_JEU_H
#define MODEL_JEU_H

#include "sources/headers/model_profil.h"
/**
 * \class ModelJeu
 * \brief Structure de donnée représentant un jeu.
 */
class ModelJeu : public Singleton<ModelJeu>
{
	friend class Singleton<ModelJeu>;
private:
	ModelProfil * _profils; /**< Modèle de profils de joueurs */
	int _idProfil; /**< Identifiant du profil chargé */
	int _niveauSelectionne; /**< Identifiant du niveau sélectionné */
	/**
		*  \brief Constructeur
		*	 \fn    ModelJeu()
		*
		*  Constructeur de la classe ModelJeu
		*/
	ModelJeu();
public:
	/**
		*  \brief Mutateur de la donnée membre idProfil
		*	 \fn    void setIdProfil(int id)
		*	 \param id Identifiant du profil chargé
		*/
	void setIdProfil(int id);
	/**
		*  \brief Mutateur de la donnée membre niveauSelectionne
		*	 \fn    void setNiveauSelectionne(int niveauSelectionne)
		*	 \param niveauSelectionne Identifiant du niveau sélectionné
		*/
	void setNiveauSelectionne(int niveauSelectionne);
	/**
		*  \brief Récupère le niveau sélectionné
		*	 \fn    int getNiveauSelectionne()
		*  \return Le niveau sélectionné
		*/
	int getNiveauSelectionne();
	/**
		*  \brief Récupère le nom du profil
		*	 \fn    void getNomProfil()
		*  \return QString le nom du profil
		*/
	QString getNomProfil();


	/**
		*  \brief Retourne le dernier niveau terminé et sauvegardé
		*	 \fn    virtual int getDernierNiveauTermine()
		*	 \return Dernier niveau terminé et sauvegardé
		*/
	int getDernierNiveauTermine();
	/**
		*  \brief Ajoute un score associé à un niveau dans le profil joueur
		*	 \fn    virtual bool ajouterScore(int idNiveau, int temps)
		*  \param idNiveau Identifiant du niveau
		*  \param temps Temps à ajouté
		*	 \return Vrai le score est sauvegardé sinon Faux
		*/
	bool ajouterScore(int idNiveau, int temps);
};

#endif // MODEL_JEU_H
