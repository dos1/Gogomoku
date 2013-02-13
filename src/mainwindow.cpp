#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "pawn.h"
#include <QtDeclarative>

MainWindow::MainWindow(QWidget *parent) :
	KMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Register Tile to be available in QML
	//qmlRegisterType<Tile>("gameCore", 1, 0, "Tile");

	// Setup context
	QDeclarativeContext *m_context;

	m_context = ui->declarativeView->rootContext();
	m_context->setContextProperty("gameData", &game);

	m_context = ui->declarativeView_2->rootContext();
	m_context->setContextProperty("gameData", &game);

	ui->declarativeView->setSource(QUrl("qrc:/qml/table.qml"));
	ui->declarativeView_2->setSource(QUrl("qrc:/qml/Tile.qml"));

	game.newGame();
	show();
}

MainWindow::~MainWindow() {
	delete ui;
}
