#ifndef _BINGO_H
#define _BINGO_H

#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;

class Bingo {
    private:
        
        int i, j, value, numValue;
        string gameType;
        string matchOrBlank;
        /*matchOrBlank will be positioned as a "space" under the cards.
        It reports if there's a match.*/
        string lettersNumsCalled;
        /*A stringstream of all the numbers called so far will be created 
        in SetCalledNumber and assigned to this string. callReview() displays
        this string at the beginning of each turn.*/
        
        void FillCard();
        void MarkCard();
        bool CheckForXBingo();
        bool CheckForSQBingo();
        
    public:
        int numValueCounter;
        /*numValueCounter will be incremented throughout the program and
        reset with each new game. It will be used to show which turn it is,
        and to determine the amount of elements of a couple of arrays.*/
        char Top[6];
        /*Top[] will contain letters of the word "Bingo". It will be used to
        display the letters at the top of the board, and also be referred to 
        when determining which letter goes with which number. */
        string bingoCard[5][5];//empty card.
        string markedCard[5][5];
        
        Bingo();
        string DisplayCard(string bingoCard[][5]);
        string callReview(){return lettersNumsCalled;}
        void SetBingoPattern(string gameType) {this->gameType = gameType;}
        bool SetCalledNumber(int &numValue, char &letterValue);
        string DisplayCard(string bingoCard[][5], string markedCard[][5], int &counter);
        void Win();
        
};

#endif