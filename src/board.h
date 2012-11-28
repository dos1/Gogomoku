#include "move.h"
#include "color.h"
#include "playstate.h"

class Board {
	public:
		short int size;
		Color fields[size][size];
		Color who_to_move;
		Move history[];

		void add_move(Move move);
		Move undo_move();
		PlayState check_state();
}
