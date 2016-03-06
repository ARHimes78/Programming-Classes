//Alan Himes
//ahimes1@cnm.edu
//Card.cpp

#include "stdafx.h"
#include "Card.h"

#include <string>
using namespace std;

Card::Card() {
	iValue = 1;
	value = "Ace";
	suit = "spades";
}

Card::Card(int n) {
	int iSuit = n/13;
	iValue = n%13 + 1;

	switch(iSuit) {
		case 0:
			suit = "spades";
			break;
		case 1:
			suit = "hearts";
			break;
		case 2:
			suit = "clubs";
			break;
		case 3:
			suit = "diamonds";
			break;
	}

	if (iValue == 1)
		value = "Ace";
	else if (iValue == 11)
		value = "Jack";
	else if (iValue == 12)
		value = "Queen";
	else if (iValue == 13)
		value = "King";
	else
		value = to_string(iValue);

	if (iValue > 10)
		iValue = 10;

}

void Card::SetIValue(int val) {
	iValue = val;
}