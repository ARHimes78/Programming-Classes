//Alan Himes, ahimes1@cnm.edu, driver.cpp, bingo.cpp, bingo.h
 
#include <iostream>
#include <string>
#include "Header.h"
 
using namespace std;
 
int main() {
    Header();
    bool bBingo = true;
    bool playAgain = true;
    bool moreBingo = false;
    int bingoCard[5][5];
    int numValue, resetFlag = 0;
    int markedCard[5][5];
    string answer;
 
    do {
        FillCard(bingoCard, markedCard);
        bBingo = false;
        DisplayCard(bingoCard);
        
        do {
            cout << "\nTurn #" << resetFlag + 1 << endl;
            DisplayCard(bingoCard, markedCard, moreBingo);
            numValue = GetRandomNumber(resetFlag);
            MarkCard(bingoCard, markedCard, numValue);
            bBingo = CheckForXBingo(markedCard);
        } while(!bBingo);
        cout << "\nWould you like to play again? ";
        getline(cin, answer);
        
        if (tolower(answer[0]) == 'y') {
            playAgain = true;
            moreBingo = true;
            resetFlag = 0; //resetting the reset flag
            cout << endl;
        }
        else
            playAgain = false;
    } while (playAgain);
    cout << "Bye!" << endl;
    return 0;
}
 
