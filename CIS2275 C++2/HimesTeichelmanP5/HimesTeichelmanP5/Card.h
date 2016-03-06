//Alan Himes
//ahimes1@cnm.edu
//Card.h

#ifndef _CARD_H
#define _CARD_H

#include <string>

using namespace std;

class Card {
	private:
		int iValue;
		string value;
		string suit;
	public:
		Card();
		Card(int n);
		void SetIValue(int val);
		string GetValue(){ return value;}
		int GetIValue(){return iValue;}
		string GetSuit(){return suit;}
};
//test
#endif