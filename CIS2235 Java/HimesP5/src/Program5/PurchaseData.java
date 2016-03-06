package Program5;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.text.DecimalFormat;
import javax.swing.JOptionPane;

/**
 *
 * @author ahimes1
 */
public class PurchaseData {
    private DecimalFormat df;
    private String fruit;
    private String adjective1, adjective2;
    private int pistachios;
    String cereal, soup;
    String chips, candy, soda;
    private double cerealPrice, soupPrice, chipsPrice, candyPrice, sodaPrice;
    private double total;
    private String summary;
    
    public PurchaseData() {
        df = new DecimalFormat("#.00");
        fruit = " " + "apple";//initial selection of combo box.
        adjective1 = "";
        adjective2 = "";
        pistachios = 0;
        cereal = "Mystery Cereal";
        soup = "Vegetable Beef";
        chips = " ";
        candy = " ";
        soda = " ";
        chipsPrice = 0.0;
        candyPrice = 0.0;
        sodaPrice = 0.0;
        total = 1.00; //because of the mandatory fruit.
        summary = "";
    }
    
    public void setCombo(String fruit) {
        this.fruit = " " + fruit;
    }
    
    public void setTextField1(String adj) {
        if (adj.equals(""))
            adjective1 = "";
        else
            adjective1 = " " + adj;
    }
    
    public void setTextField2(String adj) {
        if (adj.equals(""))
            adjective2 = "";
        else
            adjective2 = ", " + adj;
    }
    
    public void setSlider(int pist) {
        pistachios = pist;
    }
    
    public void setRadio1(String cereal) {
        this.cereal = cereal;
        if (cereal == "Corn Flakes")
            cerealPrice = 3.89;
        else if (cereal == "Raisin Bran")
            cerealPrice = 2.35;
        else if (cereal == "Mystery Cereal")
            cerealPrice = 0.0;
    }
    
    public void setRadio2(String soup) {
        this.soup = soup;
        if (soup == "Clam Chowder")
            soupPrice = 3.95;
        else if (soup == "Vegetable Beef")
            soupPrice = 0.0;
        else if (soup == "Chicken Soup")
            soupPrice = 4.11;
    }
    
    public void setCheck1(String chips) {
        this.chips = chips + " ";
        
        if (chips.equals(" "))
            chipsPrice = 0.0;
        else
            chipsPrice = .99;
    }
    
    public void setCheck2(String candy) {
        this.candy = candy + " ";
        
        if (candy.equals(" "))
            candyPrice = 0.0;
        else
            candyPrice = 1.09;
    }
    
    public void setCheck3(String soda) {
        this.soda = soda + " ";
        
        if (soda.equals(" "))
            sodaPrice = 0.0;
        else
            sodaPrice = 2.15;
    }
    
    private void createSummary() {
        //take all the items and make a summary string
        
        String nothing = "";
        
        if (chips.equals(" ") && candy.equals(" ") && soda.equals(" ")) {
            nothing = "none";
        }
        
        if (soup.equals("Vegetable Beef"))
            soup = "WE'RE ALL OUT OF VEGETABLE BEEF SOUP!!!!";
        
        summary = "One" + adjective1 + adjective2 + fruit + " \n"
            + pistachios + " pistachios" + " \n"
            + "Some " + cereal + " \n"
            + "Also, " + soup + " \n" 
            + "Snacks: " + nothing + chips + candy + soda + " \n"
            + "Your total is " + getTotal(); 
    }
    
    public String getTotal() {
        double snackPrice = chipsPrice + candyPrice + sodaPrice;
        
        return "$" + df.format(total + (.05 * pistachios) + cerealPrice
            + soupPrice + snackPrice);
    }
    
    public String getSummary() {
        createSummary();
        return summary;
    }
    
    public void writeFile(File file){
        try {
            FileWriter fstream = new FileWriter(file);
            BufferedWriter outPut = new BufferedWriter(fstream);
            outPut.write(summary);
            //looks good in Word, Notepad++ and Wordpad, not Notepad.
            
            outPut.close();
        }
        
        catch(Exception e) {
            JOptionPane.showMessageDialog(null, "Error: " + e.getMessage());
        }
    }
}