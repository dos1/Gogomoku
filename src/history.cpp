#include "history.h"

History::History() {
}

void History::addToHistory(Field next){
    hist.append(next);
}
