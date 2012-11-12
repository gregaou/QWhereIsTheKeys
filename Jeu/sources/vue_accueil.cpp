#include "sources/headers/vue_accueil.h"
#include "ui_vue_accueil.h"
#include <QDebug>
VueAccueil::VueAccueil(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueAccueil)
{
	_ui->setupUi(this);

	connect(_ui->boutonQuitter,SIGNAL(clicked()),_qwitk,SLOT(close()));

}

VueAccueil::~VueAccueil()
{
	delete _ui;
}


QString VueAccueil::toString()
{
	return QString("VueAccueil");
}
