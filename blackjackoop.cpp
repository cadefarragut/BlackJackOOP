#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector<int> cards = {
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

class Hand {
	public:
		void addCard(int card){

		}

};
class Deck{
	public:
		int deckEmpty(){
			cout << "Out of Cards. Thanks for Playinig" << endl;
			return 0;
		}

		int newCard(){
			
			if(cards.empty()){
				deckEmpty();
				return 0;	
			}
			int card = cards.back();	
			cards.pop_back();
			return card;	
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
};

class Game{
	public:
		Deck deck;
		Hand player;
		Hand dealer;

		void start(){
			cout << "Welcome to BlackJack" << endl;	
			deal();
		}

		void deal(){
			// Player receives 2 cards
			// Dealer receives 1 card afterwards
				

			int card = deck.newCard();
			player.addCard(card);
			cout << "Dealer: " << deck.cardtoString(card) << endl;	
			int card2 = deck.newCard();
			player.addCard(card2);	
			int card3 = deck.newCard();
			dealer.addCard(card3);
			cout << "Player: " << deck.cardtoString(card2) << " " << deck.cardtoString(card3) << endl;
	}
	// TODO End Game if Dealer has BlackJack off rip Players Turn
		// Dealers Turn Ace Config
		void playersTurn(){

		}



};



int main(){
	Game blackjack;	
	mt19937 rng(time(nullptr));
	shuffle(cards.begin(), cards.end(), rng);
	blackjack.start();
	blackjack.playersTurn();
	
	return 0;
}
