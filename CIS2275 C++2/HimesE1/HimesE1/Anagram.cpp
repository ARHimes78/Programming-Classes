#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
 
using namespace std;

void header() {
	cout << "Name: Alan Himes" << endl;
	cout << "Title: Anagram" << endl;
	cout << "Objective: Compare two words (or sets of words) to determine if one is an anagram of the other\n\n" << endl;
}
 
bool IsAnagram(string wordA, string wordB) {
	int i, j;
	int match = 0;
	int lengthA = wordA.length();
	int lengthB = wordB.length();
	char temp;
	stringstream ssA, ssB;

	/*Creating stringstreams consisting of only lowercase letters from the strings.
	Used a char variable, "temp", to avoid ASCII numbers instead of letters being 
	added to the stringstreams.*/
	for (i=0; i<lengthA; i++) {
		if ((wordA[i] >= 'A' && wordA[i] <= 'Z') || (wordA[i] >= 'a' && wordA[i] <= 'z')) {
			temp = tolower(wordA[i]);//in case there's a capital letter in one of the words.
			ssA << temp;
		}
	}
		
	for (i=0; i<lengthB; i++) {
		if ((wordB[i] >= 'A' && wordB[i] <= 'Z') || (wordB[i] >= 'a' && wordB[i] <= 'z')) {
			temp = tolower(wordB[i]);
			ssB << temp;
		}
	}
		
	/*Creating strings from the stringstreams with the goal of alphabetizing
	all of their letters.*/
	string noSpacesAbcA = ssA.str(); 
	string noSpacesAbcB = ssB.str();
	
	//Re-assigning lengthA to the "lowercase, no spaces" version of the strings.
	lengthA = noSpacesAbcA.length(); 
	lengthB = noSpacesAbcB.length();
	
	/*If the total amount of letters of one string exceeds another, an anagram
	is impossible.*/
	if (lengthA != lengthB)
		return false;
	
	/*Using the bubble sort method to create alphabetized versions of both strings.
	The bubble sort places lower values before higher values and repeats this process
	as many times as there are array elements (minus 1).*/
	for (i=0; i<lengthA - 1; i++) {
		for (j=1; j<lengthA; j++) { 
			if (noSpacesAbcA[j - 1] > noSpacesAbcA[j]) {
				temp = noSpacesAbcA[j];
				noSpacesAbcA[j] = noSpacesAbcA[j - 1];
				noSpacesAbcA[j - 1] = temp;
			}
		}
	}
			
	for (i=0; i<lengthA - 1; i++) {
		for (j=1; j<lengthA; j++) {
			if (noSpacesAbcB[j - 1] > noSpacesAbcB[j]) {
				temp = noSpacesAbcB[j];
				noSpacesAbcB[j] = noSpacesAbcB[j - 1];
				noSpacesAbcB[j - 1] = temp;
			}
		}
	}
	
	for (i=0; i<lengthA; i++) {
	/*if lowercase, no spaces, alphabetized versions of both strings are identical,
	one is an anagram of the other.*/
		if (noSpacesAbcA[i] == noSpacesAbcB[i])
			match++;
	}
	
	if (match == lengthA) 
		return true;
	else
		return false;
}
 
bool another() {
	string answer;
 
	cout << "\nAgain? (y/n): ";
	getline(cin, answer);
	
	if (tolower(answer[0]) == 'y')
		return true;
	else
		return false;
}