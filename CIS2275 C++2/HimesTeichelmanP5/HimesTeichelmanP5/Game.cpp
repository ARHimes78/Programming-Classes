#include "stdafx.h"//
#include "game.h"

#include <string>
#include <sstream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Logger.h"

using namespace std;

Game::Game() {
	bet = 0.0;
	money = 1000.0;
	wins = 0; 
	losses = 0; 
	ties = 0; 
	numberOfBets = 0;

	log.StartLog(money);
}

bool Game::SetBet(double b) {
    stringstream ssBet;

    if (b < 0 || b > money)
        return false;
    else {
        bet = b;
        ++numberOfBets;
        ssBet << "The bet is $" << bet << ".";
        log.WriteLog(ssBet.str());
        return true;
    }
}

void Game::InitialDeal() {
	for (int i = 0; i < 2; ++i)
	{

		Card card1, card2;
		deck.Deal(card1);
		playersHand.AddCard(card1);
		deck.Deal(card2);
		dealersHand.AddCard(card2);

	}
}

//move the IsBlackJack() and PlayerBusted() to game.h because they're one line

bool Game::PlayerContinues() {
	if (PlayerBusted())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Game::PlayerHits() 
{
	Card dCard;
	deck.Deal(dCard);
	playersHand.AddCard(dCard);
}

string Game::PlayerWins() {
	SetInProgress(false);
	stringstream temp;
	double bBet = bet * 1.5;

	++wins;//Added -Alan

	if (IsBlackJack())
	{
		money += bBet;


		temp << "Player wins: \r\nBet: " << bet << " Blackjack bonus: "
			<< bBet << "\r\nCurrent Money: " << money;

		//return temp.str();
	}
	else
	{
		money += bet;

		temp << "Player wins: \r\nBet: " << bet << "\r\nCurrent Money: " << money;

		//return temp.str();

	}

	log.WriteLog(temp.str());//Added - Alan

	return temp.str();//moved this here because it'll happen in either case -Alan
}

bool Game::DealerContinues() {
	if (dealersHand.MustHit())
	{
		Card dCard;
		deck.Deal(dCard);

		dealersHand.AddCard(dCard);
		dealerHit = true;//Added - Alan
		return true;
	}
	else
	{
		dealerHit = false;//Added - Alan
		return false;
	}
}

string Game::DealerWins() {
	SetInProgress(false);
	stringstream temp;

	++losses;//Added - Alan
    money -= bet;//Added - Alan

	temp << "Player loses: \r\nBet: " << bet << "\r\nCurrent Money: " << money;

	log.WriteLog(temp.str());//Added - Alan

	return temp.str();
}

string Game::Tie() {
	SetInProgress(false);
	++ties;

	stringstream ssTie;
	ssTie << "Tie: " << "Player has $" << money;

	log.WriteLog(ssTie.str());//Added -Alan
	return ssTie.str();
}

string Game::ShowResults() {
    stringstream ssResults;
    if (IsBlackJack())
        return PlayerWins();
    if (PlayerBusted() && dealersHand.Busted()) {
        ssResults << "PLAYER AND DEALER BUSTED" << endl;
        ssResults << Tie();
        return ssResults.str();
    }
    else if (PlayerBusted()) {
        ssResults << "PLAYER BUSTED" << endl;
        ssResults << DealerWins();
        return ssResults.str();
    }
    else if (dealersHand.Busted()) {
        ssResults << "DEALER BUSTED" << endl;
        ssResults << PlayerWins();
        return ssResults.str();
    }
    else if (playersHand.BestScore() > dealersHand.BestScore()) {
        if (GetStay()) {
            ssResults << "Player's score is better than dealer's score!" << endl;
            ssResults << PlayerWins();
            return ssResults.str();
        }
        else
        return NoResults();
    }
    else if (dealersHand.BestScore() > playersHand.BestScore()) {
        if (GetStay()) {
            ssResults << "Dealers's score is better than player's score!" << endl;
            ssResults << DealerWins();
            return ssResults.str();
        }
        else
        return NoResults();
    }
    else if (dealersHand.BestScore() == dealersHand.BestScore()) {
        if (GetStay()) {
            ssResults << "Player's score = Dealer's score!" << endl;
            ssResults << PlayerWins();
			return ssResults.str();
        }
        else
        return NoResults();
    }
    else
        return NoResults();
}

void Game::ClearHands() {
	playersHand.ClearHand();
	dealersHand.ClearHand();
	playersHand.ResetTotal();
    dealersHand.ResetTotal();
}

void Game::EndGame() {
	stringstream temp;

	temp << "Player ended the game with $" << money << " in winnings." << endl;
	temp << "After " << numberOfBets << " bets, there were" << endl;
    temp << wins << " wins" << endl;
    temp << losses << " losses" << endl;
    temp << ties << " ties" << endl;
    temp << "Final balance - $" << money;

	string endArg = temp.str();

	log.CloseLog(endArg);
}