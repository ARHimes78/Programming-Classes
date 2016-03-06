#include <iostream>
#include <string>

using namespace std;

void header();
string AskName(string name);
void AskForBarrels(float &diam, float &height, int &num);
float CalcNetWhiskeyVol(float diam, float height, int num);
float DetermineBottles(float volume, int *pt_cases, int *pt_bottles, int *pt_leftover);
void doAgain(bool &repeat, bool &again);
void clear();