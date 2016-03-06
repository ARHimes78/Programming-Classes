// Austin Teichelman
// ateichelman@cnm.edu
// Deck.h

#ifndef _DECK_H
#define _DECK_H

#include <array>
#include <random>
#include "card.h"

using namespace std;

class Deck
{

private:
	array<int,52> cards;
	int topCard;
	default_random_engine engine;

public:
	Deck();
	void Shuffle();
	int RandomCard();
	void Deal(Card &c);

};

#endif