//Alan Himes
//ahimes1@cnm.edu
//enigma.cpp

#include "stdafx.h"
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include "shifty.h"

using namespace std;

Shifty::Shifty() {
    //calling base constructor
}

void Shifty::SetMessage(string msg) {
    message = msg;
	savedMessage = msg;
    Enigma::SetMessage(message);
    key = Enigma::GetKey();
    Encode();
}

void Shifty::SetMessage(string msg, int k) {
    message = msg;
	savedMessage = msg;
    key = k;
    Enigma::SetMessage(message, key);
    Encode();
}

void Shifty::SetCodedMessage(string codedMsg, int k) {
    codedMessage = codedMsg;
	savedCodedMessage = codedMsg;
    key = k;
    Decode();
    
    /*message is being passed instead of codedMessage.
    Decode() took the fully encoded message and removed the 
    "inherited" encoding for MORE decoding in the base class.
    */ 
    Enigma::SetCodedMessage(message, key);
    
    /*Now that the message has been FULLY decoded, it is returned
    to the inherited class.
    */
    message = Enigma::GetDecodedMessage();
	savedMessage = message;
}

void Shifty::Encode() {
    message = Enigma::GetCodedMessage();
    
    codedMessage = "";
    
    string nonShift = "zxcvbnm,./asdfghjkl;'qwertyuiop[]\\1234567890-=";
    string shift = "ZXCVBNM<>?ASDFGHJKL:\"QWERTYUIOP{}|!@#$%^&*()_+";
    
    for (int unsigned i=0; i<message.size(); ++i) {
        for (int unsigned j=0; j<nonShift.size(); ++j) {
            if (message[i] == nonShift[j])
                message[i] = shift[j];
            else if (message[i] == shift[j])
                message[i] = nonShift[j];
        }
    }
    
    int ascii;
    int threeDigitNums;
    stringstream ssHugeNumber;
    
    for (int unsigned i=0; i<message.size(); ++i) {
        ascii = static_cast<int>(message[i]);
        threeDigitNums = 1000 - ascii;
        ssHugeNumber << threeDigitNums;
    }
    
    string hugeNumber = ssHugeNumber.str();
    
    //Using the shift arrays again to change the numbers to their shift-numbers
    for (int unsigned i=0; i<hugeNumber.size(); ++i) {
        for (int unsigned j=34; j<nonShift.size(); ++j) {
            if (hugeNumber[i] == nonShift[j])
                hugeNumber[i] = shift[j];
        }
    }
    
    codedMessage = hugeNumber;
	savedCodedMessage = codedMessage;
}

void Shifty::Decode() {
    message = "";
    
    string nonShift = "zxcvbnm,./asdfghjkl;'qwertyuiop[]\\1234567890-=";
    string shift = "ZXCVBNM<>?ASDFGHJKL:\"QWERTYUIOP{}|!@#$%^&*()_+";
    
    int counter = 0;
    int digit;
    int ascii;
    int threeDigits[3] = {0,0,0};
    stringstream ssAscii;
    
    for (int unsigned i=0; i<codedMessage.size(); ++i) {
        //unshifting the "shift-number keys"
        for (int unsigned j=34; j<45; ++j) {
            if (codedMessage[i] == shift[j])
                codedMessage[i] = nonShift[j];
        }
        
        //subtracting the values by 48 gets numbers 0-9.
        digit = codedMessage[i] - 48;
        
        //Creating a 3-element array with each 3-number group one at a time
        threeDigits[counter] = digit;
        
        ++counter;
        
        if (counter == 3) {
            
            for (int k=0; k<3; ++k)
                ascii = (100*threeDigits[0]) + (10*threeDigits[1]) + (threeDigits[2]);
                ascii = 1000-ascii;
                ssAscii << (char)ascii;
            
            counter = 0;
        }
    }
    
    message = ssAscii.str();
    
    //un-shifting/shifting the characters.
    for (int unsigned i=0; i<message.size(); ++i) {
        for (int unsigned j=0; j<nonShift.size(); ++j) {
            if (message[i] == nonShift[j])
                message[i] = shift[j];
            else if (message[i] == shift[j])
                message[i] = nonShift[j];
        }
    }
}