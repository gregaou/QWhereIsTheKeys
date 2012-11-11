/**
 * \file
 * \author    Miroslav
 * \version   1.0
 * \date       12 Novembre 2009
 * \brief       D�finit les mod�les de voiture et leur particularit�s.
 *
 * \details    Cette classe surcharge les accesseurs standards du module_voiture pour
 *                  convenir aux sp�cificit�s des diff�rents mod�les possibles.
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
