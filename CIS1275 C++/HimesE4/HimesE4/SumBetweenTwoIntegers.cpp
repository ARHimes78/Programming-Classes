//Alan Himes, ahimes1@cnm.edu


#include <iostream>
#include <string>
#include <cmath>


using namespace std;


void numbers(int num1, int num2);
string another();
void clear();


bool same = false;


int main() {
    cout << "Name: Alan Himes" << endl;
    cout << "Email: ahimes1@cnm.edu" << endl;
    cout << "Title: Sum Between Two Integers" << endl;
    cout << "Objective: Add two user-input integers with all the numbers between them" << endl;
    
    int num1, num2;
    string answer;
    bool repeat, again = false;
    
    do {
        repeat = false; 
        same = false; //just in case they were set to true
        cout << "\nEnter one number: ";
        cin >> num1;
        clear(); //function removes Enter from input queue and protects from non-numbers causing infinite loops
        cout << "\nEnter another number: ";
        cin >> num2;
        clear();
        numbers (num1, num2);
        if (same == true) //code within the "numbers" function, start loop over if numbers were identical
            continue;
        while (repeat == false) {
            answer = another();
            if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "Y" || answer == "y") {
                break; //break from the while loop and let the do while loop repeat
            }
            else if (answer == "no" || answer == "No" || answer == "NO" || answer == "N" || answer == "n") {
                repeat = true;
                again = true; //escape while and do while loops
            }
            else {
                cout << "Invalid entry, please try again." << endl;
                continue; //repeat while loop
            }
        }
    } while (again == false);
cout << "\nBye!" << endl;
return 0;
}


void numbers (int num1, int num2) {
    int high, low, i, answer, answerAdd;
    //test if numbers are the same, if so, use global variable "same" to trigger starting the "while" over within the if condition 
    if (num1 == num2) {
        cout << "Please enter two different numbers. ";
        same = true;
    }
    //Determine which number is the low and which is the high
    //Add the low number with itself + 1, repeat until high number is reached
    else {
        if (num1 > num2) {
            high = num1;
            low = num2;
            answerAdd = low;
            answer = low;
            for (i = low; i < high; i++) {
                ++answerAdd;
                answer = answer + answerAdd;
            }
        }
        else if (num1 < num2) {
            high = num2;
            low = num1;
            answerAdd = low;
            answer = low;
            for (i = low; i < high; i++) {
                ++answerAdd;
                answer = answer + answerAdd;
            }
        }
    cout << "The sum of integers from " << low << " to " << high << " is " << answer << "." << endl;
    }
}


string another() {
    string answer;
    
    cout << "Would you like to find the sum of the numbers between two numbers again? (yes/no): ";
    getline(cin, answer);
    return answer;
}


void clear() {
    cin.clear();
    cin.ignore();
}