#include "game.h"
#include "pawn.h"
#include "gameboard.h"
#include <QObject>

Game::Game(QObject *parent) : QObject(parent) {
	who_next = NULL;
	board = new Gameboard(this);
	this->newGame();
}

void Game::newGame(){
	time_begin = time(0);
	time_end = 0;
	if(who_next!=NULL){
		free(who_next);
	}
	who_next = (Pawn*) new BlackPawn;
	playerChanged();
	state_play = InProgress;
	moves_done = 0;
	the_story.cleanHistory();
	board->cleanBoard();
	newGameStarted();
	stateChanged();
	undoEnabled(false);
}

Game::~Game(){
	if(who_next!=NULL){
		free(who_next);
	}
	delete board;
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
	playerChanged();
}

void Game::undoTurn(){
	if(who_next->getColor()==0){
		who_next = (Pawn*) new BlackPawn;
	}else{
		who_next = (Pawn*) new WhitePawn;
	}
	moves_done--;
	playerChanged();
}

PlayState Game::winning(int who){
	if(who==0){
		state_play = WinWhite;
	}else{
		state_play = WinBlack;
	}
	stopTimer();
	stateChanged();
	undoEnabled(false);
	return state_play;
}

PlayState Game::drawing(){
	state_play = Draw;
	stopTimer();
	stateChanged();
	undoEnabled(false);
	return state_play;
}

void Game::makeMove(int x, int y) {
	board->makeMove(x,y);
	nextTurn();
}

void Game::addHistory(Field next){
	the_story.addToHistory(next);
	undoEnabled(true);
}

void Game::revertLastMove(){
	Field pom;
	if(the_story.notEmpty()){
		pom=the_story.takeFromHistory();
		board->revertMove(pom.getX(),pom.getY());
		tileCleared(pom.getX()*19+pom.getY());
		undoTurn();
	}
	if(!the_story.notEmpty()){
		undoEnabled(false);
	}
}

Pawn *Game::getNextPawn(){
	return this->who_next;
}

int Game::getNextColor(){
	return this->who_next->getColor();
}

PlayState Game::getState(){
	return state_play;
}

void Game::stopTimer(){
	time_end = time(0);
}

time_t Game::gameTime(){
	if(time_end!=0){
		return (time_end-time_begin);
	}else{
		return (time(0)-time_begin);
	}
}

Gameboard *Game::getBoard(){
	return board;
}
