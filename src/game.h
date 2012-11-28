#include "board.h"
#include "playstate.h"

class Game {
	public:
		Board state;
		PlayState state_play;
		time_t time_begin;

		void add_move(Move move);
		Move undo_move();
		PlayState check_state();
		time_t check_time();
}
