#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

void Header(){
    cout << "Name: Alan Himes" << endl;
    cout << "Title: Bingo" << endl;
    cout << "Objective: Create a game of bingo\n\n" << endl;
}
 
void FillCard(int bingoCard[][5], int markedCard[][5]){
    int row, col, i, j, value, loopcount = 0;//loopcount for debugging
    int values[25];
    bool check; 
    srand(time(NULL));
    
    for (row=0;row<5;++row) {
        for (col=0;col<5;++col) {
            //initializing bingoCard[][] and markedCard[][].
            bingoCard[row][col] = 0;
            markedCard[row][col] = 0; 
        }
    }
    
    do {
        check = true; //give the loop a chance to make it through without duplicated numbers.
        
        /*cout << "loopcount = " << loopcount << endl; 
        for debugging.*/
        
        for (row=0; row<5; ++row) {
            for (col=0; col<5; ++col) {
                value = rand() % 15 + 1;
                bingoCard[row][col] = value + (col * 15);
                if (row == 2 && col == 2)
                    bingoCard[row][col] = 100;
                markedCard[row][col] = bingoCard[row][col]; //At this point markedCard is just a copy of the bingoCard.
                values[(row*5) + col] = bingoCard[row][col];
                //copied all the values of the bingo card to another array to compare for duplicates.
            }
        }
    
        for (i=0; i<25; ++i) {
            for (j=0; j<25; ++j) {
                /*after a lot of trial and error I figured out a way to iterate through a 
                multi-dimensional array as though it were single-dimensional. Instead
                of copying from the textbook, I decided to invent a way to test for repeating
                numbers on the bingo card using nested loops.*/
                if (bingoCard[i/5][(i - (i/5)) - (4*(i/5))] == values[j] && i != j) {
                    /*
                    This commented out area was used for debugging.
                    cout << "i = " << i << " j = " << j << endl;
                    cout << bingoCard[i/5][(i - (i/5)) - (4*(i/5))] << " = " << values[j] << endl;
                    */
                    check = false; 
                    //if any duplicate numbers are detected the loop repeats until there are none.
                }
            }
        }
            
        loopcount++;//used this to see if the loop was actually working
    
    } while (!check);
}
 
void DisplayCard(int bingoCard[][5]){
    //copied from the textbook.
    char Top[10] = "BINGO";
    int row, col, i;
    for(i = 0; i < 5; ++i)
        cout << setw(6) << Top[i];


    cout << endl;
    
    cout << "------------------------------" << endl;
 
    //now print the card, row by row
    for(row = 0; row < 5; ++ row) {
        for(col = 0; col < 5; ++ col) {
            if(col == 2 && row == 2)
                cout << setw(6) << "FREE";
            else if (bingoCard[row][col] == 0) //this is actually markedCard[][] being passed to this function.
                cout << setw(6) << "*";
            else
                cout << setw(6) << bingoCard[row][col];
        }
        cout << endl; 
    }
}
 
void DisplayCard(int bingoCard[][5], int markedCard[][5], bool &moreBingo){
    static int games = 0;
    char Top[10] = "BINGO";
    int row, col, i;
    
    if (moreBingo) {
        games = 0;
        moreBingo = false; //will become true again if there's another game
    }
    
    if (games == 0) { //The only purpose of the "moreBingo" bool is to ensure this message displays every time.
        cout << "\nTime for a fresh game of bingo!\n" << endl;
        DisplayCard(bingoCard);
    }
    
    else {
        cout << "\nGame in progress:\n" << endl;
        DisplayCard(markedCard); //DisplayCard() has instructions to place asterisks in matched number slots.
    }
    
    ++games;


}
 
int GetRandomNumber(int &resetFlag){//resetFlag came in from main, where it's set to zero before the first and repeated games begin.
    int numValue;
    int i;
    static int alreadyCalled[75];
    bool already;
    
    if (resetFlag == 0) { //only initialize the array the first time
        for (i=0; i<75; i++)
            alreadyCalled[i] = resetFlag;
        }
    
    do {
        already = true;
        numValue = rand() % 75 + 1;


        alreadyCalled[resetFlag] = numValue; //adding number to array, add a different number if there's a duplicate.
        
        for (i=0; i<resetFlag; i++) { //check the array so far to see if there are any duplicates
                
            if (alreadyCalled[i] == numValue)
                already = false; //will loop until there are only unique numbers in the array.
        }
    } while (!already);
    
    if (resetFlag !=0) {
        cout << "\nNumbers called so far: ";
        
        for (i=0; i<resetFlag; i++) {
            if (i == resetFlag - 1)
                cout << alreadyCalled[i] << "." << endl;
            else
                cout << alreadyCalled[i] << ", ";
        }
    }
                
    
    cout << "\n\"" << numValue << ".\"" << endl; //calling out the number 
    resetFlag++;
    return numValue;
}
 
void MarkCard(int bingoCard[][5], int markedCard[][5], int &numValue){
    int row, col;
    string pressEnter = "";
    
    for (row=0; row<5; row++) {
        for (col=0; col<5; col++) {
            if (bingoCard[row][col] == numValue) {//exclude the "free" space
                markedCard[row][col] = 0; 
                //the 0 is an indicator to display asterisks in the place of matching numbers.
                cout << "\nA match!!" << endl;
            }
        }
    }
    cout << "\nPress Enter to continue or Q to quit: ";
    getline(cin, pressEnter);
    if (tolower(pressEnter[0]) == 'q') {
        cout << "BINGO ABORTED!" << endl;
        exit(1);
    }
}
 
bool CheckForXBingo(int markedCard[][5]){
    
    //"BINGO" only happens if there's an X.
    
    bool diagonalA = false; 
    bool diagonalB = false;
    
    if (markedCard[0][0] == 0 && markedCard[1][1] == 0 && markedCard[3][3] == 0 && markedCard[4][4] == 0)
        diagonalA = true;
    if (markedCard[0][4] == 0 && markedCard[1][3] == 0 && markedCard[3][1] == 0 && markedCard[4][0] == 0)
        diagonalB = true;
    if (diagonalA && diagonalB) {//If there's an X...
        cout << "\nBINGO!!\n" << endl;
        cout <<  "\\" << setw(5) << "\\" << setw(5) << "|" << setw(5) << "|" << setw(5) << "|" << setw(5) << "/" << setw(5) << "/" << endl;
        DisplayCard(markedCard);
        cout <<  "/" << setw(5) << "/" << setw(5) << "|" << setw(5) << "|" << setw(5) << "|" << setw(5) << "\\" << setw(5) << "\\" << endl;
        return true;
    }
    else
        return false;
}