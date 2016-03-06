//Alan Himes, ahimes1@cnm.edu, driver.cpp, bingo.cpp, bingo.h
 
#include <iostream>
#include <ctime>
#include <string>
#include "bingo.h"
#include "functions.h"
#include "Windows.h"

using namespace std;

int main(){
    Header();
    
    srand(time(NULL));
	//HANDLE textColors = GetStdHandle(STD_OUTPUT_HANDLE);
    
    int numValue, counter;
    char letterValue;
    string gameType, answer;
    bool resetFlag = false;
	bool gameOver = false;
    bool bBlue, bRed, playAgain;
    
    do {
        Bingo blue, red;
        
		setColor(7);
        gameType = ChooseGameType();
        blue.SetBingoPattern(gameType);
        setColor(9);
		cout << "\nThe Blue Card!\n" << endl;
        cout << blue.DisplayCard(blue.bingoCard);
        
		setColor(7);
        gameType = ChooseGameType();
		setColor(12);
        red.SetBingoPattern(gameType);
        cout << "\nThe Red Card!\n" << endl;
        cout << red.DisplayCard(red.bingoCard);
        
		setColor(7);
        pressEnter();
        
        do {
            counter = blue.numValueCounter;
			setColor(7);
            cout << "\n\n\nTurn #" << counter + 1 << endl;
            
            cout << blue.callReview();
            
            numValue = GetRandomNumber(resetFlag, blue.Top, letterValue, counter);
            
			setColor(9);
            cout << "\n\nBlue Card\n" << endl;
            bBlue = blue.SetCalledNumber(numValue, letterValue);
            cout << blue.DisplayCard(blue.bingoCard, blue.markedCard, counter);
            //change displayCard to return a string of the card, place in a cout <<
            
			setColor(12);
            cout << "\n\nRed Card\n" << endl;
            bRed = red.SetCalledNumber(numValue, letterValue);
            cout << red.DisplayCard(red.bingoCard, red.markedCard, counter);
            
            setColor(7);
            pressEnter();
            
            if (bBlue && bRed) {
				setColor(9);
                blue.Win();
				setColor(12);
                red.Win();
                cout << "\nIt's a tie!!!" << endl;
                gameOver = true;
            }
            else if (bBlue) {
				setColor(9);
                blue.Win();
                cout << "\nBlue wins!!!" << endl;
                gameOver = true;
            }
            else if (bRed) {
				setColor(12);
                red.Win();
                cout << "\nRed wins!!!" << endl;
                gameOver = true;
            }
            
        }while(!gameOver);
        
		setColor(7);
        cout << "\nWould you like to play again (y/n)? ";
        getline(cin, answer);
        
        if (tolower(answer[0]) == 'y') {
            resetFlag = false;
            gameOver = false;
            playAgain = true;
            cout << endl;
        }
        else
            playAgain = false;
        
    } while(playAgain);
    
    cout << "\nBye!\n" << endl;
    
}