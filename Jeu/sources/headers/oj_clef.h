#ifndef OJ_CLEF_H
#define OJ_CLEF_H

#include "objet_jeu_mobile.h"

class OjClef : public ObjetJeuMobile
{
public:
	explicit OjClef(const qreal x, const qreal y);
	QString toString() { return QString("OjClef"); }
	void process();

protected:
	QList<QPixmap> loadListPixmap() const;
};

#endif // OJ_CLEF_H
