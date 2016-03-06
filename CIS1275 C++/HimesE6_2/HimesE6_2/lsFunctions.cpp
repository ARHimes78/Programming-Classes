#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "lsFunctions.h" //Because clear() is inside some of these functions

using namespace std;

void header() {
    cout << "Name: Alan Himes" << endl;
    cout << "Title: Letter Series" << endl;
    cout << "Objective: Create list of letters from input" << endl;
}


void AskForLetterAndSeriesLength(char *pc, int *plength) {
    cout << "\nEnter a letter (A-Z or a-z): ";
    cin >> *pc;
    cout << "How many characters after this letter should be listed? ";
    cin >> *plength;
    clear();
}


bool IsValidLetter(char c) {
    if ((c >= 65 && c <= 90) || (c >=97 && c <=122)) //if character is within range of ascii values for capital or lowercase letters
        return true;
    else
        return false;
}


string BuildSeries(char c, int num) {
    stringstream ss;
    string series;
    int i;
    
    cout << "Chosen letter: " << c << endl;
    cout << "Number of letters following the chosen letter: " << num << endl;
    ss << c; //show the input letter, if number is zero this is all that will output from the string because for loop will be skipped.
    for (i=0; i<num; i++) {
        if (c + 1 == 91)
            c = 65;
        else if (c + 1 == 123)
            c = 97;
        else
            c++;
        
        ss << ", " << c ;
    }
    ss << endl;
    series = ss.str();
    return series;
}


void doAgain(bool &again, bool &repeat) {
    string answer;
    cout << "Would you like to do another letter series? (yes/no): ";
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