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
		Pawn *who_next;
		Gameboard *board;
		History the_story;
		int moves_done;
	public:
		Game(QObject *parent=0);
		~Game();
		int numberOfMoves();
		PlayState winning(int who);
		PlayState drawing();
		void addHistory(Field next);

		Q_PROPERTY(int nextColor READ getNextColor NOTIFY playerChanged);
		int getNextColor();

		Pawn* getNextPawn();

		PlayState getState();
		void stopTimer();
		time_t gameTime();
		Gameboard *getBoard();
	public slots:
		void newGame();
		void nextTurn();
		void undoTurn();
		void revertLastMove();
	signals:
		void newGameStarted();
		void playerChanged();
		void boardChanged(); //?
};
#endif //GAME_H
