#ifndef HISTORY_H
#define HISTORY_H

#include <QList>
#include "pawn.h"

class Historym{
	public:
    QList<Field> hist;

    History();
    addToHistory(Field);
    Field takeFromHistory();
};

#endif // HISTORY_H
