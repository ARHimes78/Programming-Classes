//Alan Himes, ahimes1@cnm.edu
//crowsolver.h, crowsolver.cpp, functions.h, functions.cpp, driver.cpp

#include <iostream>
#include <string>
#include "crowsolver.h"
#include "functions.h"

using namespace std;

void Header();

int main() {
    Header();
    
    CrowSolver crow;
    double pitchDia, pitchHei, pebDia, beakLen;
    string name, yOrN;
    int numPebbles;
    bool anotherCrow;
    
    cout.precision(2);
    cout.setf(ios::showpoint | ios::fixed);
    
    cout << crow.GetDescription();
    //Calling GetDescription with default values here as instructed.
    
    do{
    
        AskPitcherDimensions(&crow, pitchDia, pitchHei);
        AskPebbleDiam(&crow, pebDia);
        AskCrowData(&crow, name, beakLen);
        
        cout << crow.GetDescription();

        cout << "\nAgain? (y/n):";
        getline(cin, yOrN);
        if (tolower(yOrN[0]) == 'y')
            anotherCrow = true;
        else
            anotherCrow = false;
    }while (anotherCrow);
    
    cout << "\nBye!\n" << endl;
    return 0;
    
}

void Header() {
    cout << "\nName: Alan Himes" << endl;
    cout << "Title: Crow Solver" << endl;
    cout << "Objective: Calculate pebbles needed for crow to drink from pitcher\n" 
        << endl;
}