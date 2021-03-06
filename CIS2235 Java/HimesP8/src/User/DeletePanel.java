/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package User;

import Data.Data;
import Data.DbManager;
import java.sql.SQLException;
import javax.swing.JOptionPane;
/**
 *
 * @author ahimes1
 */
public class DeletePanel extends javax.swing.JPanel {
    private Data data;
    private DbManager db;
    private String[] groceries;
    private int[] ids;
    
    /**
     * Creates new form DeletePanel
     */
    public DeletePanel() {
        initComponents();
        
        data = new Data();
        db = new DbManager();
        
        initializeArrays();
        
        jListGroceries.setListData(groceries);
        
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jListGroceries = new javax.swing.JList();
        jLGroceries = new javax.swing.JLabel();
        jBDelete = new javax.swing.JButton();

        jListGroceries.setModel(new javax.swing.AbstractListModel() {
            String[] strings = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
            public int getSize() { return strings.length; }
            public Object getElementAt(int i) { return strings[i]; }
        });
        jListGroceries.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        jListGroceries.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                jListGroceriesValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(jListGroceries);

        jLGroceries.setText("Groceries");

        jBDelete.setText("Delete");
        jBDelete.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jBDeleteActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(226, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLGroceries)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 136, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(32, 32, 32)
                        .addComponent(jBDelete)))
                .addGap(202, 202, 202))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(31, Short.MAX_VALUE)
                .addComponent(jLGroceries)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 298, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(127, 127, 127)
                        .addComponent(jBDelete)))
                .addGap(29, 29, 29))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void jBDeleteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jBDeleteActionPerformed
        delete();
        initializeArrays();
        updateList();
    }//GEN-LAST:event_jBDeleteActionPerformed

    private void jListGroceriesValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_jListGroceriesValueChanged
        updateDataObj(ids[jListGroceries.getSelectedIndex()]);
    }//GEN-LAST:event_jListGroceriesValueChanged
    
    //to receive updates from other classes for use
    
    private void delete() {
        try {
            db.delete(data);
        }
        catch (SQLException ex) {
            JOptionPane.showMessageDialog(null, "unable to delete");
        }
    }
    
    public void initializeArrays() {
        try {
            groceries = db.getDataList();
            ids = db.getDataID();
        }
        catch (SQLException ex) {
            JOptionPane.showMessageDialog(null, "Unable to obtain data.");
        }
    }
    
    public void updateList(){
        jListGroceries.setListData(groceries);
    }
    
    private void updateDataObj(int index){
        //index should correspond to item on list
        
        try {
            data = db.getData(index);
        }
        catch (SQLException ex) {
            JOptionPane.showMessageDialog(null, "Unable to obtain data.");
        }
    }
    
    public void deselect() {
        jListGroceries.clearSelection();
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jBDelete;
    private javax.swing.JLabel jLGroceries;
    private javax.swing.JList jListGroceries;
    private javax.swing.JScrollPane jScrollPane1;
    // End of variables declaration//GEN-END:variables
}
