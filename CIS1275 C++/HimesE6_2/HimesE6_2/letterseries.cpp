//Name: Alan Himes Email: ahimes1@cnm.edu Filename: letterseries.cpp, lsFunctions.cpp, lsFunctions.h

#include <iostream>
#include <iomanip>
#include <string>
#include "lsFunctions.h"

using namespace std;

int main() {
    header();
    
    char c;
    int num;
    bool validate;
    bool repeat;
    bool again;
    string series;
    
    do {
        AskForLetterAndSeriesLength(&c, &num);
        validate = IsValidLetter(c);
        
        if (validate == true) {
            series = BuildSeries(c, num);
            cout << series;
        }
        else //the only other possibility is that validate will receive a false value
            cout << "Invalid character." << endl;
        do {
            doAgain(again, repeat);
        } while (again == true);
    } while (repeat == true);
    cout << "Bye!" << endl;
    return 0;
}