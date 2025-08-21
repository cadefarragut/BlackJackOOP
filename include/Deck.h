#ifndef BJ_DECK_H
#define BJ_DECK_H

#include <string>
#include "Cards.h"

class Deck{
	public:
	int deckEmpty();
	int newCard();
	std::string cardtoString(int card);
	int peek();

};

#endif
