#include <iostream>
#include <string>

using namespace std;

void header();
void ShowInstructions();
void ShowTheMoney(float &bet, float &balance, int &seed);
int MakeABet();
int spinWheel(int &seed);
float FigureWinnings(float &bet, int &spin, int &numBet);
string CreateLogText(float &bet, int &spin, int &numBet, float &balance, float &winnings, float &totalWinnings, float &betTotal, string &forFileName);
bool WriteLog(string &logText, string *forFileName, bool *playAgain, float &betTotal, string &numBets, string &spins, float &totalWinnings, float &balance);
bool anotherGame(bool &logWritten, float &balance);
void clear();