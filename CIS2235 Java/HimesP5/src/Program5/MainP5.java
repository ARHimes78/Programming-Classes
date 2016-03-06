//Alan Himes
//ahimes1@cnm.edu
//Program 5 GUI by NetBeans
//CIS2235
//File: MainP5.java, PurchaseFrame.java, PurchaseData.java

package Program5;
import javax.swing.JFrame;

/**
 *
 * @author ahimes1
 */
public class MainP5 {
    private PurchaseFrame frame;
    
    public static void main(String[] args){
        new MainP5();
    }
    
    private MainP5() {
        frame = new PurchaseFrame();
        frame.setTitle("Purchase simulator");
        frame.setSize(750, 550);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
