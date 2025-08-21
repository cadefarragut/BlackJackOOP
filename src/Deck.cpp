#include "Deck.h"
#include <string>
#include <stdexcept>

int Deck::deckEmpty(){
	if (cards.empty()){
		return true;
	}
	return false;
}

int Deck::newCard(){
	
	if(deckEmpty()){
		throw std::runtime_error("Deck empty");
	}
	int card = cards.back();	
	cards.pop_back();
	return card;	
} 

std::string Deck::cardtoString(int card){
	if ( card > 0 && card < 11){
		return std::to_string(card);
	}
	if ( card == 11 ) return "J";
	if ( card == 12 ) return "Q";
	if ( card == 13 ) return "K";
	if ( card == 14 ) return "A";
	return "?";	
}

int Deck::peek(){
	return cards.back();
}

