//Alan Himes
//ahimes1@cnm.edu
//enigma.cpp

#include "stdafx.h"
#include <iostream>
#include <random>
#include <string>
#include "primeshift.h"

using namespace std;

Primeshift::Primeshift() {
    //calling base constructor
}

void Primeshift::SetMessage(string msg) {
    message = msg;
	savedMessage = msg;
    Enigma::SetMessage(message);
    key = Enigma::GetKey();
    Encode();
}

void Primeshift::SetMessage(string msg, int k) {
    message = msg;
	savedMessage = msg;
    key = k;
    Enigma::SetMessage(message, key);
    Encode();
}

void Primeshift::SetCodedMessage(string codedMsg, int k) {
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

void Primeshift::Encode() {
    message = Enigma::GetCodedMessage();
    
    //Changing all the characters in message to their shift/nonshift value.
    
    //escaped the backslash and quotation mark
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
    
    /*ensure codedMessage contains same amount of characters as message
    and keeps shift change.*/
    codedMessage = message;
    
    //Creating an array of prime numbers
    int primes[22];
    int count = 0;
    int num = 32;//starting with 32 because it is the lowest
    
    /*will iterate 21 times to get the range of prime numbers needed, including the
    two prime numbers after 126.
    */
    while (count < 22) {
        bool bPrime = true;
        
        /*checks to see if every number up to half of num is divisible.
        If so, the number isn't prime, and the loop breaks.
        */ 
        for (int i=2; i<=num / 2; ++i) {
            if (num % i == 0) {
                bPrime = false;
                break;
            }
        }
        
        /*if the number in question made it past the for loop, it is prime,
        and is added to the array.
        */
        if (bPrime) {
            primes[count] = num;
            ++count;
        }
        
        ++num;
    }
    
    for (int unsigned i=0; i<message.size(); ++i) {
        int ascii = static_cast<int>(message[i]);
        
        //check for prime, if found shift one prime ahead or wraparound
        for (int unsigned j=0; j<22; ++j) {
            if (ascii == primes[j]) {
                //check if key is prime.
                bool keyPrime = true;
                
                for (int k=2; k<key/2; ++k) {
                    if (key % k == 0) {
                        keyPrime = false;
                        break;
                    }
                }
                
                if (keyPrime) {
                    if (primes[j+1] > 126) {
                        codedMessage[i] = (char)primes[0];
                    }
                    else {
                        codedMessage[i] = (char)primes[j+1];
                        break;//because next iteration is j+1!
                    }
                }
                
                //check if key is even.
                else if (key % 2 == 0) {
                    if (primes[j+2] > 126) {
                        //index 18 of the array is the last prime # before 126.
                        codedMessage[i] = (char)primes[(j+2)-19];
                    }
                    else {
                        codedMessage[i] = (char)primes[j+2];
                        break;
                    }
                }
                else {//key isn't prime or even
                    if (primes[j+3] > 126) {
                        codedMessage[i] = (char)primes[(j+3)-19];
                    }
                    else {
                        codedMessage[i] = (char)primes[j+3];
                    }
                }
            }
        }     
    }
    savedCodedMessage = codedMessage;
}

void Primeshift::Decode() {
    //ensure message contains same amount of characters as codedMessage
    message = codedMessage;
    
    //Same procedure as the prime array creator used in Encode().
    int primes[22];
    int count = 0;
    int num = 23;//starting from 23 because it's 3 prime numbers below 32
    
    
    
    while (count < 22) {
        bool bPrime = true;
        
        for (int i=2; i<=num / 2; ++i) {
            if (num % i == 0) {
                bPrime = false;
                break;
            }
        }
        
        if (bPrime) {
            primes[count] = num;
            ++count;
        }
        
        ++num;
    }
    
    for (int unsigned i=0; i<codedMessage.size(); ++i) {
        int ascii = static_cast<int>(codedMessage[i]);
        
        //check for prime, if found shift one prime ahead or wraparound
        for (int unsigned j=0; j<22; ++j) {
            if (ascii == primes[j]) {
                //check if key is prime.
                bool keyPrime = true;
                
                for (int k=2; k<key/2; ++k) {
                    if (key % k == 0) {
                        keyPrime = false;
                        break;
                    }
                }
                
                if (keyPrime) {
                    if (primes[j-1] < 32) {
                        message[i] = (char)primes[21];
                    }
                    else {
                        message[i] = (char)primes[j-1];
                        break;
                    }
                }
                
                //check if key is even.
                else if (key % 2 == 0) {
                    if (primes[j-2] < 32) {
                        message[i] = (char)primes[(j-2)+19];
                    }
                    else {
                        message[i] = (char)primes[j-2];
                        break;
                    }
                }
                else {//key isn't prime or even
                    if (primes[j-3] < 32) {
                        message[i] = (char)primes[(j-3)+19];
                    }
                    else {
                        message[i] = (char)primes[j-3];
                    }
                }
            }
        }     
    }
    
    //Removing the shift change
    
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
    
}