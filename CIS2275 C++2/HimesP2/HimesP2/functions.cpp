#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;

void Header() {
    cout << "\nName: Alan Himes" << endl;
    cout << "Title: Bingo" << endl;
    cout << "Objective: The Bingo program with classes\n\n" << endl;
}

string ChooseGameType() {
    static int redOrBlue = 2;
    int gameChoice = 0;
    string color, gameType = "";
    bool choiceLoop;
    
    if (redOrBlue % 2 == 0)
    //because of the later increment, even or odd will determine the color asked.
        color = "blue";
    else
        color = "red";
    
    do {
        cout << "\nChoose a game type for the " << color << " card:" << endl;
        cout << "\n1: Player wins with X Bingo (both diagonals)" << endl;
        cout << "2: Player wins with Square Bingo (all the edge numbers)\n" << endl;
    
        cin >> gameChoice;
        
        switch (gameChoice) {
            case 1:
                gameType = "X Bingo";
                choiceLoop = false;
                break;
            case 2:
                gameType = "Square Bingo";
                choiceLoop = false;
                break;
            default:
                cout << "\nPlease choose 1 or 2." << endl;
                choiceLoop = true;
        }
    } while (choiceLoop);
    
    cin.clear();
    cin.ignore();
    
    ++redOrBlue;
    
    return gameType;
}

void pressEnter() {
    string pressEnter;
    
    cout << "\nPress Enter to continue or Q to quit: ";
    getline(cin, pressEnter);
    if (tolower(pressEnter[0]) == 'q') {
        cout << "\nBINGO ABORTED!\n" << endl;
        exit(1);
    }
}

void setColor(int color) {
	HANDLE textColors = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(textColors, color);
}

int GetRandomNumber(bool &resetFlag, char Top[], char &letterValue, int &counter){
    //resetFlag came in from main, where it's set to false before a game begins.
    int i, numValue, bingoMath;
    //bingoMath will be used to find out which letter goes with which number.
    static int alreadyCalled[75];
    bool already;
    
    if (!resetFlag) { //only initialize the array the first time
        for (i=0; i<75; i++)
            alreadyCalled[i] = 0;

		resetFlag = true;
    }
    
    do {
        //With this loop, only a new number will be allowed.
        already = true;
        numValue = rand() % 75 + 1;

        alreadyCalled[counter] = numValue; 
        //adding number to array, add a different number if there's a duplicate.
        
        for (i=0; i<counter; i++) { 
            //check the array so far to see if there are any duplicates
                
            if (alreadyCalled[i] == numValue) {
                already = false; 
                //will loop until there are only unique numbers in the array.
			}
        }
    } while (!already);
    
    /*from dividing the current "already called number by 15,
    the correct element number of the character array of "BINGO"
    can be associated with the number. Decimal remainder is
    truncated when assigned to an int.
    */
    bingoMath = numValue / 15;
    
    if (numValue % 15 == 0)
    /* since "B row" is 1 - 15, "I row" is 16 - 30, etc.,
    when bingoMath gets factors of 15/15, it will need to be decremented.
    */
    --bingoMath;
    
    letterValue = Top[bingoMath];
	//this is also "returned" because it will be used somewhere else.
    
    cout << "\n\n\"" << letterValue 
        << numValue << ".\"" << endl; //calling out the number 
    return numValue;
}