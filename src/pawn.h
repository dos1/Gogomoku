#ifndef PAWN_H
#define PAWN_H

class Pawn
{
public:
    Pawn();
    virtual int getColor() = 0;
};

class WhitePawn :: Pawn
{
public:
    int getColor();
};

class BlackPawn :: Pawn
{
public:
    int getColor();
};
#endif // PAWN_H
