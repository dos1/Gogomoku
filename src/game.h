#ifndef GAME_H
#define GAME_H

#include "gameboard.h"
#include "playstate.h"

class Game {
	public:
		PlayState state_play;
        time_t time_begin;
        Pawn *who_next;
        Gameboard board;
        History the_game;

        Game();
        newGame();
        revertMove();

}
#endif //GAME_H
