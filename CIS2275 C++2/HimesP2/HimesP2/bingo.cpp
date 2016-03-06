#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include "bingo.h"

using namespace std;

Bingo::Bingo() {
    numValueCounter = 0;
    numValue = 0;
    gameType = "";
    matchOrBlank = "\n\n";
    lettersNumsCalled = "\nNumbers called so far: NONE!";
    char topInit[6] = "BINGO";
    
    for (i=0; i<5; ++i) {
    /*This is silly, but initializing the Top char array in the least tedious
    way. Just saying Top[6] = "BINGO" doesn't work because it was already
    created (in the Bingo class).*/
        Top[i] = topInit[i];
    }
    
    for (i=0; i<5; ++i) {
        for (j=0; j<5; ++j) {
            bingoCard[i][j] = "";
            markedCard[i][j] = "";
        }
    }
    
    FillCard();
}

string Bingo::DisplayCard(string bingoCard[][5]){
    stringstream cardToString;
    
    cardToString << gameType << "\n" << endl;
    
    for(i = 0; i < 5; ++i)
        cardToString << setw(6) << Top[i];

    cardToString << endl;
    
    cardToString << "------------------------------" << endl;
 
    //now print the card, row by row
    for(i=0; i<5; ++i) {
        for(j= 0; j<5; ++j) {
            if (i==2 && j==2)
                cardToString << setw(6) << "FREE";
            else
                cardToString << setw(6) << bingoCard[i][j];
        }
        cardToString << endl; 
    }
    
    cardToString << matchOrBlank;
    
    return cardToString.str();
}

bool Bingo::SetCalledNumber(int &numValue, char &letterValue) {
    /*This method sets the called number in its object, and 
    contributes to an array of already called letters/numbers, 
    which is placed into a stringstream to be shown at the start
    of each turn. Also, MarkCard() is called, and a bool is returned
    whether or not there was a bingo*/
    static int numSoFar[75];
    static char letterSoFar[75];
    bool winner;
    stringstream ssLetNum;
        
    this->numValue = numValue;
    
    MarkCard();
    
    //report every number called so far and continue the game.
    numSoFar[numValueCounter] = numValue;
    letterSoFar[numValueCounter] = letterValue;
        
    ++numValueCounter;
        
    ssLetNum << "\nNumbers called so far: ";
        
    for (i=0; i<numValueCounter; i++) {
    
        if (i == numValueCounter - 1)
            ssLetNum << letterSoFar[i] << numSoFar[i] << ".";
        else
            ssLetNum << letterSoFar[i] << numSoFar[i] << ", ";
    }
    
    lettersNumsCalled = ssLetNum.str();
    
    if (gameType == "X Bingo")
        winner = CheckForXBingo();
    else if (gameType == "Square Bingo")
        winner = CheckForSQBingo();
        
    return winner;
}

string Bingo::DisplayCard(string bingoCard[][5], string markedCard[][5], int &counter){
    
    if (counter == 0 && matchOrBlank == "\n") {
        return DisplayCard(bingoCard);
    }
    
    else {
        return DisplayCard(markedCard);	
    }
}

void Bingo::Win(){
    
    gameType = "";
    matchOrBlank = "\n\n";
    
    cout << "\nBINGO!!\n" << endl;
    cout <<  "\\" << setw(5) << "\\" << setw(5) << "|" 
        << setw(5) << "|" << setw(5) << "|" << setw(5) << "/" << setw(5) << "/" << endl;
    cout << DisplayCard(markedCard);
    cout <<  "/" << setw(5) << "/" << setw(5) << "|" 
        << setw(5) << "|" << setw(5) << "|" << setw(5) << "\\" << setw(5) << "\\" << endl;
}



void Bingo::FillCard(){
    
    int values[25];
    bool check; 
    
    do {
        check = true; 
        //give the loop a chance to make it through without duplicated numbers.
        
        for (i=0; i<5; ++i) {
            for (j=0; j<5; ++j) {
                value = rand() % 15 + 1;
                bingoCard[i][j] = to_string(value + (j * 15));
                if (i == 2 && j == 2)
                    bingoCard[i][j] = '*';
                markedCard[i][j] = bingoCard[i][j]; 
                //At this point markedCard is just a copy of the bingoCard.
                values[(i*5) + j] = atoi(bingoCard[i][j].c_str());
                /*copied all the values of the bingo card to another array 
                to compare for duplicates.*/
            }
        }
    
        for (i=0; i<25; ++i) {
            for (j=0; j<25; ++j) {
                /*after a lot of trial and error I figured out a way to iterate through a 
                multi-dimensional array as though it were single-dimensional. Instead
                of copying from the textbook, I decided to invent a way to test for repeating
                numbers on the bingo card using nested loops.*/
                if (bingoCard[i/5][(i - (i/5)) - (4*(i/5))] == to_string(values[j]) && i != j) {
                    check = false; 
                    /*if any duplicate numbers are detected the loop repeats until 
                    there are none.*/
                }
            }
        }
    } while (!check);
}
void Bingo::MarkCard(){
    
    bool match = false;
    stringstream ssMatch;
    
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            if (bingoCard[i][j] == to_string(numValue)) {//exclude the "free" space
                markedCard[i][j] = '*'; 
                match = true;
            }
        }
    }
    
    if (match)
        ssMatch << "\nA match!!" << endl;
    else
        ssMatch << "\n" << endl; //for smoother re-prints of the bingo boards
        
        matchOrBlank = ssMatch.str();
}

bool Bingo::CheckForXBingo(){
    
    int diagACount = 0;
    int diagBCount = 0;
    bool diagonalA = false; 
    bool diagonalB = false;
    
    int i, j;
        
    for (i=0,j=0; i<5; ++i,++j) {
        if (markedCard[i][j] == "*")
            ++diagACount;
    }
    
    for (i=0,j=4; i<5; ++i,--j) {
        if (markedCard[i][j] == "*")
            ++diagBCount;
    }
    
    if (diagACount == 5)
        diagonalA = true;
        
    if (diagBCount == 5)
        diagonalB = true;
    
    if (diagonalA && diagonalB) {//If there's an X...
        return true;
    }
    else
        return false;
}

bool Bingo::CheckForSQBingo(){
    
    int horizACount = 0; 
    int vertACount = 0;
    int horizBCount = 0;
    int vertBCount = 0;
    bool horizontalA = false;
    bool verticalA = false;
    bool horizontalB = false;
    bool verticalB = false;
    
    for (i=0; i<5; ++i) {
        if (markedCard[0][i] == "*")
            ++horizACount;
        if (markedCard[i][0] == "*")
            ++vertACount;
        if (markedCard[4][i] == "*")
            ++horizBCount;
        if (markedCard[i][4] == "*")
            ++vertBCount;
    }
    
    if (horizACount == 5)
        horizontalA = true;
    if (vertACount == 5)
        verticalA = true;
    if (horizBCount == 5)
        horizontalB = true;
    if (vertBCount == 5)
        verticalB = true;
        
    if (verticalA && horizontalA && verticalB && horizontalB) {
        return true;
    }
    else
        return false;
}