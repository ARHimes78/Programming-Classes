#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cctype>
#include "RouletteFunctions.h"

using namespace std;

void header() {
    cout << "Name: Alan Himes" << endl;
    cout << "Title: Roulette Wheel" << endl;
    cout << "Objective: Create a roulette wheel" << endl;
}


void ShowInstructions() {
    cout << "\n";
    cout << "Instructions:" << endl;
    cout << "Place a bet, then pick a number between 0-36." << endl;
    cout << "If the correct number was chosen, 36 x the bet amount is awarded." << endl;
}


void ShowTheMoney(float &bet, float &balance, int &seed) {
    /*This function asks for the seed and how much $ to bet. Since they are
    two values, the results are passed by reference instead of returned.*/
    
    int choice;
    bool seedChoice = true;
    bool makeBet = true;
    
    cout << "\nPlease choose one of the following:" << endl;
    cout << "1: Enter a seed manually" << endl;
    cout << "2: Generate random seed" << endl;
    /*I liked the idea of including a random seed option because entering the
    same seed causes the same spin results.*/
    
    cin >> choice;
    clear();
    while (seedChoice == true) {
        switch(choice) {
            case 1:
                cout << "Enter a seed value: ";
                cin >> seed;
                clear();
                srand(seed);
                seedChoice = false;
                break;
            case 2:
                cout << "Random seed generated." << endl;
                srand(time(NULL));
                seed = rand();
                seedChoice = false;
                break;
            default:
                cout << "Invalid entry. Please choose 1 or 2." << endl;
                cin >> choice;
                clear();
        }
    }
    
    while (makeBet == true) {
        cout.setf(ios::fixed);
            cout.precision(2);
        cout << "\nYour balance is $" << balance << ". How much would you like to bet?" << endl;
        cin >> bet;
        clear();
        if (bet > balance)
            cout << "You cannot bet beyond $" << balance << "!" << endl;
        else {
            balance = balance - bet;
            makeBet = false;
        }
    }
}


int MakeABet() {
    int numBet;
    bool pick;
    do {
        cout << "Pick a number between 0 and 36." << endl;
        cin >> numBet;
        clear();
        if (numBet > 36 || numBet < 0) {
            cout << "Invalid entry, please try again." << endl;
            pick = true;
        }
        else
            pick = false;
    } while (pick == true);
    return numBet;
}


int spinWheel(int &seed) {
    srand(seed);
    int spin = rand() % 37;
    return spin;
}


float FigureWinnings(float &bet, int &spin, int &numBet) {
	float zero = 0;
    if (spin == numBet)
        return bet * 36;
    else
        return zero;
}


string CreateLogText(float &bet, int &spin, int &numBet, float &balance, float &winnings, float &totalWinnings, float &betTotal, string &forFileName) {
    
    char timeNow[20];
    char dateNow[20];
    
    errno_t err;
    
    err = _strtime_s(timeNow, 20);
    err = _strdate_s(dateNow, 20);

    static string logText = "Log of Roulette Play\n\n";
    static int gameNumber = 0;
    stringstream ssLog;
    stringstream ssFN; //The date/time for the file name will be created with this

    
    ssFN << "Log_" << dateNow[0] << dateNow[1] << "_" << dateNow[3] << dateNow[4] << "_" << dateNow[6] << dateNow[7] << "_"; //creating the log filename with date and time included
    ssFN << timeNow[0] << timeNow[1] << "_" << timeNow[3] << timeNow[4];
    ssFN << ".txt";
    forFileName = ssFN.str();
    
    
    balance = balance + winnings;
    totalWinnings = totalWinnings + winnings;
    betTotal = betTotal + bet;
    
	cout << "totalWinnings = " << totalWinnings;

    //These couts are a result of the most recent bet, now that the resulting balance has been calculated. 
    cout << "\nAmount bet: $" << bet << endl;
    cout.precision(0);
    cout << "Number bet on: " << numBet << endl;
    cout << "Winning number: " << spin << endl;
    cout.precision(2);
    cout << "Balance: $" << balance << endl;
    
    ssLog << logText; //This line makes it possible to include the previous bet results with the stringstream
    ssLog << timeNow << endl;
    ssLog << dateNow << endl;
    gameNumber++;
    ssLog << "Game # " << gameNumber << endl;
    ssLog.setf(ios::fixed);
    ssLog.precision(2);
    ssLog << "Bet: $" << bet << endl;
    ssLog.precision(0);
    ssLog << "Number bet on: " << numBet << endl;
    ssLog << "Winning number: " << spin << endl;
    ssLog.precision(2);
    ssLog << "Winnings: $" << winnings << endl;
    ssLog << "Total Winnings: $" << totalWinnings << endl;
    ssLog << "Balance: $" << balance << endl;
    if (numBet == spin)
        ssLog << "***WIN!***" << endl;
    ssLog << "\n";
    if (balance < .01)
        ssLog << "Ran out of money!";
    logText = ssLog.str();
    
    return logText;
}


bool WriteLog(string &logText, string *forFileName, bool *playAgain, float &betTotal, string &numBets, string &spins, float &totalWinnings, float &balance) {
    /*The instrutions said to pass the pointer for playAgain, but it was used
    to determine whether or not to run WriteLog(). Now that it was already decided
    that playAgain is false, and WriteLog is running, I don't know what to do
    with *playAgain. */
    
    string history;
    stringstream ssHist;
    
    ssHist << "\n***GAME HISTORY***" << endl;
    ssHist.setf(ios::fixed);
    ssHist.precision(2);
    ssHist << "\nTotal amount bet: $" << betTotal << endl;
    ssHist << "Numbers bet on: " << numBets << endl;
    ssHist << "Winning numbers: " << spins << endl;
    ssHist << "Total Winnings: $" << totalWinnings << endl;
    ssHist << "Balance: $" << balance << endl;
    ssHist << "\n";
    
    history = ssHist.str();
    cout << history;
    
    ofstream logToFile;
    logToFile.open(*forFileName);
    if (!logToFile)
        return false;
    
    logToFile << logText;
    logToFile.close();
    
    cout << "Log \"" << *forFileName << "\" written successfully!" << endl;
    
    return true;
}


bool anotherGame(bool &logWritten, float &balance) {
    string answer;
    bool again;
    int i;

    if (balance < .01) { //Having less than one cent = broke.
        cout << "\nYou're broke, chief!" << endl;
        return false;
    }
    

    do {
        cout << "\nWould you like to play again? (yes/no): ";
        getline(cin, answer);
		for(i=0;i<answer.length();i++)
			answer[i] = tolower(answer[i]);
        if (answer == "yes" || answer == "y") {
            logWritten = true; //Without this the program will abort after saying "yes".
            again = false;
        }
        else if (answer == "no" || answer == "n")
            return false;
        else {
            cout << "Invalid entry. Please try again." << endl;
            again = true;
        }
    } while (again == true);
    return true;
}


void clear() {
    cin.ignore();
    cin.clear();
}