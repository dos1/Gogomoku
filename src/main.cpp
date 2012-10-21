#include "mainwindow.h"
#include <KApplication>
#include <KCmdLineArgs>
#include <KAboutData>

int main(int argc, char *argv[])
{
	KAboutData aboutData("gogomoku", 0, ki18n("Gogomoku"), "0.0.1",
											 ki18n("Simple Gomoku game."),
											 KAboutData::License_GPL,
											 ki18n("Copyright (C) 2012 Marcin Błaszyk, Marcin Jankowski, Sebastian Krzyszkowiak") );
	KCmdLineArgs::init(argc, argv, &aboutData);
	KApplication a;
	new MainWindow;
	return a.exec();
}
