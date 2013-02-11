#ifndef HISTORY_H
#define HISTORY_H

#include <QList>
#include "field.h"

class History {
	public:
		QList<Field> hist;

    History();
		void addToHistory(Field);
		Field takeFromHistory();
};

#endif // HISTORY_H
