#include "history.h"

History::History() {
}

void History::addToHistory(Field next){
	hist.append(next);
}

Field History::takeFromHistory(){

	return hist.takeLast();

}

void History::cleanHistory(){
	hist.clear();
}

bool History::notEmpty(){
	if(hist.isEmpty()){
		return FALSE;
	}
	return TRUE;
}
