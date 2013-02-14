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
		
	private slots:
		void on_pushButton_pressed();

		void on_pushButton_2_pressed();

	private:
		Ui::MainWindow *ui;
		Game game;
};

#endif // MAINWINDOW_H
