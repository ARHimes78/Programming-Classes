//Alan Himes, ahimes1@cnm.edu, driver.cpp, simplecalc.cpp, simplecalc.h
#include <iostream>
#include <string>
#include "simplecalc.h"

using namespace std;

int main() {
	header();

	char oper;
	double op1, op2;
	string yOrN;//yes or no

	cout << "***WELCOME TO CALCULATOR!***\n" << endl;

	bool again;
	do {
		SimpleCalc calc;
		//constructor re-initializes the variables with each loop
		
		cout << "Enter the first number: ";
		cin >> op1;
		cout << "Would you like to add, subtract, multiply or divide"
			<< " (enter +, -, * or /)?: ";
		cin >> oper;
		cout << "Enter the second number: ";
		cin >> op2;
		calc.SetOperation(oper, op1, op2);
		cout << "\n" << calc.GetResults() << endl;
		//the returned string "results" is displayed from the GetResults() method.
		
		cout << "\nAgain? ";
		clear();
		getline(cin, yOrN);
		
		if (tolower(yOrN[0]) == 'y')
			again = true;
		else
			again = false;
	} while (again);

	cout << "Bye!" << endl;
	return 0;
}