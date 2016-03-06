#include <iostream>
#include <string>

using namespace std;

void programHeader();
string writeToArray(string textLine, string header[8], string cities[25], int popStats[150], int i, int j, int m);
void analyzeData(int popStats[150], string cities[25], int i, int j, int m, int *total2030, int *diff1975, int *incrCongo);
bool writeToFile(string cities[25], string tableDisplay, string *fileName, int &total2030, int &diff1975, int &incrCongo);
