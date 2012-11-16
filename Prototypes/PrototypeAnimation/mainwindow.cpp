#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QDebug>

#include "vue_jeu.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QWidget *vue = new VueJeu();
	vue->setFocusPolicy(Qt::StrongFocus);
	vue->setFocus();
	setCentralWidget(vue);
}

MainWindow::~MainWindow()
{
	delete ui;
}
