//Alan Himes, ahimes1@cnm.edu, distanceconverter.cpp
#include <iostream>
#include <iomanip>


using namespace std;


int main() {
    cout << "Name: Alan Himes" << endl;
    cout << "Title: Distance Converter" << endl;
    cout << "Objective: Convert distance values" << endl;
    
    cout.precision(3);
    cout.setf(ios::showpoint | ios::fixed);
    
    bool exit = false;
    int feet;
    int inches, inchesAnswer;
    int choice;
    float decFeet;
    
    do {
        cout << "\nDistance Converter" << endl;
        cout << "\nPlease choose one of the following:\n" << endl;
        cout << "1:" << setw(30) << "Inches to feet & inches" << endl;
        cout << "2:" << setw(30) << "Feet & inches to decimal feet" << endl;
        cout << "3:" << setw(30) << "Feet & inches to inches" << endl;
        cout << "4:" << setw(30) << "Exit" << endl;
        cout << "\n";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter a number of inches: ";
                cin >> inches;
                feet = inches / 12;
                inchesAnswer = inches % 12;
                cout << "\n" << inches << "\" is " << feet << "' and " << inchesAnswer << "\"." << endl;
                break;
            case 2:
                cout.precision(3);
                cout.setf(ios::showpoint | ios::fixed);
                cout << "Enter a number of feet: ";
                cin >> feet;
                cout << "Enter a number of inches: ";
                cin >> inches;
                decFeet = (static_cast<float>(feet) * 12 + static_cast<float>(inches))/12;
                cout << "\n" << feet << "', " << inches << "\" is " << decFeet << "\'." << endl;
                cout.unsetf(ios::showpoint | ios:: fixed);
                break;
            case 3:
                cout.setf(ios::showpoint | ios::fixed);
                cout << "Enter a number of feet: ";
                cin >> feet;
                cout << "Enter a number of inches: ";
                cin >> inches;
                inchesAnswer = feet * 12 + inches;
                cout << "\n" << feet << "' and " << inches << "\" is " << inchesAnswer << "\"." << endl;
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "\nInvalid entry, please try again." << endl;           
        }
		cin.clear();
		cin.ignore();
    } while (exit == false);
    cout << "Goodbye!" << endl;
    return 0;
}