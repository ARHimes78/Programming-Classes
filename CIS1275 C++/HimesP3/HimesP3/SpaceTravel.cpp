//Alan Himes, ahimes1.cnm.edu, spacetravel.cpp

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>


using namespace std;

string name();
float planetTime(int choice, float rate);
float planetWeight( int choice, float weight);
string another(string inputName);
void clear();


int main() {
    cout << "Name: Alan Himes" << endl;
    cout << "Email: ahimes1@cnm.edu" << endl;
    cout << "Title: Space Travel" << endl;
    cout << "Objective: Calculate weight on other planets and how long trips to them would take" << endl;
    
    cout.precision(2);
    cout.setf(ios::showpoint | ios::fixed);
    
    string inputName, answer;
    int choice = 0;
	float rate, weight, time, pWeight = 0;
    bool repeat, again, menu = false;
    vector<string> planets;
    
    planets.push_back("Mercury");
    planets.push_back("Venus");
    planets.push_back("Earth");
    planets.push_back("Mars");
    planets.push_back("Jupiter");
    planets.push_back("Saturn");
    planets.push_back("Uranus");
    planets.push_back("Neptune");
	planets.push_back("Neither");
    
    do {
		while (menu == false) {
			repeat = false;
			cout << "\nWhat is your name? ";
			inputName = name(); //used a function instead in case of problems with getline() causing infinite loops etc.

			cout << "I don't mean to be rude, " << inputName << ", but how much do you weigh (lbs)? ";
			cin >> weight;
			clear();
			cout << "If you were to travel through space, how fast (MPH) would you go? ";
			cin >> rate;
			clear();
        
			cout << "\nWhich planet would you like to travel to?" << endl;
			cout << "1: " << setw(8) << planets.at(0) << endl;
			cout << "2: " << setw(8) << planets.at(1) << endl;
			cout << "3: " << setw(8) << planets.at(2) << endl;
			cout << "4: " << setw(8) << planets.at(3) << endl;
			cout << "5: " << setw(8) << planets.at(4) << endl;
			cout << "6: " << setw(8) << planets.at(5) << endl;
			cout << "7: " << setw(8) << planets.at(6) << endl;
			cout << "8: " << setw(8) << planets.at(7) << endl;
			cout << "9: " << setw(7) << planets.at(8) << "!" << endl;
			cin >> choice;
			clear();

			time = planetTime(choice, rate);
			pWeight = planetWeight(choice, weight); 
        
			if (choice == 9) {
				cout << "\n" << planets.at(8) << " would I!" << endl;
				menu = true; //escape the "menu" while loop
			}
			else if (choice == 3) {
				cout << "\nYou're already there, silly!" << endl;
				menu = true;
			}
			else if (choice >= 1 && choice <= 8) {
				cout << "\nIt would take " << time << " hours (which would be " << time / 24 << " days, or " << time / 24 / 365.25 << " Earth years) to get to " << planets.at(choice-1) << " while traveling " << rate << " MPH." << endl;
				cout << "\nOnce you get there, " << inputName << ", you will weigh " << pWeight << " pounds, instead of the " << weight << " pounds you would weigh on Earth." << endl;
				menu = true;
			}
			else 
				cout << "\nInvalid entry, please try again." << endl;
        
			while (repeat == false) {
				answer = another(inputName);
				if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "Y" || answer == "y") {
					menu = false; //re-initialize "menu"
					repeat = true;
				}
				else if (answer == "no" || answer == "No" || answer == "NO" || answer == "N" || answer == "n") {
					repeat = true; 
					again = true; //escape repeat and again loops, proceed to end of program
				}
				else {
					cout << "\nInvalid entry, please try again" << endl;
					continue; //begin "repeat" loop again
				}
			}
		}
    } while (again == false);
	cout << "Bye!" << endl;
    return 0;
}

string name() {
	string user;
	getline(cin, user);
	return user;
}

float planetTime(int choice, float rate) {
	vector<float> distance; //from sun, millions of miles

	distance.push_back(36);
    distance.push_back(67);
    distance.push_back(93);
    distance.push_back(141);
    distance.push_back(483);
    distance.push_back(886);
    distance.push_back(1782);
    distance.push_back(2793);
	distance.push_back(0); //Added a 9th vector element because something had to exist in case the user chose "9". Same for the "gravity" vector in the planetWeight function.

    choice = choice - 1;
    float time;

    time = abs(distance.at(2) - distance.at(choice)) / rate; //Earth's distance from the sun - other planet's distance / rate
    return time * 1000000;
}


float planetWeight(int choice, float weight) {
	vector<float> gravity; //compared to Earth

	gravity.push_back(0.27);
    gravity.push_back(0.86);
    gravity.push_back(1.00);
    gravity.push_back(0.37);
    gravity.push_back(2.64);
    gravity.push_back(1.17);
    gravity.push_back(0.92);
    gravity.push_back(1.44);
	gravity.push_back(0);

    choice = choice - 1;

    weight = gravity.at(choice) * weight;
    return weight;
}


string another(string inputName) {
    string again;
    cout << "\nWould you care for some more space math, " << inputName << "? (yes/no): ";
    getline(cin, again);
    return again;
}


void clear () {
    cin.clear();
    cin.ignore();
}