#include <iostream>
#include <string>

using namespace std;

void header();
void AskForLetterAndSeriesLength(char *pc, int *plength);
bool IsValidLetter(char c);
string BuildSeries(char c, int num);
void doAgain(bool &again, bool &repeat);
void clear();