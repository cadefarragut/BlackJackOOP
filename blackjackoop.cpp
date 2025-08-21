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
		     14, 14, 14, 14
	};

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
				count -= 10;
				softAce--;
			}
		}
};


class Deck{
	public:
		int deckEmpty(){
			if (cards.empty()){
				return true;
			}
			return false;
		}

		int newCard(){
			
			if(deckEmpty()){
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
			player.count = 0;
			dealer.count = 0;
			cout << "Welcome to BlackJack" << endl;	
		}

		bool isBlackJack(){
			if (player.count == 21){
				cout << "BlackJack!" << endl;
				return true;
			}	
			return false;
		}

		bool isDealerBlackJack(){
			if(cards.back()){
				int card = deck.newCard();				
				// This is wrong. Is adding up vector value and not Card Value	
				cout << deck.cardtoString(card) << endl;	
				cout << "Dealer BlackJack" << endl;
				return true;		
			}
			return false;		
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


		void playersTurn(){
			string x;	
			cout << "1: Hit ,,, 2: Stand :: ";
			cin >> x;
			while( x == "1"){
				int card = deck.newCard();
				player.addCard(card);
				cout << deck.cardtoString(card) << endl;
				if ( player.count > 21 ){
					cout << "player busted with " << player.count << endl;
					break;
				}
				cin >> x;
				cout << endl;
			}
				
		} 

		void dealersTurn(){
			while(dealer.count < 17){
				int card = deck.newCard();
				dealer.addCard(card);
				cout << deck.cardtoString(card) << endl;
				
				if ( dealer.count > 21 ){
					cout << "dealer busts with " << dealer.count << endl;
					break;
				}
			}

		}

		void scoreCheck(){
			if(player.count > dealer.count && player.count < 22) cout << "You win" << endl;
			if(player.count < dealer.count && dealer.count < 22) cout << "Dealer wins" << endl;
			if(player.count == dealer.count) cout << "Push" << endl;
	}

};

//TODO
// Fix isDealerBlackJack()
// Clean up Code, maybe optimize more
int main(){
	Game blackjack;
	mt19937 rng(time(nullptr));
	shuffle(cards.begin(), cards.end(), rng);
	while(!blackjack.deck.deckEmpty()){
		blackjack.start();
		blackjack.deal();
		if (blackjack.isBlackJack()) continue;
		if (blackjack.isDealerBlackJack()) continue;
		blackjack.playersTurn();
		if ( blackjack.player.count < 22){
			blackjack.dealersTurn();	
		}	
		blackjack.scoreCheck();	
	}
	cout << "Deck is out. Thanks for playing!" << endl;
	return 0;
}
