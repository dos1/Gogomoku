#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "field.h"
#include "game.h"

class Gameboard {
	public:
    Field tab[19][19];
    Game *game;

    Gameboard(Game *ptr);
    cleanBoard();
    makeMove(int x, int y);
    revertMove();
    addHistory(Field next);
    PlayState checkState(int x,int y);
    nextTurn();
};

#endif // GAMEBOARD_H
