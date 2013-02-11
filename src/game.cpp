#include "game.h"

Game::Game(){
    time_begin = time(0);
    who_next = (Pawn*) new BlackPawn;
    state_play = InProgress;
    moves_done = 0;
}

void Game::newGame(){
    time_begin = time(0);
    who_next = (Pawn*) new BlackPawn;
    state_play = InProgress;
    moves_done = 0;
}

int Game::numberOfMoves(){
    return moves_done;
}

void Game::nextTurn(){
    if(who_next->getColor()==0){
        who_next = (Pawn*) new BlackPawn;
    }else{
        who_next = (Pawn*) new WhitePawn;
    }
    moves_done++;
}

void Game::undoTurn(){
    if(who_next->getColor()==0){
        who_next = (Pawn*) new BlackPawn;
    }else{
        who_next = (Pawn*) new WhitePawn;
    }
    moves_done--;
}

PlayState Game::winning(int who){
    if(who==0){
        state_play = WinWhite;
    }else{
        state_play = WinBlack;
    }
    return state_play;
}

PlayState Game::drawing(){
    state_play = Draw;
    return state_play;
}
