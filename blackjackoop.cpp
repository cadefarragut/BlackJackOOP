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
		
		void adjustCount(){

	}
};

class Dealer {
	public:
		int count;

};

class Deck{
	public:
	
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
		} 


		void deal(){

		}
};

class Game{
	private:
		Player player;
		Dealer dealer;
		Deck deck;

	public:
	
		void start(){
			cout << "Welcome to BlackJack" << endl;	
			deck.deal();
		}

};



int main(){
	Game blackjack;
	blackjack.start();
	return 0;
}
