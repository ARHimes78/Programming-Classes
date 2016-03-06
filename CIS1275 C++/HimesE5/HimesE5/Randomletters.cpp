//Alan Himes, ahimes1@cnm.edu, randomletters.cpp


#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


int generateALetter();


int main() {
    cout << "Name: Alan Himes" << endl;
    cout << "Email: ahimes1@cnm.edu" << endl;
    cout << "Title: Random letter generator" << endl;
    cout << "Objective: Generate random letters from user input" << endl;
    
    char letter;
    int seed, i;
    string answer;
    bool repeat = true;
    
    do {
        bool doAgain = true;
        cout << "\nPlease enter a seed value for the random letter generator: " << endl;
        cin >> seed;
        srand(seed);
        cin.ignore();
        cin.clear();
    
        for (i=0; i<15; i++) {
        letter = generateALetter(); //assigning a returned int between 65 and 90 to a char variable will create a letter
            if (i == 14)
                cout << letter << "." << endl;
            else 
                cout << letter << ", ";
        }
        while (doAgain == true) {
            cout << "Generate more random letters? (yes/no): ";
            getline(cin, answer);
            if (answer == "YES" || answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y")
                doAgain = false;
            else if (answer == "NO" || answer == "No" || answer == "no" || answer == "N" || answer == "n") {
                doAgain = false;
                repeat = false;
            }
            else
                cout << "Invalid entry, please try again." << endl;
        }
            
    } while (repeat == true);
    
    cout << "Bye!" << endl;
    return 0;
}


int generateALetter() {
    int rndNum;
    rndNum = rand() % 26; //only possible numbers to generate are 0 through 25, for 26 letters
    return rndNum + 65; // add randomly generated number to 65 to ensure a value between 65 and 90
}