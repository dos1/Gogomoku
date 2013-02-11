#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "field.h"
#include "playstate.h"


class Game;
class Gameboard {
	public:
    Field tab[19][19];
    Game *game;

    Gameboard(Game *ptr);
		void cleanBoard();
		void makeMove(int x, int y);
		void revertMove();
		void addHistory(Field next);
		PlayState checkState(int x,int y);
		void nextTurn();
};

#endif // GAMEBOARD_H
