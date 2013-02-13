#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <KMainWindow>
#include "game.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public KMainWindow {
		Q_OBJECT
		
	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		
	private:
		Ui::MainWindow *ui;
		Game game;
};

#endif // MAINWINDOW_H
