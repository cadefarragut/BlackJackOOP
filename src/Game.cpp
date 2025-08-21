#include "Game.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

bool Game::isTenValue(int r) {return r >= 10 && r <= 13; }

void Game::start(){
	player = Hand{};
	dealer = Hand{};
	std::cout << "Welcome to BlackJack" << std::endl;	
}

bool Game::isBlackJack(){
	if (player.count == 21 && dealer.count != 21){
		std::cout << "BlackJack!" << std::endl;
		return true;
	}
	if( dealer.count == 21 && player.count != 21){
		std::cout << "Dealer BlackJack" << std::endl;
		return true;
	}
	if( dealer.count == 21 && player.count == 21){
		std::cout << "BlackJack Push" << std::endl;
		return true;	
	}
	return false;	
}

bool Game::isDealerBlackJack(){
	if (!(dealer_up_card == 14 || isTenValue(dealer_up_card))) return false;
	int hole = deck.peek();
	if(dealer_up_card == 14) return isTenValue(hole);
	return hole == 14;
}

void Game::deal(){
	hole_dealt = false;
	int card = deck.newCard();
	player.addCard(card);

	dealer_up_card = deck.newCard();
	dealer.addCard(dealer_up_card);

	int card2 = deck.newCard();
	player.addCard(card2);	
	bool dealer_bj = false;	
	if(isDealerBlackJack()){
		dealer_hole_card = deck.newCard();
		dealer.addCard(dealer_hole_card);
		hole_dealt = true;
		dealer_bj = true;
	}
	std::cout << "Dealer: " << deck.cardtoString(dealer_up_card) << " [hidden]" << std::endl;	
	std::cout << "Player: " << deck.cardtoString(card) << " " << deck.cardtoString(card2) << std::endl;
	if (dealer_bj){
		std::cout << "Hidden Card was " << deck.cardtoString(dealer_hole_card) << std::endl;
	}
}


void Game::playersTurn(){
	std::string x;	
	std::cout << "1: Hit ,,, 2: Stand :: ";
	std::cin >> x;
	while( x == "1"){
		if ( deck.deckEmpty())	{
			std::cout << "Deck is out " << std::endl;
			return;
		}
		int card = deck.newCard();
		player.addCard(card);
		std::cout << deck.cardtoString(card) << std::endl;
		if ( player.count > 21 ){
			std::cout << "player busted with " << player.count << std::endl;
			break;
		}
		
		std::cout << "1: Hit ,,, 2: Stand :: ";
		std::cin >> x;
		std::cout << std::endl;
	}
			
} 

void Game::dealersTurn(){
	if (!hole_dealt){
		dealer_hole_card = deck.newCard();
		dealer.addCard(dealer_hole_card);
		hole_dealt = true;
		std::cout << "Hidden card was " << deck.cardtoString(dealer_hole_card) << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	} else {
		std::cout << "Hidden card was " << deck.cardtoString(dealer_hole_card) << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	
	while(dealer.count < 17){
		if ( deck.deckEmpty())	{
			std::cout << "Deck is out " << std::endl;
			return;
		}
		int card = deck.newCard();
		dealer.addCard(card);
		std::cout << deck.cardtoString(card) << " " << std::flush;
		if ( dealer.count > 21 ){
			std::cout << std::endl;
			std::cout << "dealer busts with " << dealer.count << std::endl;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));

	}
	std::cout << std::endl;

}

void Game::scoreCheck(){
	std::this_thread::sleep_for(std::chrono::seconds(1));

	if(player.count > dealer.count && player.count < 22) std::cout << "You win with a " << player.count << std::endl;
	if(player.count < dealer.count && dealer.count < 22) std::cout << "Dealer wins with a " << dealer.count << std::endl;
	if(player.count == dealer.count) std::cout << "Push" << std::endl;
}

