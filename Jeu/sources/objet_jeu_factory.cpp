#include "sources/headers/objet_jeu_factory.h"

ObjetJeu* ObjetJeuFactory::getObjetJeu(QString line)
{
	QStringList list = line.trimmed().split(SEP_FIC_NIV);
	if (list.size() > 0)
	{
		QString nom = list.at(0);

		if(nom == "OjHeros" && list.size() == 3)
			return new OjHeros(list.at(1).toFloat(),list.at(2).toFloat());

		else if (nom == "OjClef" && list.size() == 3)
			return new OjClef(list.at(1).toFloat(),list.at(2).toFloat());

		else if (nom == "OjFixAnime" && list.size() == 7)
			return new OjFixAnime(list.at(1).toFloat(),list.at(2).toFloat(),
														list.at(3),list.at(4),
														list.at(5),list.at(6));

		else if (nom == "OjMechantSimple" && list.size() == 8 )
			return new OjMechantSimple(list.at(1).toFloat(),list.at(2).toFloat(),
																 list.at(3),list.at(4),
																 list.at(5),list.at(6),
																 list.at(7).toInt());

		else if (nom == "OjPlateforme" && list.size() == 5)
			return new OjPlateforme(list.at(1).toFloat(),list.at(2).toFloat(),
															list.at(3).toFloat(),list.at(4).toFloat());

		else if (nom == "OjMechantTourne" && list.size() == 12)
			return new OjMechantTourne(list.at(1).toFloat(),list.at(2).toFloat(),
																 list.at(3),list.at(4),
																 list.at(5),list.at(6),
																 list.at(7),list.at(8),
																 list.at(9),list.at(10),
																 list.at(11).toInt());
	}

	return new OjPlateforme(0,0,0,0);
}
