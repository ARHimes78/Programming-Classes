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
public class Alternate extends EnigmaClass {
    
    public Alternate(){
        //calling superclass constructor
    }
    
    protected void encode() {
        message = encMessage;//pass on result of superclass encode()
        encMessage = "";
        
        if (key % 2 == 0) {
            //arrange the string as 0,2,4...then 1,3,5...
            for(int i=0; i<2; ++i){
                for(int j=i; j<message.length(); j+=2){
                    encMessage += message.charAt(j);
                }
            }
        }
        else {
            //arrange the string as 1,3,5...then 0,2,4...
            for(int i=1; i>-1; --i){
                for(int j=i; j<message.length(); j+=2){
                    encMessage += message.charAt(j);
                }
            }
        }
    }
    
    
        
    
    protected void decode() {
        message = "";
        
        //splitting encMessage in half
        
        String encMsgEvenHalf = "";
        String encMsgOddHalf = "";
        int half = 0;//used in for loop condition at end of this method
        boolean halfIsOdd = false;
        
        if (key % 2 == 0) {
            //check if amount of characters in encMessage is even
            if (encMessage.length() % 2 == 0) {
                for (int i=0; i<encMessage.length(); ++i){
                    if (i<encMessage.length()/2) {
                        encMsgEvenHalf += encMessage.charAt(i);  
                    }
                    else{
                        encMsgOddHalf += encMessage.charAt(i);
                    }
                }
            }
            else {
                halfIsOdd = true;
                
                /*If encMessage.length() is odd, and key is even, 
                    the first group of characters will be half the length plus 1.
                    For example, if the string has 9 characters, the first half will
                    be the first 5 (9/2, truncated to 4, plus 1).
                    */
                for (int i=0; i<encMessage.length(); ++i){ 
                    if (i<encMessage.length()/2 + 1) { 
                        encMsgEvenHalf += encMessage.charAt(i);
                    }
                    else {
                        encMsgOddHalf += encMessage.charAt(i);
                    }
                } 
            }
        }
        else {
            if (encMessage.length() % 2 == 0) {
                /*If encMessage has an even amount of numbers, the for
                condition below will have the same effect as the "even key"
                version, but it's also used for the "else" condition here
                of which the string has an odd number of characters.
                */
                for (int i=0; i<encMessage.length(); ++i){
                    if (i<encMessage.length() - (encMessage.length()/2))
                        encMsgOddHalf += encMessage.charAt(i);
                    else
                        encMsgEvenHalf += encMessage.charAt(i);
                }
            }
            else {
                halfIsOdd = true;
                
                /*If encMessage.length() is odd, and key is odd, 
                the SECOND group of characters will be half the length plus 1.
                Also, there will ALWAYS be more evens (0, 2, 4...) if the
                string length is odd.
                The if condition i<encMessage.length() - (encMessage.length()/2 + 1)
                is like the i<encMessage.length()/2 + 1 "counterpart" in the "even key"
                version, except instead of into the string from the beginning, it's
                into the string from the end. This causes the amount of odd numbers 
                to be one less than the amount of even numbers.
                */
                for (int i=0; i<encMessage.length(); ++i){
                    if (i<encMessage.length() - (encMessage.length()/2 + 1))
                        encMsgOddHalf += encMessage.charAt(i);
                    else
                        encMsgEvenHalf += encMessage.charAt(i);
                }  
            }
        }
        
        /*The number of even positioned characters is always
        half of the string or half of the string + 1.
        */
        half = encMsgEvenHalf.length();
        
        /*Now, assembling message with the two string halves.
        This works whether the key is even or odd because the first
        character is always even (0 position).
        */
        for (int i=0; i<half; ++i) {
            message += encMsgEvenHalf.charAt(i);
            if (halfIsOdd && i == half-1)
                break;//to avoid out of bounds error.
            else
                message += encMsgOddHalf.charAt(i);
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
