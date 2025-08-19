#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
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
		int count = 0;
		int softAce = 0;
		void addCard(int card){
			if ( card < 11 ) count += card;
			if ( card > 10 && card < 14 ) count += 10;
			if ( card == 14 ) {
				count += 11; 		
				softAce++;
			}
			while ( count > 21 && softAce > 0 ){
				count -= 11;
				softAce--;
			}
			if ( count > 21 && softAce == 0) cout << "Busted" << endl;	
		}

};


class Deck{
	public:
		int deckEmpty(){
			cout << "Out of Cards. Thanks for Playing" << endl;
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
			int card2 = deck.newCard();
			player.addCard(card2);	
			int card3 = deck.newCard();
			dealer.addCard(card3);
			cout << "Dealer: " << deck.cardtoString(card3) << endl;	
			cout << "Player: " << deck.cardtoString(card) << " " << deck.cardtoString(card2) << endl;
	}
		// TODO 
	// 	End Game if Dealer has BlackJack off rip 
	// 	Players Turn
		// Counting System with Aces
		void playersTurn(){
			string x;	
			cout << "1: Hit ,,, 2: Stand :: ";
			cin >> x;
			while( x == "1"){
				int card = deck.newCard();
				player.addCard(card);
				cout << deck.cardtoString(card);
				if ( player.count > 21 ){
					cout << "busted with " << player.count << endl;
					break;
				}
				cin >> x;
				cout << endl;
			}
				
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
