//Alan Himes, ahimes1@cnm.edu, Roulettewheel.cpp, RouletteFunctions.cpp, RouletteFunctions.h


#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include "RouletteFunctions.h"

using namespace std;

int main () {
    float bet, winnings, balance, totalWinnings, betTotal;
	betTotal = 0;
	totalWinnings = 0; //Needed to initialize to avoid garbage number being added to totals.
    int seed, numBet, spin, i;
    bool playAgain;
    bool logWritten;
    string logText, forFileName, numBets, spins;
    vector<int> AllNumberBets;
    vector<int> AllSpins;
    stringstream ssAllNumberBets;
    stringstream ssAllSpins;
    //Vectors and strings used to create totals in main for the string in "WriteLog()"
    
    header();
    ShowInstructions();
    balance = 100; //Player starts with $100.00.
    
    do {
        ShowTheMoney(bet, balance, seed);
    
        numBet = MakeABet();
        AllNumberBets.push_back(numBet); //vector containing all bet numbers
        
        spin = spinWheel(seed);
        AllSpins.push_back(spin); //vector containing all winning numbers


        winnings = FigureWinnings(bet, spin, numBet);


        if (winnings >= 36) //because any winning amount has a minimum possible amount of $36
            cout << "\nCongratulations! You won $" << winnings << "!" << endl;
        
        logText = CreateLogText(bet, spin, numBet, balance, winnings, totalWinnings, betTotal, forFileName);
        
        playAgain = anotherGame(logWritten, balance);
        
        if (playAgain == false) {
            ssAllNumberBets << AllNumberBets.at(0);
            for (i=1; i<AllNumberBets.size(); i++) {
                ssAllNumberBets << ", " << AllNumberBets.at(i);
            }
            numBets = ssAllNumberBets.str();
            
            ssAllSpins << AllSpins.at(0);
            for (i=1; i<AllSpins.size(); i++) {
                ssAllSpins << ", " << AllSpins.at(i);
            }
            spins = ssAllSpins.str();
            
            logWritten = WriteLog(logText, &forFileName, &playAgain, betTotal, numBets, spins, totalWinnings, balance);
        }
        
        if (logWritten == false) {
            cout << "Unable to write log! Aborting program!!" << endl;
            exit(1);
        }
    } while (playAgain == true);
    cout << "\nBye!" << endl;
    return 0;
}