#ifndef BJ_HANDS_H
#define BJ_HANDS_H

class Hand {
	public:
		int count = 0;
		int softAce = 0;
		void addCard(int card);
};

#endif
