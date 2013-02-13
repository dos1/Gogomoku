#ifndef HISTORY_H
#define HISTORY_H

#include <QList>
#include "field.h"

class History {
	private:
		QList<Field> hist;
	public:
		History();
		void addToHistory(Field next);
		Field takeFromHistory();
		void cleanHistory();
		bool notEmpty();
};

#endif // HISTORY_H
