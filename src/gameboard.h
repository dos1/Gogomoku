#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "field.h"
#include "game.h"

class Gameboard
{
public:
    Field tab[19][19];
    class Game *game;

    Gameboard();
    cleanBoard();
    makeMove(int x, int y);
    revertMove(int x, int y);
};

#endif // GAMEBOARD_H
