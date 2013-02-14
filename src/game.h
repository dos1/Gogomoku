#ifndef GAME_H
#define GAME_H

#include "playstate.h"
#include "history.h"
#include <ctime>
#include <QObject>

class Pawn;
class Gameboard;
class Field;
class Game : public QObject {
		Q_OBJECT
	private:
		PlayState state_play;
		time_t time_begin;
		time_t time_end;
		QString time_str;
		Pawn *who_next;
		Gameboard *board;
		History the_story;
		void nextTurn();
		void undoTurn();
	public:
		Game(QObject *parent=0);
		~Game();

		PlayState winning(int who);
		PlayState drawing();
		void addHistory(Field next);

		Q_PROPERTY(int nextColor READ getNextColor NOTIFY playerChanged)
		int getNextColor();

		Pawn* getNextPawn();

		Q_PROPERTY(int state READ getState NOTIFY stateChanged)
		PlayState getState();

		Q_PROPERTY(int moves READ getMoveCount NOTIFY playerChanged)
		int getMoveCount();

		Q_PROPERTY(QString time READ getTime NOTIFY stateChanged)
		QString getTime() { return time_str; }

		void stopTimer();
		time_t gameTime();
		Gameboard *getBoard();
	public slots:
		void newGame();
		void revertLastMove();
		void makeMove(int x, int y);
	signals:
		void newGameStarted();
		void stateChanged();
		void playerChanged();
		void tileCleared(int number);
		void undoEnabled(bool undo);
};
#endif //GAME_H
