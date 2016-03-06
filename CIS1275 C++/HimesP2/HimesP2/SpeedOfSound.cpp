//Alan Himes, ahimes1@cmn.edu, speedofsound.cpp


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;


int main() {
    cout << "\nName: Alan Himes" << endl;
    cout << "Title: Speed of Sound" << endl;
    cout << "Objective: Determine how far away a sound is from its origin\n" << endl;
    
    bool qGas = false;
	bool qSec = false;
	bool done = false;
    string gas;
    string another;
    double seconds, kmph, km, answerMeters, answerFeet, answerYards, answerMph;
    
    cout.precision(3);
    cout.setf(ios::showpoint | ios::fixed);
    
    do {
        /* A while loop for gas, within it another while loop for seconds
        in case of invalid entries. Bools are used to escape loops. */
        while (qGas == false) {
            cout << "\nEnter one of the following gases:" << endl;
            cout << "  Helium" << endl;
            cout << "  Air" << endl;
            cout << "  Carbon Dioxide" << endl;
            cout << "  Oxygen" << endl;
            cout << "  Hydrogen" << endl;
            cout << "  Water Vapor\n" << endl;
            getline(cin, gas);
            while (qSec == false) {
                cout << "Enter, in seconds, the time it took for sound to travel through this gas: ";
                cin >> seconds;
                if (seconds <= 0)
                    cout << "\nYour input value must be above zero." << endl;
                else
                    qSec = true;
            }
                
            //if statements contain the calculations. Distance = kmph * time
            if (gas == "Helium" || gas == "helium" || gas == "HELIUM") {
                kmph = 3473.102;
                km = kmph / 3600 * seconds;
                qGas = true;
                }
            else if (gas == "Air" || gas == "air" || gas == "AIR") {
                kmph = 1191.342;
                km = kmph / 3600 * seconds;
                qGas = true;
                }
            else if (gas == "Carbon Dioxide" || gas == "Carbon dioxide" || gas == "carbon Dioxide" || gas == "carbon dioxide" || gas == "CARBON DIOXIDE") {
                kmph = 932.45;
                km = kmph / 3600 * seconds;
                qGas = true;
                }
            else if (gas == "Oxygen" || gas == "oxygen" || gas == "OXYGEN") {
                kmph = 1137.589;
                km = kmph / 3600 * seconds;
                qGas = true;
                }
            else if (gas == "Hydrogen" || gas == "hydrogen" || gas == "HYDROGEN") {
                kmph = 4642.504;
                km = kmph / 3600 * seconds;
                qGas = true;
                }
            else if (gas == "Water Vapor" || gas == "Water vapor" || gas == "water Vapor" || gas == "water vapor" || gas == "WATER VAPOR") {
                kmph = 1456.816;
                km = kmph / 3600 * seconds;
                qGas = true;
                }
            else {
                cout << "\nThe gas entry was incorrect, please try again." << endl;
                cin.clear(); //not exactly sure why these work, but without them repeats or endless loops happen.
                cin.ignore();
            }
        }
        
        //performing the conversions here, since we'll only end up with one value for the kilometers.
        //1 meter = 3.28084 feet, km/hour = .671371 mph. 
        answerMeters = km * 1000;
        answerFeet = answerMeters * 3.28084;
        answerYards = answerFeet / 3;
        answerMph = kmph * .621371;
        
        cout << "\nIn " << gas << ", sound travels:" << endl;
        cout << setw(15) << answerMeters << " meters" << endl;
        cout << setw(15) << answerFeet << " feet" << endl;
        cout << setw(15) << answerYards << " yards" << endl;
        cout << "at " << answerMph << " miles per hour, 0 degrees Celsius.\n" << endl;
        
        cout << "\nWould you like to perform another calculation? (yes/no)" << endl;
        cin >> another;
        if (another == "Yes" || another == "yes" || another == "YES") {
            qGas = false;
            qSec = false;
            cin.clear();
            cin.ignore();
        }
        else
            done = true;
    } while (done == false);
    cout << "\nGoodbye!\n" << endl;
    return 0;
}