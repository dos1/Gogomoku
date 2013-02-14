#include "history.h"

History::History() {
}

void History::addToHistory(Field next){
	hist.append(next);
}

Field History::takeFromHistory(){
    if(notEmpty()==FALSE){
        throw new EmptyHistory();
    }
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

int History::countHistory() {
	return hist.count();
}
