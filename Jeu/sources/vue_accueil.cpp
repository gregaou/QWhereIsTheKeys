#include "sources/headers/vue_accueil.h"
#include "ui_vue_accueil.h"

VueAccueil::VueAccueil(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueAccueil)
{}

VueAccueil::~VueAccueil()
{
	delete _ui;
}

QString VueAccueil::toString()
{
	return QString("VueAccueil");
}
