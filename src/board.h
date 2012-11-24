#include "move.h"
#include "color.h"

class Board {
	public:
		short int size;
		Color fields[size][size];
		Color who_to_move;
		Move history[];
}
