//Alan Himes
//ahimes1@cnm.edu
//Program 7 - Polygons
//CIS2235
//File: MainP7.java, ControlPanel.java, DrawPanel.java, InfoPanel.java, PolygonCalc.java, PolygonFrame.java

package Program7;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author splabbity
 */
public class DrawPanel extends javax.swing.JPanel {
    //private PolygonFrame frame;
    private Color shapeColor;
    private int radius;
    private int sides;
    private int centerX, centerY;
    private boolean circle;
    
    /**
     * Creates new form DrawPanel
     */
    public DrawPanel() {
        initComponents();
        
        centerX = 200;
        centerY = 250;
        shapeColor = (Color.BLACK);
        circle = false;
        drawShape();
    }
    
    public void drawShape() {
        repaint();
    }
    
    public void paintComponent(Graphics g){
        
        
        super.paintComponent(g);
        
        g.setColor(shapeColor);
        
        /*
        Would have preferred a switch/case, but it didn't work well with array
        assigments. Each possible side of the polygon corresponds to the amount
        of array elements for drawPolygon's arguments.
        Created methods graphSin and graphCos to calculate vector locations,
        which solve the math as doubles before casting the results to ints
        for the int arrays required by drawPolygon.
        */
        if (sides == 3) {
            int shapeX[] = {centerX, centerX+radius*(int)graphSin(1), 
                centerX-radius*(int)graphSin(1)};
            int shapeY[] = {centerY-radius*20, centerY+radius*(int)graphCos(1), 
                centerY+radius*(int)graphCos(1)};
            g.drawPolygon(shapeX, shapeY, sides);
        }
        else if (sides == 4) {
            int shapeX[] = {centerX, centerX+radius*20, centerX, centerX-radius*20};
            int shapeY[] = {centerY+radius*20, centerY, centerY-radius*20, centerY};
            g.drawPolygon(shapeX, shapeY, sides);
        }
        else if (sides == 5) {
            int shapeX[] = {centerX, centerX+radius*(int)graphSin(1),
                centerX+radius*(int)graphSin(2),
                centerX-radius*(int)graphSin(2),
                centerX-radius*(int)graphSin(1)};
            int shapeY[] = {centerY-radius*20, centerY-radius*(int)graphCos(1),
                centerY+radius*(int)graphCos(2),
                centerY+radius*(int)graphCos(2),
                centerY-radius*(int)graphCos(1)};
            g.drawPolygon(shapeX, shapeY, sides);
        }
        else if (sides == 6) {
            int shapeX[] = {centerX, centerX+radius*(int)graphSin(1),
                centerX+radius*(int)graphSin(2),
                centerX,
                centerX-radius*(int)graphSin(2),
                centerX-radius*(int)graphSin(1),};
            int shapeY[] = {centerY-radius*20, centerY-radius*(int)graphCos(1),
                centerY+radius*(int)graphCos(2),
                centerY+radius*20,
                centerY+radius*(int)graphCos(2),
                centerY-radius*(int)graphCos(1)};
            g.drawPolygon(shapeX, shapeY, sides);
        }
        else if (sides == 7) {
            int shapeX[] = {centerX, centerX+radius*(int)graphSin(1),
                centerX+radius*(int)graphSin(2),
                centerX+radius*(int)graphSin(3),
                centerX-radius*(int)graphSin(3),
                centerX-radius*(int)graphSin(2),
                centerX-radius*(int)graphSin(1)};
            int shapeY[] = {centerY-radius*20, centerY-radius*(int)graphCos(1),
                centerY+radius*(int)graphCos(2),
                centerY+radius*(int)graphCos(3),
                centerY+radius*(int)graphCos(3),
                centerY+radius*(int)graphCos(2),
                centerY-radius*(int)graphCos(1)};
            g.drawPolygon(shapeX, shapeY, sides);
        }
        else if (sides == 8) {
            int shapeX[] = {centerX, centerX+radius*(int)graphSin(1),
                centerX+radius*20, centerX+radius*(int)graphSin(1),
                centerX, centerX-radius*(int)graphSin(1),
                centerX-radius*20, centerX-radius*(int)graphSin(1)};
            int shapeY[] = {centerY-radius*20, centerY-radius*(int)graphCos(1),
                centerY, centerY+radius*(int)graphCos(1),
                centerY+radius*20, centerY+radius*(int)graphCos(1),
                centerY, centerY-radius*(int)graphCos(1)};
            g.drawPolygon(shapeX, shapeY, sides);
        }
        else if (sides == 9) {
            int shapeX[] = {centerX, centerX+radius*(int)graphSin(1),
                centerX+radius*(int)graphSin(2),
                centerX+radius*(int)graphSin(3),
                centerX+radius*(int)graphSin(4),
                centerX-radius*(int)graphSin(4),
                centerX-radius*(int)graphSin(3),
                centerX-radius*(int)graphSin(2),
                centerX-radius*(int)graphSin(1)};
            int shapeY[] = {centerY-radius*20, centerY-radius*(int)graphCos(1),
                centerY-radius*(int)graphCos(2),
                centerY+radius*(int)graphCos(3),
                centerY+radius*(int)graphCos(4),
                centerY+radius*(int)graphCos(4),
                centerY+radius*(int)graphCos(3),
                centerY-radius*(int)graphCos(2),
                centerY-radius*(int)graphCos(1)};
            g.drawPolygon(shapeX, shapeY, sides);
        }
        else {
            int shapeX[] = {centerX, centerX+radius*(int)graphSin(1),
                centerX+radius*(int)graphSin(2),
                centerX+radius*(int)graphSin(2),
                centerX+radius*(int)graphSin(1),
                centerX, centerX-radius*(int)graphSin(1),
                centerX-radius*(int)graphSin(2),
                centerX-radius*(int)graphSin(2),
                centerX-radius*(int)graphSin(1)};
            int shapeY[] = {centerY-radius*20, centerY-radius*(int)graphCos(1),
                centerY-radius*(int)graphCos(2),
                centerY+radius*(int)graphCos(2),
                centerY+radius*(int)graphCos(1),
                centerY+radius*20, centerY+radius*(int)graphCos(1),
                centerY+radius*(int)graphCos(2),
                centerY-radius*(int)graphCos(2),
                centerY-radius*(int)graphCos(1)};
            g.drawPolygon(shapeX, shapeY, sides);
        }
        
        if (circle) {
            int circCenter = radius * 20;
            int circSize = radius * 40;
            g.drawOval(centerX - circCenter, centerY - circCenter, circSize, circSize);
        }
    }
    
    private double graphSin(int angle) {
        
        return Math.abs(Math.sin(Math.toRadians(360*angle/sides))*20);
    }
    
    private double graphCos(int angle) {
        
        return Math.abs(Math.cos(Math.toRadians(360*angle/sides))*20);
    }
    
        public void setRadius(int r) {
        radius = r;
    }
    
    public void setSides(int s) {
        sides = s;
    }
    
    public void setColor (Color c) {
        shapeColor = c;
    }
    
    public void setCircle(boolean circ) {
        circle = circ;
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setBackground(new java.awt.Color(192, 192, 192));
        setPreferredSize(new java.awt.Dimension(400, 500));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 500, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents
    

    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
