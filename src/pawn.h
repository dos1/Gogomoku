#ifndef PAWN_H
#define PAWN_H

class Pawn {
	public:
		Pawn() {}
    virtual int getColor() = 0;
	protected:
		~Pawn() {}
};

class WhitePawn : Pawn {
	public:
		int getColor();
	protected:
		~WhitePawn() {}
};

class BlackPawn : Pawn {
	public:
		int getColor();
	protected:
		~BlackPawn() {}
};


#endif // PAWN_H
