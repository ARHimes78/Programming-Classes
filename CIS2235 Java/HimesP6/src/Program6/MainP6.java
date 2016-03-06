//Alan Himes
//ahimes1@cnm.edu
//Program 6 Enigma Class
//CIS2235
//File: MainP6.java, EnigmaFrame.java, EnigmaClass.java, EnigmaInterface.java

package Program6;
import javax.swing.JFrame;

/**
 *
 * @author ahimes
 */
public class MainP6 {
    private EnigmaFrame frame;
    
    public static void main(String[] args) {
        new MainP6();
    }
    
    public MainP6(){
        frame = new EnigmaFrame();
        frame.setTitle("Alan Himes - Program 6: Enigma class");
        frame.setSize(600, 400);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}