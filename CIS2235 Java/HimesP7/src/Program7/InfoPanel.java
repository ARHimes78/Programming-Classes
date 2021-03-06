//Alan Himes
//ahimes1@cnm.edu
//Program 7 - Polygons
//CIS2235
//File: MainP7.java, ControlPanel.java, DrawPanel.java, InfoPanel.java, PolygonCalc.java, PolygonFrame.java

package Program7;

import java.awt.BorderLayout;
import java.text.DecimalFormat;

/**
 *
 * @author splabbity
 */
public class InfoPanel extends javax.swing.JPanel {
    String perimeter, area, circumference, circleArea;
    private DecimalFormat df;
    private boolean circle;
    
    /**
     * Creates new form InfoPanel
     */
    public InfoPanel() {
        initComponents();
        
        circle = false;
        df = new DecimalFormat("#.0000");
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jTPerimeter = new javax.swing.JTextField();
        jTCircumference = new javax.swing.JTextField();
        jTCircleArea = new javax.swing.JTextField();
        jTArea = new javax.swing.JTextField();
        jLPerimeter = new javax.swing.JLabel();
        jLArea = new javax.swing.JLabel();
        jLCircumference = new javax.swing.JLabel();
        jLCircleArea = new javax.swing.JLabel();

        setBackground(new java.awt.Color(64, 64, 64));
        setBorder(javax.swing.BorderFactory.createTitledBorder(null, "MEASUREMENTS", javax.swing.border.TitledBorder.CENTER, javax.swing.border.TitledBorder.DEFAULT_POSITION, new java.awt.Font("Lucida Grande", 1, 14), new java.awt.Color(255, 255, 255))); // NOI18N
        setPreferredSize(new java.awt.Dimension(150, 500));

        jTPerimeter.setEditable(false);

        jTCircumference.setEditable(false);

        jTCircleArea.setEditable(false);

        jTArea.setEditable(false);

        jLPerimeter.setForeground(new java.awt.Color(255, 255, 255));
        jLPerimeter.setText("Perimeter");

        jLArea.setForeground(new java.awt.Color(255, 255, 255));
        jLArea.setText("Area");

        jLCircumference.setForeground(new java.awt.Color(255, 255, 255));
        jLCircumference.setText("Circumference");

        jLCircleArea.setForeground(new java.awt.Color(255, 255, 255));
        jLCircleArea.setText("Circle area");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTCircumference, javax.swing.GroupLayout.DEFAULT_SIZE, 138, Short.MAX_VALUE)
            .addComponent(jTCircleArea, javax.swing.GroupLayout.DEFAULT_SIZE, 138, Short.MAX_VALUE)
            .addComponent(jTArea)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLPerimeter)
                    .addComponent(jLArea)
                    .addComponent(jLCircumference)
                    .addComponent(jLCircleArea))
                .addContainerGap(41, Short.MAX_VALUE))
            .addComponent(jTPerimeter, javax.swing.GroupLayout.Alignment.TRAILING)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(119, Short.MAX_VALUE)
                .addComponent(jLPerimeter)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jTPerimeter, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(24, 24, 24)
                .addComponent(jLArea)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jTArea, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(20, 20, 20)
                .addComponent(jLCircumference)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jTCircumference, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(22, 22, 22)
                .addComponent(jLCircleArea)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jTCircleArea, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(90, 90, 90))
        );
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLArea;
    private javax.swing.JLabel jLCircleArea;
    private javax.swing.JLabel jLCircumference;
    private javax.swing.JLabel jLPerimeter;
    private javax.swing.JTextField jTArea;
    private javax.swing.JTextField jTCircleArea;
    private javax.swing.JTextField jTCircumference;
    private javax.swing.JTextField jTPerimeter;
    // End of variables declaration//GEN-END:variables


    public void circleStats(boolean vis) {
        jLCircumference.setEnabled(vis);
        jTCircumference.setEnabled(vis);
        jLCircleArea.setEnabled(vis);
        jTCircleArea.setEnabled(vis);
    }
    
    public void setPerimeter(Double p) {
        perimeter = df.format(p) + " inches";
    }
    
    public void setArea(Double a) {
        area = df.format(a) + " sq. inches";
    }
    
    public void setCircumference(Double c) {
        circumference = df.format(c) + " inches";
    }
    
    public void setCircleArea(Double ca) {
        circleArea = df.format(ca) + " sq. inches";
    }
    
    public void setCircle(boolean circ) {
        circle = circ;
    }
    
    public void measurements() {
        jTPerimeter.setText(perimeter);
        jTArea.setText(area);
        jTCircumference.setText("");
        jTCircleArea.setText("");
                
        if (circle) {
            jTCircumference.setText(circumference);
            jTCircleArea.setText(circleArea); 
        }
    }
}
