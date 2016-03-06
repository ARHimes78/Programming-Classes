//Alan Himes
//ahimes1@cnm.edu
//primeshift.h

#ifndef _PRIMESHIFT_H
#define _PRIMESHIFT_H
#include "enigma.h"

#include <iostream>
#include <random>
#include <string>

using namespace std;

class Primeshift : public Enigma {
	private:
		string savedMessage;//This is a work-around.
		string savedCodedMessage;
    protected:
        int key;
        string message, codedMessage;
        default_random_engine e;
        void Encode();
        void Decode();
    public:
        Primeshift();
        void SetMessage(string msg);
        void SetMessage(string msg, int k);
        void SetCodedMessage(string codedMsg, int k);
		/*Because message and codedMessage get manipulated so much, 
		the return methods will return stored variables instead.
		*/
        string GetCodedMessage() {return savedCodedMessage;}
        string GetDecodedMessage() {return savedMessage;}
        int GetKey() {return key;}
};

#endif