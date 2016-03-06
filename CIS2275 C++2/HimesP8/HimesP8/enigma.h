//Alan Himes
//ahimes1@cnm.edu
//enigma.h

#ifndef _ENIGMA_H
#define _ENIGMA_H

#include <iostream>
#include <random>
#include <string>

using namespace std;

class Enigma {
    protected:
        int key;
        string message, codedMessage;
        default_random_engine e;
        void Encode();
        void Decode();
    public:
        Enigma();
        virtual void SetMessage(string msg);
        virtual void SetMessage(string msg, int k);
        virtual void SetCodedMessage(string codedMsg, int k);
        virtual string GetCodedMessage() {return codedMessage;}
        virtual string GetDecodedMessage() {return message;}
        virtual int GetKey() {return key;}
};

#endif