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
    int getCorlor();
};

class BlackPawn :: Pawn
{
public:
    int getCorlor();
};
#endif // PAWN_H
