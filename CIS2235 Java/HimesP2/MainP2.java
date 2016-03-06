//Alan Himes
//ahimes1@cnm.edu
//File: AlarmClock.java
//Program 1 The Alarm Clock - Time to Sound an Alarm
//CIS2235
//File:  AlarmClock.java

import javax.swing.*;

public class MainP2 {
	private int again;
	public static ImageIcon iconPic;//decided to make this static because it doesn't change and making an object isn't needed.
	private AlarmUI ui;
	
	public static void main(String[] args) {
		MainP2 app = new MainP2();//using MainP2's constructor to activate the program
	}
	
	private MainP2() {
		iconPic = new ImageIcon("icon.png");
		again = 0;
		JOptionPane.showMessageDialog(null, 
			"Name: Alan Himes\nCourse: CIS2235\nProgram information: Calculate the time between a set time and the current time.", 
			"Program Header", JOptionPane.INFORMATION_MESSAGE, iconPic);
		do{
			ui = new AlarmUI();
			ui.start();
			again = JOptionPane.showConfirmDialog(null, "Would you like to set another alarm?", "Again?", 
				JOptionPane.INFORMATION_MESSAGE, 0, iconPic);
		} while (again == 0);
		JOptionPane.showMessageDialog(null, "Bye!", "End of program", JOptionPane.INFORMATION_MESSAGE, iconPic);
	}
}