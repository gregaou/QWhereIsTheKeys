/**
 * \file			profil.h
 * \brief			Structure de donnée représentant un profil de joueur.
 * \author    BOSSOLA Grégory
 * \version   1.0
 * \date      11/11/12
 */
#ifndef PROFIL_H
#define PROFIL_H

#include <QMap>
#include <QString>
#include <QStringList>
#include <QTime>

/**
 * \class Profil
 * \brief Structure de donnée représentant un profil de joueur.
 */
class Profil
{
private:
	QString _nom; /**< Nom du profil du joueur */
	QMap<int, QTime> _resultatsNiveaux; /**< Liste des temps réalisés sur les niveaux déjà complétés */
	static const QString _sep; /**< Séparateur */
public:
	/**
		*  \brief Constructeur
		*	 \fn    Profil()
		*
		*  Constructeur de la classe Profil
		*/
	Profil();
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
		*	 \fn    QString getNom() const
		*  \return Nom du profil
		*/
	QString getNom() const;
	/**
		*  \brief Accesseur de la donnée membre _resultatsNiveaux
		*	 \fn    QMap getResultatsNiveaux() const
		*  \return Liste des temps réalisés sur les niveaux déjà complétés
		*/
	QMap<int,QTime> getResultatsNiveaux() const;
	/**
		*  \brief Accesseur de la donnée temps de _resultatsNiveau en fonction du niveau
		*	 \fn    int getResultat(int idNiveau)
		*	 \param idNiveau Identifiant du niveau
		*  \return Temps du niveau identifié par idNiveau | 0 si le niveau n'existe pas
		*/
	QTime getResultat(int idNiveau);
	/**
		*  \brief Calcule le temps total de tout les niveaux
		*	 \fn    int getTempsTotal()
		*  \return Temps total de tout les niveaux
		*/
	QTime getTempsTotal();
	/**
		*  \brief Mutateur de la donnée membre _nom
		*	 \fn    void setNom(QString nom)
		*  \param nom Nouveau nom du profil
		*/
	void setNom(QString nom);
	/**
		*  \brief Mutateur de la donnée membre _resultatsNiveaux
		*	 \fn    void setResultatsNiveaux(QMap<int,int> resultatsNiveaux)
		*  \param resultatsNiveaux Nouveaux scores
		*/
	void setResultatsNiveaux(QMap<int, QTime> resultatsNiveaux);
	/**
		*  \brief Ajoute un couple (identifiant de niveau)/(temps pour terminer le niveau) dans la liste des résultats
		*	 \fn    bool ajouterResultatNiveau(int idNiveau, QTime temps)
		*  \param idNiveau Identifiant du niveau
		*  \param temps Temps réalisé sur le niveau
		*/
	void ajouterResultatNiveau(int idNiveau, QTime temps);
	/**
		*  \brief Opérateur d'égalité
		*	 \fn    bool operator== (const Profil & p)
		*  \param p Profil à comparer
		*  \return Vrai si égalité sinon Faux
		*/
	bool operator== (const Profil & p);
	/**
		*  \brief Créer un profil à partir d'une chaine de caractères
		*	 \fn    static Profil* fromString(QString str)
		*  \param str Chaine de caractères représentant un profil et ses scores, sous la forme "<nom_du_profil><séparateur><idNiveau><temps><séparateur><idNiveau><temps>..."
		*  \return Profil correspondant à la chaine de caractères
		*/
	static Profil* fromString(QString str);
	/**
		*  \brief Créer une chaine de caractères sous la forme "<nom_du_profil><séparateur><idNiveau><séparateur><temps><séparateur><idNiveau><séparateur><temps>..." à partir d'un Profil
		*	 \fn    QString toString()
		*/
	QString toString();
};

#endif // PROFIL_H
