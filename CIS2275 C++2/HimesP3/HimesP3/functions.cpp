#include <iostream>
#include <string>
#include <limits>
#include <ios>
#include "functions.h"//needed because of Clear()
#include "crowsolver.h"//needed because of CrowSolver object arguments

using namespace std;

void AskPitcherDimensions(CrowSolver *crow, double &pitchDia, double &pitchHei) {
    cout << "\nWhat is the diameter of the pitcher? ";
    cin >> pitchDia;
    cout << "What is the height of the pitcher? ";
    cin >> pitchHei;
    
    crow->SetPitcherDimensions(pitchDia, pitchHei);
}

void AskPebbleDiam(CrowSolver *crow, double &pebDia) {
    cout << "What is the diameter of the pebble? ";
    cin >> pebDia;
    Clear();
    
    crow->SetPebbleDiameter(pebDia);
}

void AskCrowData(CrowSolver *crow, string &name, double &beakLen) {
    
    cout << "What is the crow's name? ";
    getline(cin, name);
    cout << "What is the length of " << name << "'s beak? ";
    cin >> beakLen;
    Clear();
    
    crow->SetCrowInfo(name, beakLen);
}

void Clear() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}