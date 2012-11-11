/**
 * \file			profil.h
 * \brief			Structure de donn�e repr�sentant un profil de joueur.
 * \author    Soci�t� de D�veloppement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */
#ifndef PROFIL_H
#define PROFIL_H
/**
 * \class Profil
 * \brief Structure de donn�e repr�sentant un profil de joueur.
 *
 */
class Profil
{
private:
	QString _nom; /**< Nom du profil du joueur */
	QList < QPair < int, int > > _resultatsNiveaux; /**< Liste des temps r�alis�s sur les niveaux d�j� compl�t�s */
public:
	/**
		*  \brief Constructeur
		*	 \fn    Profil(QString nom)
		*  \param nom D�finit le nom du profil
		*
		*  Constructeur de la classe Profil
		*/
	Profil(QString nom);
	/**
		*  \brief Accesseur de la donn�e membre _nom
		*	 \fn    QString getNom()
		*  \return Nom du profil
		*/
	QString getNom();
	/**
		*  \brief Accesseur de la donn�e membre _resultatsNiveaux
		*	 \fn    QList getResultatsNiveaux()
		*  \return Liste des temps r�alis�s sur les niveaux d�j� compl�t�s
		*/
	QList getResultatsNiveaux();
	/**
		*  \brief Mutateur de la donn�e membre _nom
		*	 \fn    void setNom(QString nom)
		*  \param nom Nouveau nom du profil
		*/
	void setNom(QString nom);
	/**
		*  \brief Ajoute un couple (identifiant de niveau)/(temps pour terminer le niveau) dans la liste des r�sultats
		*	 \fn    bool ajouterResultatNiveau(int idNiveau, int temps)
		*  \return Vrai si l'ajout a �t� �ffectuer | Faux
		*/
	bool ajouterResultatNiveau(int idNiveau, int temps);
	/**
		*  \brief Ajoute un nouveau temps pour un niveau donn�
		*	 \fn    bool ajouterResultat(int idNiveau)
		*  \return Vrai si l'ajout a �t� �ffectuer | Faux
		*/
	bool ajouterResultat(int idNiveau);
};

#endif // PROFIL_H
