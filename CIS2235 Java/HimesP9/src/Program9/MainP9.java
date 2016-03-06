//Alan Himes
//ahimes1@cnm.edu
//Program 9 Enigma with Polymorphism
//CIS2235
//File: MainP9.java, EnigmaFrame.java, EnigmaClass.java, EnigmaInterface.java, PrimeShift.java, Qwerty.java, Alternate.java

package Program9;
import javax.swing.JFrame;

/**
 *
 * @author ahimes
 */
public class MainP9 {
    private EnigmaFrame frame;
    
    public static void main(String[] args) {
        new MainP9();
    }
    
    public MainP9(){
        frame = new EnigmaFrame();
        frame.setTitle("Alan Himes - Program 9: Enigma with polymorphism");
        frame.setSize(600, 400);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
