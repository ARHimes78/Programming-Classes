#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>
#include "simplecalc.h"

using namespace std;

//Alan Himes, ahimes1@cnm.edu, Form1.h, simplecalc.cpp, simplecalc.h

SimpleCalc::SimpleCalc() {
	operation = 0; //ascii null
	operand1, operand2, answer = 0.0;
	results = "";
}

void SimpleCalc::SetOperation(char operation, double operand1, double operand2) {
	stringstream ssAnswer;
	//ssAnswer will be created according to the condition and placed into "result".

	//if, else if below depending on the operator chosen
	if (operation == '+') {
		answer = operand1 + operand2;
		ssAnswer << "Your operation is addition: "
			<< operand1 << " " << operation << " "
			<< operand2 << " = " << answer;
	}
	else if (operation == '-') {
		answer = operand1 - operand2;
		ssAnswer << "Your operation is subtraction: "
			<< operand1 << " " << operation << " "
			<< operand2 << " = " << answer;
	}
	else if (operation == '*') {
		answer = operand1 * operand2;
		ssAnswer << "Your operation is multiplication: "
			<< operand1 << " " << operation << " "
			<< operand2 << " = " << answer;
	}
	else if (operation == '/' && operand2 == 0)
	/*Checks "divided by zero" before normal division.
	If this was below the "normal division" it would
	never be checked.*/
		ssAnswer << "Illegal Operation!";
	else if (operation == '/') {
		answer = operand1 / operand2;
		ssAnswer << "Your operation is division: "
			<< operand1 << " " << operation << " "
			<< operand2 << " = " << answer;
	}
	else
	//if anything other than +, -, * or / is input as the operator
		ssAnswer << "You did not enter a valid operator!";

	results = ssAnswer.str();
}