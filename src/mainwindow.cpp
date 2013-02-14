#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "pawn.h"
#include "playstate.h"
#include <QtDeclarative>

MainWindow::MainWindow(QWidget *parent) :
	KMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Setup context
	QDeclarativeContext *m_context;

	m_context = ui->declarativeView->rootContext();
	m_context->setContextProperty("gameData", &game);

	m_context = ui->declarativeView_2->rootContext();
	m_context->setContextProperty("gameData", &game);

	ui->declarativeView->setSource(QUrl("qrc:/qml/table.qml"));
	ui->declarativeView_2->setSource(QUrl("qrc:/qml/Tile.qml"));

	connect(&game, SIGNAL(undoEnabled(bool)), ui->pushButton, SLOT(setEnabled(bool)));

	game.newGame();
	show();
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_pushButton_pressed()
{
		game.revertLastMove();
}

void MainWindow::on_pushButton_2_pressed()
{
	game.newGame();
}
