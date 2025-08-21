#include "Hand.h"

void Hand::addCard(int card){
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
