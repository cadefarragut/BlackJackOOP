#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <stdexcept>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono_literals;
using std::this_thread::sleep_for;

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
				throw runtime_error("Deck empty");
			}
			int card = cards.back();	
			cards.pop_back();
			return card;	
		} 

		string cardtoString(int card){
			if ( card > 0 && card < 11){
				return to_string(card);
			}
			if ( card == 11 ) return "J";
			if ( card == 12 ) return "Q";
			if ( card == 13 ) return "K";
			if ( card == 14 ) return "A";
			return "?";	
		}
		
		int peek(){
			return cards.back();
		}
};

class Game{
	public:
		Deck deck;
		Hand player, dealer;
		int dealer_up_card = -1;	
		int dealer_hole_card = -1;
		bool hole_dealt = false;
		
		static bool isTenValue(int r) {return r >= 10 && r <= 13; }


		void start(){
			player = Hand{};
			dealer = Hand{};
			cout << "Welcome to BlackJack" << endl;	
		}

		bool isBlackJack(){
			if (player.count == 21 && dealer.count != 21){
				cout << "BlackJack!" << endl;
				return true;
			}
			if( dealer.count == 21 && player.count != 21){
				cout << "Dealer BlackJack" << endl;
				return true;
			}
			if( dealer.count == 21 && player.count == 21){
				cout << "BlackJack Push" << endl;
				return true;	
			}
			return false;	
		}
		
		bool isDealerBlackJack(){
			if (!(dealer_up_card == 14 || isTenValue(dealer_up_card))) return false;
			int hole = deck.peek();
			if(dealer_up_card == 14) return isTenValue(hole);
			return hole == 14;
		}

		void deal(){
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
				cout << "Dealer: " << deck.cardtoString(dealer_up_card) << " [hidden]" << endl;	
				cout << "Player: " << deck.cardtoString(card) << " " << deck.cardtoString(card2) << endl;
				if (dealer_bj){
					cout << "Hidden Card was " << deck.cardtoString(dealer_hole_card) << endl;
				}
		}


		void playersTurn(){
			string x;	
			cout << "1: Hit ,,, 2: Stand :: ";
			cin >> x;
			while( x == "1"){
				if ( deck.deckEmpty())	{
					cout << "Deck is out " << endl;
					return;
				}
				int card = deck.newCard();
				player.addCard(card);
				cout << deck.cardtoString(card) << endl;
				if ( player.count > 21 ){
					cout << "player busted with " << player.count << endl;
					break;
				}
				
				cout << "1: Hit ,,, 2: Stand :: ";
				cin >> x;
				cout << endl;
			}
					
		} 

		void dealersTurn(){
			if (!hole_dealt){
				dealer_hole_card = deck.newCard();
				dealer.addCard(dealer_hole_card);
				hole_dealt = true;
				cout << "Hidden card was " << deck.cardtoString(dealer_hole_card) << endl;
				sleep_for(1s);
			} else {
				cout << "Hidden card was " << deck.cardtoString(dealer_hole_card) << endl;
				sleep_for(1s);
			}
			
			while(dealer.count < 17){
				if ( deck.deckEmpty())	{
					cout << "Deck is out " << endl;
					return;
				}
				int card = deck.newCard();
				dealer.addCard(card);
				cout << deck.cardtoString(card) << " " << flush;
				if ( dealer.count > 21 ){
					cout << endl;
					cout << "dealer busts with " << dealer.count << endl;
					break;
				}
				sleep_for(1s);
			}
			cout << endl;

		}

		void scoreCheck(){
			sleep_for(1s);
			if(player.count > dealer.count && player.count < 22) cout << "You win with a " << player.count << endl;
			if(player.count < dealer.count && dealer.count < 22) cout << "Dealer wins with a " << dealer.count << endl;
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
	while(cards.size() >= 4){
		blackjack.start();
		blackjack.deal();
		if (blackjack.isBlackJack()) {
			cout << endl;
			continue;
		}
		blackjack.playersTurn();
		if ( blackjack.player.count < 22){
			blackjack.dealersTurn();	
		}	
		blackjack.scoreCheck();
		cout << endl;
	}
	cout << "Deck is out. Thanks for playing!" << endl;
	return 0;
}
