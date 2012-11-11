/**
 * \file
 * \author    Miroslav
 * \version   1.0
 * \date       12 Novembre 2009
 * \brief       Définit les modèles de voiture et leur particularités.
 *
 * \details    Cette classe surcharge les accesseurs standards du module_voiture pour
 *                  convenir aux spécificités des différents modèles possibles.
 */

#ifndef QWITK_H
#define QWITK_H

#include <QMainWindow>

namespace Ui {
	class QWITK;
}

class QWITK : public QMainWindow
{
	Q_OBJECT

public:
	explicit QWITK(QWidget *parent = 0);
	~QWITK();

public slots:

private:
	Ui::QWITK *ui;
};

#endif // QWITK_H
