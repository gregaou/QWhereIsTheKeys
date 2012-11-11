/**
 * \file			qwitk.h
 * \brief			Fen�tre principale
 * \author    Soci�t� de D�veloppement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */

#ifndef QWITK_H
#define QWITK_H

#include <QMainWindow>

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class QWITK;
}

/**
 * \class QWITK
 * \brief Classe de la fen�tre principale
 *
 *  La classe g�re la fen�tre principale
 */
class QWITK : public QMainWindow
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit QWITK (QWidget *parent = 0)
		*  \param parent D�finit le parent de la fen�tre
		*
		*  Constructeur de la classe QWITK
		*/
	explicit QWITK(QWidget *parent = 0);
	/**
		*  \brief Constructeur
		*	 \fn    ~QWITK ()
		*
		*  Destructeur de la classe QWITK
		*/
	~QWITK();

public slots:

private:
	Ui::QWITK *ui; /**< Interface graphique li�e � la classe */
};

#endif // QWITK_H
