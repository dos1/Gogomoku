#include "board.h"
#include "playstate.h"

class Game {
	public:
        gamestate state;
		PlayState state_play;
        time_t time_begin;
        Pawn who_next;
        gameboard board;
        History the_game;

}
