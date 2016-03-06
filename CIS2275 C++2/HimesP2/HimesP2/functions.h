#include <iostream>
#include <string>

using namespace std;

void Header();
string ChooseGameType();
/*A switch/case asks which gametype for each card, then returns a string which
will be passed into SetBingoPattern().*/
void pressEnter();
void setColor(int color);
int GetRandomNumber(bool &resetFlag, char Top[], char &letterValue, int &counter);