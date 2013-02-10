#ifndef HISTORY_H
#define HISTORY_H

#include <QList>
#include "pawn.h"

class History
{
public:
    QList<Pawn> hist;

    History();
    addToHistory(Pawn);
    Pawn takeFromHistory();
};

#endif // HISTORY_H
