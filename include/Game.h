#ifndef BJ_GAME_H
#define BJ_GAME_H

#include "Deck.h"
#include "Hand.h"

class Game{
	public:
		Deck deck;
		Hand player, dealer;
		int dealer_up_card = -1;
		int dealer_hole_card = -1;
		bool hole_dealt = false;
		
		static bool isTenValue(int r);
		void start();
		bool isBlackJack();
		bool isDealerBlackJack();
		void deal();
		void playersTurn();
		void dealersTurn();
		void scoreCheck();

};

#endif
