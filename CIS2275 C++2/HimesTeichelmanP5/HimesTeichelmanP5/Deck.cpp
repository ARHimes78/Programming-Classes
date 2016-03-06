// Austin Teichelman
// ateichelman@cnm.edu
// Deck.cpp

#include "stdafx.h"
#include "Deck.h"

Deck::Deck()
{

	// fills cards aray with 0-51
	for (int i = 0; i < 52; i++)
	{
		cards[i] = i;
	}

	topCard = 0;

	//Added these two lines for true random shuffling. -Alan
	random_device rnd;
	engine.seed(rnd());

	Shuffle();

}

void Deck::Shuffle()
{

	bool sameCard = false;

	int rCard1, rCard2;

	int rCard1At, rCard2At;

	for (int x = 0; x < 52; x++)
	{
		// do loop repeats so long as rCard1 has the same value as rCard2
		do{
			
			rCard1 = Deck::RandomCard();
			rCard2 = Deck::RandomCard();

			if (rCard1 == rCard2) sameCard = true;
			else sameCard = false;

		}while(sameCard);

		// for-loops look through cards array for a matching value, and assign
		// the index of that value to the rCardAt variables.
		for (int i = 0; i < 52; i++)
		{
			if (cards[i] == rCard1)
			{
				rCard1At = i;
				break;
			}
		}

		for (int b = 0; b < 52; b++)
		{
			if (cards[b] == rCard2)
			{
				rCard2At = b;
				break;
			}
		}

		//replaces card2 with card1, and vice-versa
		cards[rCard2At] = rCard1;
		cards[rCard1At] = rCard2;

	}

}

int Deck::RandomCard()
{

	uniform_int_distribution<int> stanDeck (0,51);
	
	return stanDeck(engine);

}

void Deck::Deal(Card &c)
{
	Card topDeck = Card(cards[topCard]);

	c = topDeck;

	topCard++;

	if (topCard > 34)
	{
		Shuffle();
		topCard = 0;
	}

}