#ifndef JEU_H
#define JEU_H

#include "zone_jeu.h"
#include "carre.h"

class VueJeu : public QWidget
{
	Q_OBJECT
public:
	explicit VueJeu(QWidget *parent = 0);
	~VueJeu();

protected:
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:
	QGraphicsScene _scene;
	QGraphicsView _view;
	Carre *c;
};

#endif // JEU_H
