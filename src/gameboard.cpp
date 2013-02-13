#include "gameboard.h"
#include "game.h"

Gameboard::Gameboard(Game *ptr) {
    this->game=ptr;
    int i=0,j=0;
    for(i=0;i<19;i++){
        for(j=0;j<19;j++){
            tab[i][j].initialize(j,i,this);
        }
    }
}

Gameboard::~Gameboard(){
    cleanBoard();
}

void Gameboard::cleanBoard() {
    int i=0,j=0;
    for(i=0;i<19;i++){
        for(j=0;j<19;j++){
            tab[i][j].clearField();
        }
    }
}

void Gameboard::makeMove(int x, int y) {
    tab[x][y].putPawn();
}

void Gameboard::revertMove(int x, int y) {
    tab[x][y].clearField();
}

void Gameboard::addHistory(Field next) {
    game->addHistory(next);
}

PlayState Gameboard::checkState(int x, int y) {
    int color=tab[x][y].getColor();
    int i=0,j=0;
    int counter=1;

    //horizontal
    i=x+1;
    while((i<(x+5)) && (i<19)){
        if(!(tab[i][y].isEmpty()) && (color==tab[i][y].getColor())){
            counter++;
            i++;
        }else{
            break;
        }
    }
    i=x-1;
    while((i>(x-5)) && (i>=0)){
        if(!(tab[i][y].isEmpty()) && (color==tab[i][y].getColor())){
            counter++;
            i--;
        }else{
            break;
        }
    }

    if(counter>=5){
        return game->winning(color);
    }

    //vertical
    counter = 1;
    j=y+1;
    while((j<(y+5)) && (j<19)){
        if(!(tab[x][j].isEmpty()) && (color==tab[x][j].getColor())){
            counter++;
            j++;
        }else{
            break;
        }
    }
    j=y-1;
    while((j>(y-5)) && (j>=0)){
        if(!(tab[x][j].isEmpty()) && (color==tab[x][j].getColor())){
            counter++;
            j--;
        }else{
            break;
        }
    }

    if(counter>=5){
        return game->winning(color);
    }

    //up-left to down-right
    counter = 1;
    i=x+1;
    j=y+1;
    while((i<(x+5)) && (j<(y+5)) && (i<19) && (j<19)){
        if(!(tab[i][j].isEmpty()) && (color==tab[i][j].getColor())){
            counter++;
            i++;
            j++;
        }else{
            break;
        }
    }
    i=x-1;
    j=y-1;
		while((i>(x-5)) && (j>(y-5)) && (i>=0) && (j>=0)){
        if(!(tab[i][j].isEmpty()) && (color==tab[i][j].getColor())){
            counter++;
            i--;
            j--;
        }else{
            break;
        }
    }

    if(counter>=5){
        return game->winning(color);
    }

    //down-left to up-right
    counter = 1;
    i=x+1;
    j=y-1;
    while((i<(x+5)) && (j>(y-5)) && (i<19) && (j>=0)){
        if(!(tab[i][j].isEmpty()) && (color==tab[i][j].getColor())){
            counter++;
            i++;
            j--;
        }else{
            break;
        }
    }
    i=x-1;
    j=y+1;
		while((i>(x-5)) && (j<(y+5)) && (i>=0) && (j<19)){
        if(!(tab[i][j].isEmpty()) && (color==tab[i][j].getColor())){
            counter++;
            i--;
            j++;
        }else{
            break;
        }
    }

    if(counter>=5){
        return game->winning(color);
    }

    //boardfull ?
        if(game->numberOfMoves()==(19*19)){
        return game->drawing();
    }

    //otherwise
    return InProgress;
}

void Gameboard::nextTurn() {
    game->nextTurn();
}

Pawn* Gameboard::whoNext(){
		return game->getNextPawn();
}
