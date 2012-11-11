/**
 * \file			profil.h
 * \brief			Structure de donnée représentant un profil de joueur.
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */
#ifndef PROFIL_H
#define PROFIL_H
/**
 * \class Profil
 * \brief Structure de donnée représentant un profil de joueur.
 *
 */
class Profil
{
private:
	QString _nom; /**< Nom du profil du joueur */
	QList < QPair < int, int > > _resultatsNiveaux; /**< Liste des temps réalisés sur les niveaux déjà complétés */
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
		*	 \fn    QList getResultatsNiveaux()
		*  \return Liste des temps réalisés sur les niveaux déjà complétés
		*/
	QList getResultatsNiveaux();
	/**
		*  \brief Mutateur de la donnée membre _nom
		*	 \fn    void setNom(QString nom)
		*  \param nom Nouveau nom du profil
		*/
	void setNom(QString nom);
	/**
		*  \brief Ajoute un couple (identifiant de niveau)/(temps pour terminer le niveau) dans la liste des résultats
		*	 \fn    bool ajouterResultatNiveau(int idNiveau, int temps)
		*  \return Vrai si l'ajout a été éffectuer | Faux
		*/
	bool ajouterResultatNiveau(int idNiveau, int temps);
	/**
		*  \brief Ajoute un nouveau temps pour un niveau donné
		*	 \fn    bool ajouterResultat(int idNiveau)
		*  \return Vrai si l'ajout a été éffectuer | Faux
		*/
	bool ajouterResultat(int idNiveau);
};

#endif // PROFIL_H
