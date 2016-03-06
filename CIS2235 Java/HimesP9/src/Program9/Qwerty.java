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
public class Qwerty extends EnigmaClass {
    
    public Qwerty(){
        //calling superclass constructor
    }
    
    protected void encode() {
        message = encMessage;//pass on result of superclass encode()
        encMessage = "";
        
        for (int i = 0; i<message.length(); ++i) {
            switch(message.charAt(i)) {
                case 'q':
                    encMessage += 'a';
                    break;
                case 'a':
                    encMessage += 'z';
                    break;
                case 'z':
                    encMessage += 'q';
                    break;
                case 'w':
                    encMessage += 's';
                    break;
                case 's':
                    encMessage += 'x';
                    break;
                case 'x':
                    encMessage += 'w';
                    break;
                case 'e':
                    encMessage += 'd';
                    break;
                case 'd':
                    encMessage += 'c';
                    break;
                case 'c':
                    encMessage += 'e';
                    break;
                case 'r':
                    encMessage += 'f';
                    break;
                case 'f':
                    encMessage += 'v';
                    break;
                case 'v':
                    encMessage += 'r';
                    break;
                case 't':
                    encMessage += 'g';
                    break;
                case 'g':
                    encMessage += 'b';
                    break;
                case 'b':
                    encMessage += 't';
                    break;
                case 'y':
                    encMessage += 'h';
                    break;
                case 'h':
                    encMessage += 'n';
                    break;
                case 'n':
                    encMessage += 'y';
                    break;
                case 'u':
                    encMessage += 'j';
                    break;
                case 'j':
                    encMessage += 'm';
                    break;
                case 'm':
                    encMessage += 'u';
                    break;
                case 'i':
                    encMessage += 'k';
                    break;
                case 'k':
                    encMessage += 'i';
                    break;
                case 'o':
                    encMessage += 'l';
                    break;
                case 'l':
                    encMessage += 'o';
                    break;
                case 'Q':
                    encMessage += 'A';
                    break;
                case 'A':
                    encMessage += 'Z';
                    break;
                case 'Z':
                    encMessage += 'Q';
                    break;
                case 'W':
                    encMessage += 'S';
                    break;
                case 'S':
                    encMessage += 'X';
                    break;
                case 'X':
                    encMessage += 'W';
                    break;
                case 'E':
                    encMessage += 'D';
                    break;
                case 'D':
                    encMessage += 'C';
                    break;
                case 'C':
                    encMessage += 'E';
                    break;
                case 'R':
                    encMessage += 'F';
                    break;
                case 'F':
                    encMessage += 'V';
                    break;
                case 'V':
                    encMessage += 'R';
                    break;
                case 'T':
                    encMessage += 'G';
                    break;
                case 'G':
                    encMessage += 'B';
                    break;
                case 'B':
                    encMessage += 'T';
                    break;
                case 'Y':
                    encMessage += 'H';
                    break;
                case 'H':
                    encMessage += 'N';
                    break;
                case 'N':
                    encMessage += 'Y';
                    break;
                case 'U':
                    encMessage += 'J';
                    break;
                case 'J':
                    encMessage += 'M';
                    break;
                case 'M':
                    encMessage += 'U';
                    break;
                case 'I':
                    encMessage += 'K';
                    break;
                case 'K':
                    encMessage += 'I';
                    break;
                case 'O':
                    encMessage += 'L';
                    break;
                case 'L':
                    encMessage += 'O';
                    break;
                default:
                    encMessage += message.charAt(i);
                    break;
            }
        }
    }
    
    protected void decode() {
        message = "";
        
        for (int i = 0; i<encMessage.length(); ++i) {
            switch(encMessage.charAt(i)) {
                case 'a':
                    message += 'q';
                    break;
                case 'z':
                    message += 'a';
                    break;
                case 'q':
                    message += 'z';
                    break;
                case 's':
                    message += 'w';
                    break;
                case 'x':
                    message += 's';
                    break;
                case 'w':
                    message += 'x';
                    break;
                case 'd':
                    message += 'e';
                    break;
                case 'c':
                    message += 'd';
                    break;
                case 'e':
                    message += 'c';
                    break;
                case 'f':
                    message += 'r';
                    break;
                case 'v':
                    message += 'f';
                    break;
                case 'r':
                    message += 'v';
                    break;
                case 'g':
                    message += 't';
                    break;
                case 'b':
                    message += 'g';
                    break;
                case 't':
                    message += 'b';
                    break;
                case 'h':
                    message += 'y';
                    break;
                case 'n':
                    message += 'h';
                    break;
                case 'y':
                    message += 'n';
                    break;
                case 'j':
                    message += 'u';
                    break;
                case 'm':
                    message += 'j';
                    break;
                case 'u':
                    message += 'm';
                    break;
                case 'i':
                    message += 'k';
                    break;
                case 'k':
                    message += 'i';
                    break;
                case 'o':
                    message += 'l';
                    break;
                case 'l':
                    message += 'o';
                    break;
                case 'A':
                    message += 'Q';
                    break;
                case 'Z':
                    message += 'A';
                    break;
                case 'Q':
                    message += 'Z';
                    break;
                case 'S':
                    message += 'W';
                    break;
                case 'X':
                    message += 'S';
                    break;
                case 'W':
                    message += 'X';
                    break;
                case 'D':
                    message += 'E';
                    break;
                case 'C':
                    message += 'D';
                    break;
                case 'E':
                    message += 'C';
                    break;
                case 'F':
                    message += 'R';
                    break;
                case 'V':
                    message += 'F';
                    break;
                case 'R':
                    message += 'V';
                    break;
                case 'G':
                    message += 'T';
                    break;
                case 'B':
                    message += 'G';
                    break;
                case 'T':
                    message += 'B';
                    break;
                case 'H':
                    message += 'Y';
                    break;
                case 'N':
                    message += 'H';
                    break;
                case 'Y':
                    message += 'N';
                    break;
                case 'J':
                    message += 'U';
                    break;
                case 'M':
                    message += 'J';
                    break;
                case 'U':
                    message += 'M';
                    break;
                case 'I':
                    message += 'K';
                    break;
                case 'K':
                    message += 'I';
                    break;
                case 'O':
                    message += 'L';
                    break;
                case 'L':
                    message += 'O';
                    break;
                default:
                    message += encMessage.charAt(i);
                    break;
        }  
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
