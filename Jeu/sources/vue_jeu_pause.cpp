#include "sources/headers/vue_jeu_pause.h"
#include "ui_vue_jeu_pause.h"

VueJeuPause::VueJeuPause():_ui(new Ui::VueJeuPause)
{
	_ui->setupUi(this);

	connexionAffichage();
}

VueJeuPause::~VueJeuPause()
{
	delete _ui;
}

void VueJeuPause::connexionAffichage()
{
	connect(_ui->boutonReprendrePartie, SIGNAL(clicked()), this, SLOT(onClicBoutonReprendrePartie()));
}

void VueJeuPause::onClicBoutonReprendrePartie()
{
	emit reprendrePartie();
}
