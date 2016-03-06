#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include "crowsolver.h"//needed because of CrowSolver object arguments
#define PI 3.14159265359

using namespace std;

CrowSolver::CrowSolver() {
    caseNumber = -1;
    /*Set to -1 because the instructions say to run GetDescription() before any 
    information is set, other than what is being initialized in this constructor.
    Because I'm using increments for caseNumber, the first run will be "case #0".*/
    pitcherDia = 0.0;
    pitcherHei = 0.0;
    crowName = "***UNNAMED CROW***";
    beakLength = 0.0;
    pebbleDia = 0.0;
    numPebbles = 0;
    abort = false;
}

void CrowSolver::SetPitcherDimensions(double dia, double hei) {
    pitcherDia = dia; 
    pitcherHei = hei;
    
    CalcPebbles();
    //Calling CalcPebbles in every set function as instructed.
}

void CrowSolver::SetCrowInfo(string name, double beak) {
    crowName = name; 
    beakLength = beak;
    
    CalcPebbles();
}

void CrowSolver::SetPebbleDiameter(double dia) {
    pebbleDia = dia;
    
    CalcPebbles();
}

string CrowSolver::GetDescription() {
    stringstream ssDesc;
    string pebbleOrPebbles;
    int textSpace = 12;
    int i;
    
    numPebbles = GetPebbles();
    /*
    Although this method already knows what numPebbles is, I used GetPebbles()
    (which returns an int) here because I could find no other use for it.
    The instructions said to include the number of pebbles into the string with
    GetDescription(), otherwise I would have done this in main().
    */
    
    for (i=1; i<3; ++i) {
        if (caseNumber + 1 >= pow(10, i))
            textSpace++;
        /*Maintains the left-justified format of the description text with increasing
        case number digits for up to 9999 calculations.*/
    }
    
    if (abort && caseNumber >= 0) //from CalcPebbles()
        ssDesc << "\nThe crow's beak is long enough to drink, no pebbles are necessary!" << endl;

    ssDesc << "\n" << "Case #" << ++caseNumber
        << setw(5) << "" << "Crow's beak is " << beakLength << "\" long."
        << setw(5) << "" << "Pitcher is " << pitcherHei << "\" high and "
        << pitcherDia << "\" in diameter." << "\n"
        << setw(textSpace) << "" << "Pebble is " << pebbleDia << "\" in diameter." << "\n"
        << setw(textSpace) << "" << "Crow's name is " << crowName << ".\n" << endl;
        
        if (numPebbles == 1)
            pebbleOrPebbles = " pebble is";
        else
            pebbleOrPebbles = " pebbles are";
        
        ssDesc << numPebbles << pebbleOrPebbles << " needed for " 
            << crowName << " to get a drink." << endl;
        
    return ssDesc.str();
}    

void CrowSolver::CalcPebbles() {
    
    double pitchVol = PI * pow((pitcherDia / 2), 2) * pitcherHei;
    //Total volume of the pitcher
    
    
    double pebbleVol = (4.0 / 3.0) * PI * pow((pebbleDia / 2), 3);
    //Total volume of the pebble
    
    double drinkVol = PI * pow((pitcherDia / 2), 2) * (pitcherHei - beakLength + .5);
    /*This is the volume needed for the crow to drink. The .5 added allows for the
    beak's half-an-inch.*/
    
    pitchVol = pitchVol / 2;
    //Pitcher is half full of water.
    
    double neededVol = drinkVol - pitchVol;
    //this is the total volume increase because of pebbles.
    
    if (neededVol <= 0) {
    /*in the case that there's a negative value when subtracting the drinkable
    water amount from half of the pitcher's total volume, because the crow's
    beak is long enough to not need pebbles.*/
    
        abort = true;
        numPebbles = 0;
        return;
    }
    else
        abort = false;
    
    double doubNumPebbles = neededVol / pebbleVol;
    numPebbles = ceil(doubNumPebbles);
    
}