#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "distFunctions.h" //Because Clear() is inside some of these functions
#define PI 3.14159

using namespace std;

void header() {
    cout << "Name: Alan Himes" << endl;
    cout << "Title: Distillery" << endl;
    cout << "Objective: Calculate how many whiskey bottles "
    << "are needed from barrels\n" << endl;
}


string AskName(string name) {
    cout << "Name of whiskey: ";
    getline(cin, name);
    return name;
}


void AskForBarrels(float &diam, float &height, int &num) {
    cout << "Barrel diameter (inches): ";
    cin >> diam;
    cout << "Barrel height (inches): ";
    cin >> height;
    cout << "Number of barrels: ";
    cin >> num;
    clear();
}


float CalcNetWhiskeyVol(float diam, float height, int num) {
    float volume = pow(diam/2, 2) * PI * height * num;
    //pi times radius squared times height times number of barrels
    
    volume = volume / 61.0237;
    //convert cubic inches to liters
    
    return volume * .95;
    //5% loss
}


float DetermineBottles(float volume, int *pt_cases, int *pt_bottles, int *pt_leftover) {
    float fBottles, incomplete;
    
    fBottles = volume / 1.5;
    //Using float amount because of the 1.5 liters
    *pt_bottles = fBottles;
    //Decimal amount truncated when assigned to integer.
    incomplete = fBottles - *pt_bottles;
    //Any amount less than 1 cannot fill a bottle completely
    
    *pt_cases = *pt_bottles / 12;
    *pt_leftover = *pt_bottles % 12;
    
    return incomplete;
    //Remaining decimal bottle amount will be returned to main function.
}


void doAgain(bool &repeat, bool &again) {
    string answer;
    cout << "Would you like to calculate barrels of whiskey again? (yes/no): " << endl;
    getline(cin, answer);
    if (answer == "YES" || answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y") {
        again = false;
        repeat = true;
    }
    else if (answer == "NO" || answer == "No" || answer == "no" || answer == "N" || answer == "n") {
        again = false;
        repeat = false;
    }
    else {
        cout << "Invalid entry, please try again." << endl;
        again = true;
    }
}


void clear() {
    cin.ignore();
    cin.clear();
}