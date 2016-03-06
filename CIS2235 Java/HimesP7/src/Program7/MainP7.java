//Alan Himes
//ahimes1@cnm.edu
//Program 7 - Polygons
//CIS2235
//File: MainP7.java, ControlPanel.java, DrawPanel.java, InfoPanel.java, PolygonCalc.java, PolygonFrame.java

package Program7;

import javax.swing.JFrame;

/**
 *
 * @author ahimes1
 */
public class MainP7 {
    private PolygonFrame frame;
    
    public static void main(String[] args){
        new MainP7();
    }
    
    public MainP7() {
        frame = new PolygonFrame();
        
        frame.setTitle("Alan Himes - Program 7: Polygons");
        frame.setSize(700, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setVisible(true);
    }
}
