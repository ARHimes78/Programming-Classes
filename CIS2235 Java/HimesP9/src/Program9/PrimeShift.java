//Alan Himes
//ahimes1@cnm.edu
//Program 9 Enigma with Polymorphism
//CIS2235
//File: MainP9.java, EnigmaFrame.java, EnigmaClass.java, EnigmaInterface.java, PrimeShift.java, Qwerty.java, Alternate.java

package Program9;

/**
 *
 * @author ahimes1
 */
public class PrimeShift extends EnigmaClass {
    
    public PrimeShift(){
        //calling superclass constructor
    }
    
    protected void encode() {
        message = encMessage;//pass on result of superclass encode()
        encMessage = "";
        
        //Creating an array of prime numbers
        int[] primes = new int[22];
    
        int count = 0;
        int num = 32;//starting with 32 because it is the lowest
    
        /*will iterate 21 times to get the range of prime numbers needed, including the
        two prime numbers after 126.
        */
        while (count < 22) {
            boolean bPrime = true;
        
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
    
        for (int i=0; i<message.length(); ++i) {
            int ascii = (int)message.charAt(i);
            boolean bPrimeShift = false;//set to true if prime character detected
        
            //check for prime, if found shift one prime ahead or wraparound
            for (int j=0; j<22; ++j) {
                if (ascii == primes[j]) {
                    bPrimeShift = true;
                    //check if key is prime.
                    boolean keyPrime = true;
            
                    for (int k=2; k<key/2; ++k) {
                        if (key % k == 0) {
                            keyPrime = false;
                            break;
                        }
                    }

                    if (keyPrime) {
                        if (primes[j+1] > 126) {
                            encMessage += (char)primes[0];
                        }   
                        else {
                            encMessage += (char)primes[j+1];
                            break;//because next iteration is j+1!
                            
                        }
                    }
                
                    //check if key is even.
                    else if (key % 2 == 0) {
                        if (primes[j+2] > 126) {
                            //index 18 of the array is the last prime # before 126.
                            encMessage += (char)primes[(j+2)-19];
                        }
                        else {
                            encMessage += (char)primes[j+2];
                            break;
                        }
                    }
                    else {//key isn't prime or even
                        if (primes[j+3] > 126) {
                            encMessage += (char)primes[(j+3)-19];
                        }
                        else {
                            encMessage += (char)primes[j+3];
                        }
                    }
                }
            }
            if (!bPrimeShift) {
                encMessage += (char)ascii;
            }
        }
        
    }
    
    protected void decode() {
        message = "";
        
        //Same procedure as the prime array creator used in Encode().
        int[] primes = new int[22];
        int count = 0;
        int num = 23;//starting from 23 because it's 3 prime numbers below 32
    
        while (count < 22) {
            boolean bPrime = true;
        
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
    
        for (int i=0; i<encMessage.length(); ++i) {
            int ascii = (int)encMessage.charAt(i);
            boolean bPrimeShift = false;//set to true if prime character detected
            
            //check for prime, if found shift one prime ahead or wraparound
            for (int j=0; j<22; ++j) {
                if (ascii == primes[j]) {
                    bPrimeShift = true;
                    //check if key is prime.
                    boolean keyPrime = true;
                
                    for (int k=2; k<key/2; ++k) {
                        if (key % k == 0) {
                            keyPrime = false;
                            break;
                        }
                    }
                
                    if (keyPrime) {
                        if (primes[j-1] < 32) {
                            message += (char)primes[21];
                        }
                        else {
                            message += (char)primes[j-1];
                            break;
                        }
                    }
                
                    //check if key is even.
                    else if (key % 2 == 0) {
                        if (primes[j-2] < 32) {
                            System.out.println("j = " + j);
                            message += (char)primes[(j-2)+19];
                        }
                        else {
                            message += (char)primes[j-2];
                            break;
                        }
                    }
                    else {//key isn't prime or even
                        if (primes[j-3] < 32) {
                            message += (char)primes[(j-3)+19];
                        }
                        else {
                            message += (char)primes[j-3];
                        }
                    }
                }
            }
            if (!bPrimeShift)
                message += (char)ascii;
        }
        
        encMessage = message;//passing on for superclass Decode()

    }
    
    public void setMessage(String message, int key) throws NumberFormatException {
        //overrides EnigmaClass's setMessage
        
        this.message = message;
        this.key = key;
        if(key < 1 || key > 50)
            this.key = 1;
        
        super.encode();
        
        encode();
    }

    public void setEncodedMessage(String encodedMessage, int key) {
        //overrides EnigmaClass's setEncodedMessage
        
        encMessage = encodedMessage;
        this.key = key;
        if(key < 1 || key > 50)
            this.key = 1;
        
        decode();
        
        super.decode();
    }
}
