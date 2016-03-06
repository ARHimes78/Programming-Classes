//Alan Himes
//ahimes1@cnm.edu
//enigma.h

#ifndef _ENGIMA_H
#define _ENIGMA_H

#include <iostream>
#include <random>
#include <string>

using namespace std;

class Enigma {
    private:
        int key;
        string message, codedMessage;
        default_random_engine e;
        void Encode();
        void Decode();
    public:
        Enigma();
        void SetMessage(string msg);
        void SetMessage(string msg, int k);
        void SetCodedMessage(string codedMsg, int k);
        string GetCodedMessage() {return codedMessage;}
        string GetDecodedMessage() {return message;}
        int GetKey() {return key;}
};

#endif