//Alan Himes
//ahimes1@cnm.edu
//Hand.h

#ifndef _HAND_H
#define _HAND_H

#include <iostream>
#include <string>
#include <array>
#include "Card.h"

#define MAX_CARDS 21

using namespace std;

class Hand {
    private:
        int numCards;
        string showHand;
        array<Card, MAX_CARDS> cards;
        int total;//added to share between Under() and BestScore()
    public:
        Hand();
        void AddCard(Card c);
        string Show(bool isdealer, bool hideFirstCard);
        bool BlackJack();
        bool Under(int n);
        int BestScore();
        bool MustHit();
        bool Busted();
        void ClearHand();
        void ResetTotal();
};

#endif