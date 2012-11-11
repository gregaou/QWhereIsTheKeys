/**
 * \file			qwitk.h
 * \brief			Fenêtre principale
 * \author    Société de Développement de Projets Informatique
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
 * \brief Classe de la fenêtre principale
 *
 *  La classe gère la fenêtre principale
 */
class QWITK : public QMainWindow
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit QWITK (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
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
	Ui::QWITK *ui; /**< Interface graphique liée à la classe */
};

#endif // QWITK_H
