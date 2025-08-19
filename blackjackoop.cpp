#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector<int> cards = {1, 1, 1, 1,
		     2, 2, 2, 2,
		     3, 3, 3, 3,
	             4, 4, 4, 4,
		     5, 5, 5, 5,
		     6, 6, 6, 6,
		     7, 7, 7, 7,
		     8, 8, 8, 8,
		     9, 9, 9, 9,
		     10, 10, 10, 10,
		     11, 11, 11, 11,
		     12, 12, 12, 12,
		     13, 13, 13, 13,
		     14, 14, 14, 14};

class Player {
	public: 
		int count;
		
		void adjustPlayerCount(int card){
			if(card > 0 && card < 11){
				count+=card;
			}
			if ( card == 11 || card == 12 || card == 13 ){
				card += 10;		
			}
			if ( card == 14 ){

			}
	}
};

class Dealer {
	public:
		int count;

		void adjustDealerCount(int card){
			if(card > 0 && card < 11){
				count+=card;
			}
			if ( card == 11 || card == 12 || card == 13 ){
				card += 10;		
			}
			if ( card == 14 ){

		}
	}
};

class Deck{
	public:
		Player player;	
		Dealer dealer;		
		int deckEmpty(){
			cout << "Out of Cards. Thanks for Playinig" << endl;
			return 0;
		}

		int newCard(){
			mt19937 rng(time(nullptr));
			shuffle(cards.begin(), cards.end(), rng);
			int card = cards.back();
			if(card){
				cards.pop_back();
				return card;
			}
			deckEmpty();
			return 0;	
		} 

		string cardtoString(int card){
			if ( card > 0 && card < 11){
				return to_string(card);
			}
			else if ( card == 11 ){
				return "J";
			}
			else if ( card == 12 ){
				return "Q";
			}
			else if ( card == 13 ){
				return "K";
			}
			else return "A";
		}
		void deal(){
			// Player receives 2 cards
			// Dealer receives 1 card afterwards
				

			int card = newCard();
			player.adjustPlayerCount(card);
			cout << "Dealer: " << cardtoString(card) << endl;	
			int card2 = newCard();
			player.adjustPlayerCount(card2);	
			int card3 = newCard();
			dealer.adjustDealerCount(card3);
			cout << "Player: " << cardtoString(card2) << " " << cardtoString(card3) << endl;
	}
};

class Game{
	public:
		Deck deck;

		void start(){
			cout << "Welcome to BlackJack" << endl;	
			deck.deal();
		}
		// TODO
		// End Game if Dealer has BlackJack off rip
		// Players Turn
		// Dealers Turn
		// Ace Config
		void playersTurn(){

		}



};



int main(){
	Game blackjack;
	blackjack.start();
	blackjack.playersTurn();
	
	return 0;
}
