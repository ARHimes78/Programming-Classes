#ifndef _SIMPLECALC_H
#define _SIMPLECALC_H
#include <iostream>
#include <string>

using namespace std;

class SimpleCalc {
	private:
		char operation;
		double operand1, operand2, answer;
		string results;

	public:
		SimpleCalc(); //constructor
		void SetOperation(char operation, double operand1, double operand2);
		string GetResults() {return results;}
		double GetAnswer() {return answer;}
};

#endif