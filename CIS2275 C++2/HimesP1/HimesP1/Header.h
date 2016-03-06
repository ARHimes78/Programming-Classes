#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;
 
void Header();
void FillCard(int bingoCard[][5], int markedCard[][5]);
void DisplayCard(int bingoCard[][5]);
void DisplayCard(int bingoCard[][5], int markedCard[][5], bool &moreBingo);
int GetRandomNumber(int &resetFlag);
void MarkCard(int bingoCard[][5], int markedCard[][5], int &numValue);
bool CheckForXBingo(int markedCard[][5]);