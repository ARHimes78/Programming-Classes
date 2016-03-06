//Alan Himes, ahimes1@cnm.edu, distillery.cpp, distFunctions.cpp. distFunctions.h


#include <iostream>
#include <iomanip>
#include <string>
#include "distFunctions.h"

using namespace std;

int main() {
    header();
    
    string name;
    bool repeat;
    bool again;
    float diam, height, volume, incomplete;
    int num, cases, bottles, leftover;
    
    cout.setf(ios::showpoint|ios::fixed);
    cout.precision(2);
    
    do {
        name = AskName(name);
        AskForBarrels(diam, height, num);
        volume = CalcNetWhiskeyVol(diam, height, num);
        incomplete = DetermineBottles(volume, &cases, &bottles, &leftover) + leftover;
        /*Amount of whiskey less than 1.5 liters plus remaining bottles from cases
        for the crew to enjoy. */
        
        cout << "\nSummary:" << endl;
        cout << "With " << num << " barrels of " << name 
        << " whiskey, each with a diameter of " << diam
        << "\" and a height of " << height 
        << "\", the total volume (minus %5) is "
        << volume << " liters." << endl;
        cout << "Amount of bottles: " << bottles << "." << endl;
        cout << "Amount of cases: " << cases << "." << endl;
        cout << "Amount left over: " << incomplete << " bottles." << endl;
        
        do {
            doAgain(repeat, again);
        } while (again == true);
    } while (repeat == true);
    cout << "Bye!" << endl;
    return 0;
}