//Alan Himes
//ahimes1@cnm.edu
//enigma.cpp

#include "stdafx.h"
#include <iostream>
#include <random>
#include <string>
#include "qwerty.h"

using namespace std;

Qwerty::Qwerty() {
    //calling base constructor
}

void Qwerty::SetMessage(string msg) {
    message = msg;
	savedMessage = msg;
    Enigma::SetMessage(message);
    key = Enigma::GetKey();
    Encode();
}

void Qwerty::SetMessage(string msg, int k) {
    message = msg;
	savedMessage = msg;
    key = k;
    Enigma::SetMessage(message, key);
    Encode();
}

void Qwerty::SetCodedMessage(string codedMsg, int k) {
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

void Qwerty::Encode() {
    message = Enigma::GetCodedMessage();
    
    //ensure codedMessage contains same amount of characters as message
    codedMessage = message;
    
    for (int unsigned i = 0; i<message.size(); ++i) {
        switch(message[i]) {
            case 'q':
                codedMessage[i] = 'a';
                break;
            case 'a':
                codedMessage[i] = 'z';
                break;
            case 'z':
                codedMessage[i] = 'q';
                break;
            case 'w':
                codedMessage[i] = 's';
                break;
            case 's':
                codedMessage[i] = 'x';
                break;
            case 'x':
                codedMessage[i] = 'w';
                break;
            case 'e':
                codedMessage[i] = 'd';
                break;
            case 'd':
                codedMessage[i] = 'c';
                break;
            case 'c':
                codedMessage[i] = 'e';
                break;
            case 'r':
                codedMessage[i] = 'f';
                break;
            case 'f':
                codedMessage[i] = 'v';
                break;
            case 'v':
                codedMessage[i] = 'r';
                break;
            case 't':
                codedMessage[i] = 'g';
                break;
            case 'g':
                codedMessage[i] = 'b';
                break;
            case 'b':
                codedMessage[i] = 't';
                break;
            case 'y':
                codedMessage[i] = 'h';
                break;
            case 'h':
                codedMessage[i] = 'n';
                break;
            case 'n':
                codedMessage[i] = 'y';
                break;
            case 'u':
                codedMessage[i] = 'j';
                break;
            case 'j':
                codedMessage[i] = 'm';
                break;
            case 'm':
                codedMessage[i] = 'u';
                break;
            case 'i':
                codedMessage[i] = 'k';
                break;
            case 'k':
                codedMessage[i] = 'i';
                break;
            case 'o':
                codedMessage[i] = 'l';
                break;
            case 'l':
                codedMessage[i] = 'o';
                break;
            case 'Q':
                codedMessage[i] = 'A';
                break;
            case 'A':
                codedMessage[i] = 'Z';
                break;
            case 'Z':
                codedMessage[i] = 'Q';
                break;
            case 'W':
                codedMessage[i] = 'S';
                break;
            case 'S':
                codedMessage[i] = 'X';
                break;
            case 'X':
                codedMessage[i] = 'W';
                break;
            case 'E':
                codedMessage[i] = 'D';
                break;
            case 'D':
                codedMessage[i] = 'C';
                break;
            case 'C':
                codedMessage[i] = 'E';
                break;
            case 'R':
                codedMessage[i] = 'F';
                break;
            case 'F':
                codedMessage[i] = 'V';
                break;
            case 'V':
                codedMessage[i] = 'R';
                break;
            case 'T':
                codedMessage[i] = 'G';
                break;
            case 'G':
                codedMessage[i] = 'B';
                break;
            case 'B':
                codedMessage[i] = 'T';
                break;
            case 'Y':
                codedMessage[i] = 'H';
                break;
            case 'H':
                codedMessage[i] = 'N';
                break;
            case 'N':
                codedMessage[i] = 'Y';
                break;
            case 'U':
                codedMessage[i] = 'J';
                break;
            case 'J':
                codedMessage[i] = 'M';
                break;
            case 'M':
                codedMessage[i] = 'U';
                break;
            case 'I':
                codedMessage[i] = 'K';
                break;
            case 'K':
                codedMessage[i] = 'I';
                break;
            case 'O':
                codedMessage[i] = 'L';
                break;
            case 'L':
                codedMessage[i] = 'O';
                break;
            default:
                break;
        }  
    }
	savedCodedMessage = codedMessage;
}

void Qwerty::Decode() {
    //ensure message contains same amount of characters as codedMessage
    message = codedMessage;
    
    for (int unsigned i = 0; i<message.size(); ++i) {
        switch(codedMessage[i]) {
            case 'a':
                message[i] = 'q';
                break;
            case 'z':
                message[i] = 'a';
                break;
            case 'q':
                message[i] = 'z';
                break;
            case 's':
                message[i] = 'w';
                break;
            case 'x':
                message[i] = 's';
                break;
            case 'w':
                message[i] = 'x';
                break;
            case 'd':
                message[i] = 'e';
                break;
            case 'c':
                message[i] = 'd';
                break;
            case 'e':
                message[i] = 'c';
                break;
            case 'f':
                message[i] = 'r';
                break;
            case 'v':
                message[i] = 'f';
                break;
            case 'r':
                message[i] = 'v';
                break;
            case 'g':
                message[i] = 't';
                break;
            case 'b':
                message[i] = 'g';
                break;
            case 't':
                message[i] = 'b';
                break;
            case 'h':
                message[i] = 'y';
                break;
            case 'n':
                message[i] = 'h';
                break;
            case 'y':
                message[i] = 'n';
                break;
            case 'j':
                message[i] = 'u';
                break;
            case 'm':
                message[i] = 'j';
                break;
            case 'u':
                message[i] = 'm';
                break;
            case 'i':
                message[i] = 'k';
                break;
            case 'k':
                message[i] = 'i';
                break;
            case 'o':
                message[i] = 'l';
                break;
            case 'l':
                message[i] = 'o';
                break;
            case 'A':
                message[i] = 'Q';
                break;
            case 'Z':
                message[i] = 'A';
                break;
            case 'Q':
                message[i] = 'Z';
                break;
            case 'S':
                message[i] = 'W';
                break;
            case 'X':
                message[i] = 'S';
                break;
            case 'W':
                message[i] = 'X';
                break;
            case 'D':
                message[i] = 'E';
                break;
            case 'C':
                message[i] = 'D';
                break;
            case 'E':
                message[i] = 'C';
                break;
            case 'F':
                message[i] = 'R';
                break;
            case 'V':
                message[i] = 'F';
                break;
            case 'R':
                message[i] = 'V';
                break;
            case 'G':
                message[i] = 'T';
                break;
            case 'B':
                message[i] = 'G';
                break;
            case 'T':
                message[i] = 'B';
                break;
            case 'H':
                message[i] = 'Y';
                break;
            case 'N':
                message[i] = 'H';
                break;
            case 'Y':
                message[i] = 'N';
                break;
            case 'J':
                message[i] = 'U';
                break;
            case 'M':
                message[i] = 'J';
                break;
            case 'U':
                message[i] = 'M';
                break;
            case 'I':
                message[i] = 'K';
                break;
            case 'K':
                message[i] = 'I';
                break;
            case 'O':
                message[i] = 'L';
                break;
            case 'L':
                message[i] = 'O';
                break;
            default:
                break;
        }  
    }
}