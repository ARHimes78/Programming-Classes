//Alan Himes, ahimes1@cnm.edu, mortgagecalculator.cpp


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>


using namespace std;


void header();
double AskForPrin();
double AskInterest();
int AskYears();
bool Validate(double principal, double interest, int years);
string MortCalc(double principal, double interest, int years);
string another();
void clear();


int main() {
    header();
    
    double principal, interest;
    int years;
    string result;
    bool check;
    bool repeat = true;
    string answer;
    do {
        bool again = true;
        cout << "\n";
        principal = AskForPrin();
        interest = AskInterest();
        years = AskYears();
        
        check = Validate(principal, interest, years);
        if (check == false)
            cout << "One or more entries were invalid, please try again." << endl;
        else {
            result = MortCalc(principal, interest, years);
            cout << result;
            while (again == true) {
                answer = another();
                if (answer == "YES" || answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y")
                    again = false;
                else if (answer == "NO" || answer == "No" || answer == "no" || answer == "N" || answer == "n") {
                    repeat = false;
                    break;
                }
                else
                    cout << "Invalid response, please try again." << endl;
            }
        }
    } while (repeat == true);
    cout << "Bye!" << endl;
    return 0;
}


void header() {
    cout << "Name: Alan Himes" << endl;
    cout << "Title: Mortgage Calculator" << endl;
    cout << "Objective: Calculate mortgage payment" << endl;
}


double AskForPrin() {
    double principal;
    cout << "What is the amount borrowed ($500,000.00 max)? " << endl;
    cin >> principal;
    clear();
    return principal;
}


double AskInterest() {
    double interest;
    cout << "What is the annual interest rate? Please enter the percentage (10% max). " << endl;
    cin >> interest;
    clear();
    return interest;
}


int AskYears() {
    int years;
    cout << "What is the number of years on the loan (15, 25 or 30)? " << endl;
    cin >> years;
    clear();
    return years;
}


bool Validate(double principal, double interest, int years) {
    if ((principal > 0 && principal <= 500000) && (interest > 0 && interest <= 10) && (years == 15 || years == 25 || years == 30))
        return true;
    else
        return false;
}


string MortCalc(double principal, double interest, int years) {
    interest = interest/100; //to change passed interest value into decimal form
    double monthly;
    double numerator;
    double denominator;
    double totalLoan;
    double totalInterest;
    stringstream ss;
    string result;
    
    ss.setf(ios::fixed);
    ss.precision(2);
    /*Using formula from assignment description. It happens in this order:
    Multiply principal by interest, assign to numerator variable.
    Divide interest by 12, add 1, apply the power of years times 12, 
    divide by 1 (beacuse of the negative exponent -nq), subtract from 1, multiply by 12,
    assign to denominator variable.
    Divide numerator by denominator and assign to monthly.
    Tested results with www.mortgagecalculator.org with property tax and PMI set to zero
    and credit set to "excellent".*/
    
    numerator = principal*interest;
    denominator = 12*(1-(1/(pow((1+(interest/12)), years*12))));
    monthly = numerator/denominator;
    totalLoan = monthly*years*12;
    totalInterest = totalLoan-principal;
    
    ss << "\nThe principal loan is $" << principal << ".\n";
    ss.precision(0);
    ss << "The annual interest is " << interest*100 << "%.\n"; //showing interest in percent form
    ss << "The amount of years for the loan is " << years << ".\n";
    ss.precision(2);
    ss << "The monthly payment amount is $" << monthly << ".\n";
    ss << "The total loan is $" << totalLoan << ".\n";
    ss << "The total interest is $" << totalInterest << ".\n\n";
    result = ss.str();
    return result;
    
    /*I was going to use this one from the Internet, but 
    discovered it's actually the same as the formula from the assignment:
    numerator = principal*(interest/12)*pow((1+(interest/12)), years*12);
    denominator = (pow((1+(interest/12)), years*12)) - 1;
    monthly = numerator/denominator;*/
}


string another() {
    string response;
    cout << "Would you like to calculate another mortgage (yes/no)?" << endl;
    getline(cin, response);
    return response;
}


void clear() {
    cin.ignore();
    cin.clear();
}