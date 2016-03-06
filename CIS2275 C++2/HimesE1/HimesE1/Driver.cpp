//Alan Himes, ahimes1@cnm.edu, driver.cpp, anagram.cpp, anagram.h
 
#include <iostream>
#include <string>
#include "anagram.h"
 
using namespace std;
 
int main() {
	header();
	
	string wordA, wordB = "";
	bool again;
	bool bAnagram;
 
	do {
		cout << "Enter the first word: ";
		getline(cin, wordA);
		cout << "Enter the second word: ";
		getline(cin, wordB);
		
		bAnagram = IsAnagram(wordA, wordB);
 
		if (bAnagram)
			cout << "\n\"" << wordA << "\" is an anagram of \"" << wordB << "\"." << endl;
		else
			cout << "\n\"" << wordA << "\" is not an anagram of \"" << wordB << "\"." << endl;
 
		again = another();
	} while (again);
	
	cout << "\nBye!" << endl;
	return 0;
}