//Alan Himes
//ahimes1@cnm.edu
//Program 6 Enigma Class
//CIS2235
//File: MainP6.java, EnigmaFrame.java, EnigmaClass.java, EnigmaInterface.java

package Program6;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import javax.swing.JOptionPane;

/**
 *
 * @author ahimes1
 */
public class EnigmaClass implements EnigmaInterface{
    
    String message;
    String encMessage;
    int key;
    
    public EnigmaClass() {
        message = "";
        encMessage = "";
        key = 0;
    }
    
    private void encode() {
        int i;
        int ascii;
        encMessage = "";
        for (i=0; i<message.length(); ++i){
            ascii = (int)message.charAt(i);
            if(ascii + key > 126) {
                ascii = ((ascii + key) - 126) + 31;
            }
            else
                ascii = ascii + key;
            encMessage += (char)ascii;
        }
    }
    
    private void decode() {
        int i;
        int ascii;
        message = "";
        for (i=0; i<encMessage.length(); ++i){
            ascii = (int)encMessage.charAt(i);
            if(ascii - key < 32) {
                ascii = 127 - (32 - (ascii - key));
            }
            else
                ascii = ascii - key;
            message += (char)ascii;
        }
    }
    
    @Override
    public void setMessage(String message) {
        this.message = message;
    }

    @Override
    public void setMessage(String message, int key) throws NumberFormatException {
        this.message = message;
        this.key = key;
        if(key < 1 || key > 50)
            this.key = 1;
        encode();
    }

    @Override
    public void setEncodedMessage(String encodedMessage, int key) {
        encMessage = encodedMessage;
        this.key = key;
        if(key < 1 || key > 50)
            this.key = 1;
        decode();
    }

    @Override
    public String getMessage() {
        return message;
    }

    @Override
    public String getEncodedMessage() {
        return encMessage;
    }

    @Override
    public int getKey() {
        return key;
    }
    
    public void writeFile(File file) {
        try {
            FileWriter fstream = new FileWriter(file);
            BufferedWriter outPut = new BufferedWriter(fstream);
            
            outPut.write(encMessage + "\r\n" + key);
            
            outPut.close();
        }
        
        catch(Exception e) {
            JOptionPane.showMessageDialog(null, "Error: " + e.getMessage());
        }
    }
    
    public void readFile(File file) {
        try {
            FileReader fstream = new FileReader(file);
            BufferedReader inPut = new BufferedReader(fstream);
            
            /*The opened file must have one line of text and a second line of 
            just a number for this to work.*/
            encMessage = inPut.readLine();
            key = Integer.parseInt(inPut.readLine());
            
            inPut.close();
        }
        
        catch(Exception e) {
            JOptionPane.showMessageDialog(null, "Error: " + e.getMessage());
        }
    }
}