//Alan Himes, ahimes1@cnm.edu, CityPop.cpp, popfunctions.cpp, popfunctions.h


#include <iostream> //all
#include <string> //all
#include "popfunctions.h"
#define FILE_IN "pop.txt"

using namespace std;

int main() {
    
    programHeader();
    
    string textLine;
    string tableDisplay;
    int i = 0; 
	int j = 0;
	int m = 0;
    bool fileSuccess;
    string fileName;
    //The following 3 arrays contain all the information from pop.txt. They will be passed to other functions.
    string header[8];
    string cities[25];
    int popStats[150];
    int total2030 = 0; 
	int diff1975 = 0;
	int incrCongo = 0;
    
    tableDisplay = writeToArray(textLine, header, cities, popStats, i, j, m);
    analyzeData(popStats, cities, i, j, m, &total2030, &diff1975, &incrCongo);
    fileSuccess = writeToFile(cities, tableDisplay, &fileName, total2030, diff1975, incrCongo);
    
    if (fileSuccess == false) {
        cout << "Error writing to file!" << endl;
        exit(1);
    }
    else {
        cout << fileName << " was created successfully!" << endl;
        cout << "Bye!" << endl;
        return 0;
    }
}