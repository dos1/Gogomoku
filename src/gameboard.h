#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "field.h"
#include "playstate.h"


class Game;
class Gameboard {
	private:
		Game *game;
	public:
		class MoveOutOfBounds{
			public:
				MoveOutOfBounds() {}
		};

		Gameboard(Game *ptr);
		~Gameboard();
		void cleanBoard();
		void makeMove(int x, int y);
		void revertMove(int x, int y);
		void addHistory(Field next);
		PlayState checkState(int x,int y);
		//void nextTurn();
		Pawn* whoNext();
		Field tab[19][19];
};

#endif // GAMEBOARD_H
