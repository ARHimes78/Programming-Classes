//Alan Himes
//ahimes1@cnm.edu
//File: AlarmClock.java
//Program 3 The Alarm Clock - JFrame version
//CIS2235
//File:  AlarmClock.java

import javax.swing.*;

public class MainP3 {
	
	AlarmFrame frame;
	
	public static void main(String[] args) {
		
		MainP3 app = new MainP3();
		
	}
	
	private MainP3() {
		
		JOptionPane.showMessageDialog(null, 
				"Name: Alan Himes\nCourse: CIS2235\nProgram information: Calculate the time between a set time and the current time.", 
				"Program Header", JOptionPane.INFORMATION_MESSAGE);
		
		frame = new AlarmFrame();
		
		frame.setTitle("Alarm Clock");
		frame.setLocationRelativeTo(null);
		frame.setSize(600,400);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		
		
	}
	
}
