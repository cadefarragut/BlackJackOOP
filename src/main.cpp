#include <iostream>
#include <algorithm>
#include <random>
#include "Game.h"
#include "Cards.h"

int main(){
	Game blackjack;
	std::mt19937 rng(time(nullptr));
	shuffle(cards.begin(), cards.end(), rng);
	while(cards.size() >= 4){
		blackjack.start();
		blackjack.deal();
		if (blackjack.isBlackJack()) {
			std::cout << std::endl;
			continue;
		}
		blackjack.playersTurn();
		if ( blackjack.player.count < 22){
			blackjack.dealersTurn();	
		}	
		blackjack.scoreCheck();
		std::cout << std::endl;
	}
	std::cout << "Deck is out. Thanks for playing!" << std::endl;
	return 0;
}
