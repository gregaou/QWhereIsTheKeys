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
	QString lvl("niveau/%1.txt");

	int i=1;
	QFile f(lvl.arg(i));

	if(!f.exists())
		ajouterUnNiveau(new Niveau(_scene));
	while(f.exists())
	{

		f.open(QIODevice::ReadOnly);
		Niveau* n = new Niveau(_scene);
		while(!f.atEnd())
		{
			QString line = f.readLine();
			n->addObject(ObjetJeuFactory::getObjetJeu(line));
		}
		ajouterUnNiveau(n);
		f.close();

		f.setFileName(lvl.arg(++i));
	}
}

int ModelNiveau::getNbNiveau()
{
	return _niveaux.size();
}
