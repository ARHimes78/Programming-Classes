import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class AlarmFrame extends JFrame implements ActionListener {

private AlarmCalc calculate;
private JComboBox selectAmPm;
private JButton button;
private JLabel inputA, inputB, output;
private JTextField userInput;
private String inputString, outputString, messageA, messageB;
private String[] amOrPm= {"AM", "PM"};
private String userAmPm;

	public AlarmFrame(){
	
		userAmPm = "";
		
		messageA = "Enter a month, day, year, hour, and minute (MM,DD,YYYY,HH,MM), separated by commas."; 
		messageB = "Also, choose AM or PM from the combo box.";
		
		selectAmPm = new JComboBox(amOrPm);
		button = new JButton("Calculate Time Difference");
		inputA = new JLabel(messageA);
		inputB = new JLabel(messageB);
		output = new JLabel(outputString);
		userInput = new JTextField();
		
		Container windowItems = getContentPane(); 
		
		windowItems.setLayout(new GridLayout(6,0));
		
		windowItems.add(inputA);
		windowItems.add(inputB);
		windowItems.add(userInput);
		windowItems.add(selectAmPm);
		windowItems.add(button);
		windowItems.add(output);
		
		
		button.addActionListener(this);
		
	}
	
	public void actionPerformed(ActionEvent e) {
		
		timeDifference();
		
	}
	
	private void timeDifference() {
		calculate = new AlarmCalc();
		inputString = "";
		
		//initializing items here, values will be reset with each button click (instead of accumulating).
	
		inputString = userInput.getText();
		userAmPm = (String)selectAmPm.getSelectedItem();//assigning AM or PM here
		
		try {
		calculate.getTime(userAmPm, inputString);
		}
		catch (NumberFormatException nfe) {
		output.setText("Please enter numbers only!");
		return;
		}
		catch (ArrayIndexOutOfBoundsException ae) {
		output.setText("Commas are needed to separate the numbers!");
		return;
		}
		
		outputString = calculate.CalculateDifference() 
			+ " That's " + AlarmCalc.when + "!";
		output.setText(outputString);
	}
}
