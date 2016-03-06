//Alan Himes
//ahimes1@cnm.edu
//Program 8 - Database Manipulation
//CIS2235
//File: MainP8.java, DbFrame.java, AddPanel.java, UpdatePanel.java, DeletePanel.java, Data.java, DbManager.java

package User;

import javax.swing.JFrame;

/**
 *
 * @author ahimes1
 */
public class MainP8 {
    DbFrame frame;
    
    public static void main(String[] args) {
        new MainP8();
    }
    
    public MainP8() {
        frame = new DbFrame();
        
        frame.setTitle("Alan Himes - Program 8: Database Manipulation");
        frame.setSize(700, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setVisible(true);
    }
}
