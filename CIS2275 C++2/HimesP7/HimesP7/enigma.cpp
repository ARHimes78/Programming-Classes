//Alan Himes
//ahimes1@cnm.edu
//enigma.cpp

#include "stdafx.h"
#include <iostream>
#include <random>
#include <string>
#include "enigma.h"

using namespace std;

Enigma::Enigma() {
    key = 1;
    message = "";
    codedMessage = "";
    random_device rnd;
    e.seed(rnd());
}

void Enigma::SetMessage(string msg) {
    message = msg;
    
    uniform_int_distribution<int> d(1, 50);
    key = d(e);
    
    Encode();
}

void Enigma::SetMessage(string msg, int k) {
    message = msg;
    key = k;
    
    Encode();
}

void Enigma::SetCodedMessage(string codedMsg, int k) {
    codedMessage = codedMsg;
    key = k;
    if (key < 1 || key > 50)
        key = 1;
    
    Decode();
}

void Enigma::Encode() {
    //to ensure codedMessage has the same amount of "array elements" as message.
    codedMessage = message;
    
    for (int unsigned i=0; i<message.size(); ++i) {
        int ascii = static_cast<int>(message[i]);
        if(ascii + key > 126) {
            ascii = ((ascii + key) - 126) + 31;
        }
        else
            ascii += key;
            
        codedMessage[i] = (char)ascii;
    }
}

void Enigma::Decode() {
    //to ensure message has the same amount of "array elements" as codedMessage.
    message = codedMessage;
    
    for (int unsigned i=0; i<codedMessage.size(); ++i) {
        int ascii = static_cast<int>(codedMessage[i]);
        if(ascii - key < 32) {
            ascii = 127 - (32 - (ascii - key));
        }
        else
            ascii -= key;
            
        message[i] = (char)ascii;
    }
}