/**
 * \file	  profil.h
 * \brief	  Structure de donnée représentant un profil de joueur.
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */
#ifndef PROFIL_H
#define PROFIL_H

#include <QMap>
#include <QString>
/**
 * \class Profil
 * \brief Structure de donnée représentant un profil de joueur.
 */
class Profil
{
private:
	QString _nom; /**< Nom du profil du joueur */
	QMap<int, int> _resultatsNiveaux; /**< Liste des temps réalisés sur les niveaux déjà complétés */
public:
	/**
		*  \brief Constructeur
		*	 \fn    Profil(QString nom)
		*  \param nom Définit le nom du profil
		*
		*  Constructeur de la classe Profil
		*/
	Profil(QString nom);
	/**
		*  \brief Accesseur de la donnée membre _nom
		*	 \fn    QString getNom()
		*  \return Nom du profil
		*/
	QString getNom();
	/**
		*  \brief Accesseur de la donnée membre _resultatsNiveaux
		*	 \fn    QMap getResultatsNiveaux()
		*  \return Liste des temps réalisés sur les niveaux déjà complétés
		*/
	QMap<int,int> getResultatsNiveaux();
	/**
		*  \brief Accesseur de la donnée temps de _resultatsNiveau en fonction du niveau
		*	 \fn    int getResultat(int idNiveau)
		*	 \param idNiveau Identifiant du niveau
		*  \return Temps du niveau identifié par idNiveau | 0 si le niveau n'existe pas
		*/
	int getResultat(int idNiveau);
	/**
		*  \brief Calcule le temps total de tout les niveaux
		*	 \fn    int getTempsTotal()
		*  \return Temps total de tout les niveaux
		*/
	int getTempsTotal();
	/**
		*  \brief Mutateur de la donnée membre _nom
		*	 \fn    void setNom(QString nom)
		*  \param nom Nouveau nom du profil
		*/
	void setNom(QString nom);
	/**
		*  \brief Ajoute un couple (identifiant de niveau)/(temps pour terminer le niveau) dans la liste des résultats
		*	 \fn    bool ajouterResultatNiveau(int idNiveau, int temps)
		*  \param idNiveau Identifiant du niveau
		*  \param temps Temps réalisé sur le niveau
		*/
	void ajouterResultatNiveau(int idNiveau, int temps);
};

#endif // PROFIL_H
