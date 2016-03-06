//Alan Himes
//ahimes1@cnm.edu
//File: AlarmClock.java
//Program 1 The Alarm Clock - Time to Sound an Alarm
//CIS2235
//File:  AlarmClock.java

import javax.swing.*;  //for dialog boxes and icons
import java.util.*; //gregorian calendar

public class AlarmClock
{
	public static void main(String [] args) { 
		//ALL your program code must be contained in main
		//show header in a JOptionPane message box
		//begin while or do while to ask user for inputs, calculate time //to alarm, then show results

		//Icon iconPic;
		ImageIcon iconPic = new ImageIcon("icon.png");
		int again = 0;
		
		JOptionPane.showMessageDialog(null, 
			"Name: Alan Himes\nCourse: CIS2235\nProgram information: Calculate the time between a set time and the current time.", 
			"Program Header", JOptionPane.INFORMATION_MESSAGE, iconPic);
	
		do {
			Calendar calendar = new GregorianCalendar();
			//setting up the current time to compare with user input.
			int hour = calendar.get(Calendar.HOUR_OF_DAY);
			int minute = calendar.get(Calendar.MINUTE);
			int month = calendar.get(Calendar.MONTH);
			int date = calendar.get(Calendar.DATE);
			int year = calendar.get(Calendar.YEAR);
			
			calendar.set(Calendar.HOUR_OF_DAY, hour);
			calendar.set(Calendar.MINUTE, minute);
			calendar.set(year, month, date); //used pg.568 in textbook
			int week = calendar.get(Calendar.WEEK_OF_YEAR);
			int dayOfYear = calendar.get(Calendar.DAY_OF_YEAR);
			
			/*System.out.println(calendar.getTime());
			System.out.println(dayOfYear);*/
			
			boolean invalid = true;
			
			while (invalid==true) {
				String input = JOptionPane.showInputDialog(null, 
					"Enter a year, month, day, hour, minute, and AM/PM for the alarm, separated by commas." + 
					"\n(For example, July, 21, 2015 at 12:47AM would be entered as \"2015,7,21,12,47,am\")", 
					"Alarm set", JOptionPane.INFORMATION_MESSAGE);
				
				//any object or variable with the word "user" is part of the time that has been input by the user.
				Calendar userCalendar = new GregorianCalendar();
				
				String[] array = input.split(",");
				int userYear = Math.abs(Integer.parseInt(array[0])); //using absolute value in case of a negative number input
				int userMonth = Math.abs(Integer.parseInt(array[1]) - 1);
				int userDate = Math.abs(Integer.parseInt(array[2]));
				int userHour = Math.abs(Integer.parseInt(array[3]));
				int userMinute = Math.abs(Integer.parseInt(array[4]));
				String userAmPm = array[5];
				
				//adjusting input to military time, calculating minutes will be easier
				if (userAmPm.toLowerCase().equals("pm") && userHour != 12) {
					userHour += 12; 
				}
				if (userAmPm.toLowerCase().equals("am") && userHour == 12) {
					userHour = 0;
				}
				userCalendar.set(Calendar.HOUR_OF_DAY, userHour);
				userCalendar.set(Calendar.MINUTE, userMinute);
				userCalendar.set(userYear, userMonth, userDate);
				int userWeek = userCalendar.get(Calendar.WEEK_OF_YEAR);
				int userDayOfYear = userCalendar.get(Calendar.DAY_OF_YEAR);
				int userDayOfWeek = userCalendar.get(Calendar.DAY_OF_WEEK);
				
				String when;
				
				if (dayOfYear == userDayOfYear && year == userYear)
					when = "today";
				else if (dayOfYear == (userDayOfYear - 1) || 
					((dayOfYear == 365 || dayOfYear == 366) && userDayOfYear == 1) && year == (userYear - 1))
					when = "tomorrow";
				else if ((year == userYear || year == userYear - 1) && (userDayOfWeek == 7 && week == userWeek) || 
					(userDayOfWeek == 1 && (week == userWeek - 1 || (week == 52 && userWeek == 1))))
					when = "this weekend";
				else if (year == userYear && month == userMonth && week == userWeek)
					when = "this week";
				else if (year == userYear && month == userMonth)
					when = "this month";
				else if (year == userYear)
					when = "this year";
				else
					when = "a long time from now";
				
				JOptionPane.showMessageDialog(null, "The time you entered is " + userCalendar.getTime() + "." + 
					"\nThat's " + when + "!", "Time", JOptionPane.INFORMATION_MESSAGE, 
					iconPic);//The input time in standard time format
				
				/*System.out.println(userCalendar.getTime());
				System.out.println(userDayOfYear)*/;
				
				int daysBetweenYears = 0;
				int i;
				
				for (i=year; i<userYear; i++) {
					daysBetweenYears += 365;
					//System.out.println(daysBetweenYears);
					if (i % 4 == 0) { //leap year between the two years
						daysBetweenYears++;
						//System.out.println("Added 1: " + daysBetweenYears);
					}
				}
				
				long totalMinutes = (dayOfYear * 60 * 24) + (hour * 60) + minute;
				//System.out.println("totalMinutes = " + totalMinutes);
				long totalUserMinutes = (daysBetweenYears * 60 * 24) + (userDayOfYear * 60 * 24) + (userHour * 60) + userMinute;
				//System.out.println("totalUserMinutes = " + totalUserMinutes);
				
				if (totalUserMinutes - totalMinutes < 0) {
					JOptionPane.showMessageDialog(null, "Please enter a future time.", "That's in the past!", JOptionPane.INFORMATION_MESSAGE, iconPic);
				}
				else {
					long minutesDifference = totalUserMinutes - totalMinutes;
					long hoursDifference = minutesDifference / 60; //truncates remaining decimal amount
					long remainingMinutes = minutesDifference % 60;
					JOptionPane.showMessageDialog(null, "The alarm will sound in:\n" + hoursDifference + 
						" hours and " + remainingMinutes + " minutes.", "Alarm Info", JOptionPane.INFORMATION_MESSAGE, iconPic);
					invalid = false;
				}
			}
			
			again = JOptionPane.showConfirmDialog(null, "Would you like to set another alarm?", "Again?", 
					JOptionPane.INFORMATION_MESSAGE, 0, iconPic); //yes means 0, no means 1, cancel means 2.
			
		} while (again == 0);
		JOptionPane.showMessageDialog(null, "Bye!", "End of program", JOptionPane.INFORMATION_MESSAGE, iconPic);
	}
}