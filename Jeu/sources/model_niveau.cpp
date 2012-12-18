#include "sources/headers/model_niveau.h"

void ModelNiveau::ajouterUnNiveau(Niveau *n)
{
	_niveaux.append(n);
}

QList<Niveau*> ModelNiveau::getNiveaux()
{
	return _niveaux;
}

void ModelNiveau::setScene(QGraphicsScene* scene)
{
	_scene = scene;
}

QGraphicsScene *ModelNiveau::getScene()
{
	return _scene;
}

void ModelNiveau::chargerNiveaux()
{
	Niveau* n = new Niveau(_scene);

	QFile f("niveau/1.txt");
	f.open(QIODevice::ReadOnly);

	while(!f.atEnd())
	{
		QString line = f.readLine();
		n->addObject(ObjetJeuFactory::getObjetJeu(line));
	}
	ajouterUnNiveau(n);
	f.close();
}

int ModelNiveau::getNbNiveau()
{
	return _niveaux.size();
}
