// Alan Himes, Austin Teichelman
// arhimes1@cnm.edu, ateichelman@cnm.edu

#ifndef _GAME_H
#define _GAME_H

#include <string>
#include "Deck.h"
#include "Hand.h"
#include "Logger.h"

using namespace std;

class Game
{

private:
	
	double bet;
	double money;
	int wins, losses, ties, numberOfBets;
	Deck deck;
	Hand playersHand;
	Hand dealersHand;
	Logger log;
        bool stay;
	bool dealerHit;
	bool inProgress;

public:
	
	Game();
	bool SetBet(double b);
	void InitialDeal();
	string ShowPlayerHand() {return playersHand.Show(false, false);}
	string ShowDealersHand(bool hide) {return dealersHand.Show(true, hide);}
	bool IsBlackJack() {return playersHand.BlackJack(); }
	bool PlayerBusted() {return playersHand.Busted();}
	bool PlayerContinues();
	void PlayerHits();
	string PlayerWins();
	bool DealerContinues();
	string DealerWins();
	string Tie();
	string NoResults() {return ""; }
	string ShowResults();
	void ClearHands();
	bool IsLogOpened(){ return log.IsLogOpen();}
	void EndGame();
	
    int GetPlayerScore() {return playersHand.BestScore();}
    int GetDealerScore() {return dealersHand.BestScore();}
        
    void SetStay(bool stay) {this->stay = stay; }
    bool GetStay() {return stay; }
    double GetMoney() {return money; }
    bool GetDealerHit() {return dealerHit; }

	void SetInProgress(bool progress) {inProgress = progress; }
	bool IsInProgress() {return inProgress; }
};

#endif