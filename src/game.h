#ifndef GAME_H
#define GAME_H

#include "playstate.h"
#include "history.h"
#include "pawn.h"
#include <ctime>

class Gameboard;
class Game {
	public:
		PlayState state_play;
        time_t time_begin;
        Pawn *who_next;
				Gameboard *board;
        History the_game;
        int moves_done;

        Game();
				void newGame();
        int numberOfMoves();
				void nextTurn();
				void undoTurn();
        PlayState winning(int who);
        PlayState drawing();
};
#endif //GAME_H
