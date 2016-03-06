//Alan Himes
//ahimes1@cnm.edu
//Hand.cpp

#include "stdafx.h"
#include "Hand.h"
#include "Card.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Hand::Hand() {
    numCards = 0;
    showHand = "";
    total = 0;
    
    int i;
    
    //initialize object array?
}

void Hand::AddCard(Card c) {
    cards[numCards] = c;
    ++numCards;
    
    total = 0;
    int i;
    for (i=0; i<numCards; ++i)
        total += cards[i].GetIValue();
        
}

string Hand::Show(bool isdealer, bool hideFirstCard) {
    stringstream ssHand;
    
    if (isdealer)
        ssHand << "Dealer:" << endl;
    else
        ssHand << "Player:" << endl;
        
    int i;
    
    for (i=0; i<numCards; ++i){
        if (hideFirstCard && i == 0)
            ssHand << "HIDDEN CARD" << endl;
        else
            ssHand << cards[i].GetValue() << " of " << cards[i].GetSuit() << endl;
    }
    
    showHand = ssHand.str();
    return showHand;
}

bool Hand::BlackJack() {
    int i;
    bool blackJack = false;
    
    if (numCards >= 2) {
        if (BestScore() == 21)
            blackJack = true;
        else if (cards[0].GetIValue() == 1 && cards[1].GetIValue() == 10)
            blackJack = true;
        else if (cards[0].GetIValue() == 10 && cards[1].GetIValue() == 1)
            blackJack = true;
        else
            blackJack = false;
    }
    
    return blackJack;
}

bool Hand::Under(int n) {
    if (total < n)
        return true;
    else
        return false;
}

int Hand::BestScore() {
    bool haveAce = false;

    int i;
    for (i=0; i<numCards; ++i) {
        if (cards[i].GetValue() == "Ace"){
            haveAce = true;
        }
    }
    
    //If the total amount of points is less than 12 and there's an ace in the hand
    if (Under(12) && haveAce) {
        
        total += 10; //if changing an ace from 1 to an 11, the difference is 10.
        return total;
    }
    
    if (!Under(12) && haveAce)
        return total;//the Ace should stay a 1.
    
    if (!haveAce)
        return total;
}

bool Hand::MustHit() {
    if (BestScore() < 17)
        return true;
    else
        return false;
}

bool Hand::Busted() {
    if (BestScore() > 21)
        return true;
    else
        return false;
}

void Hand::ClearHand() {
    showHand = "";
    numCards = 0;
}

void Hand::ResetTotal() {
    total = 0;
}