import javax.swing.*;
import java.util.*;

public class AlarmUI {
	private Calendar calendar; //"now" calendar object
	private Calendar userCalendar; //user input calendar object
	private AlarmCalc calculate;
	private int hour, minute, month, date, year, week, dayOfYear;//these all pertain to "now".
	private int userHour, userMinute, userMonth, userDate, userYear, userWeek, userDayOfYear, userDayOfWeek;//anything with "user" is from user input.
	private String input, userAmPm, when;
	private String[] array;
	private boolean invalid;
	
	
	public AlarmUI() {
		
		calendar = new GregorianCalendar();
		userCalendar = new GregorianCalendar();
		calculate = new AlarmCalc();
		
		hour = calendar.get(Calendar.HOUR_OF_DAY); //Upon construction, current time units variables are assigned.
		minute = calendar.get(Calendar.MINUTE);
		month = calendar.get(Calendar.MONTH);
		date = calendar.get(Calendar.DATE);
		year = calendar.get(Calendar.YEAR);
		week = calendar.get(Calendar.WEEK_OF_YEAR);
		dayOfYear = calendar.get(Calendar.DAY_OF_YEAR);
		
		input = "";
		userAmPm = ""; 
		when = "";
		
		invalid = true;
		
	}
	
	public void start() {
		
		do {
			input = JOptionPane.showInputDialog(null, 
				"Enter a month, day, year, hour, minute, and AM/PM for the alarm, separated by commas." + 
				"\n(For example, July, 21, 2015 at 12:47AM would be entered as \"7,21,2015,12,47,am\")", 
				"Alarm set", JOptionPane.INFORMATION_MESSAGE);
				
			array = input.split(",");//array elements are created from "input" string
			userMonth = Math.abs(Integer.parseInt(array[0]) - 1); //using absolute value in case of a negative number input
			userDate = Math.abs(Integer.parseInt(array[1]));
			userYear = Math.abs(Integer.parseInt(array[2]));
			userHour = Math.abs(Integer.parseInt(array[3]));
			userMinute = Math.abs(Integer.parseInt(array[4]));
			userAmPm = array[5];
				
			//adjusting input to military time, calculating minutes will be easier
			if (userAmPm.toLowerCase().equals("pm") && userHour != 12) {
				userHour += 12; 
			}
			if (userAmPm.toLowerCase().equals("am") && userHour == 12) {
				userHour = 0;
			}
			userCalendar.set(Calendar.HOUR_OF_DAY, userHour); //set object's fields in order to obtain WEEK_OF_YEAR, etc.
			userCalendar.set(Calendar.MINUTE, userMinute);
			userCalendar.set(userYear, userMonth, userDate);
			userWeek = userCalendar.get(Calendar.WEEK_OF_YEAR);
			userDayOfYear = userCalendar.get(Calendar.DAY_OF_YEAR);
			userDayOfWeek = userCalendar.get(Calendar.DAY_OF_WEEK);
					
			when = whenIsIt();
			
			JOptionPane.showMessageDialog(null, "The time you entered is " + userCalendar.getTime() + "." + 
				"\nThat's " + when + "!", "Time", JOptionPane.INFORMATION_MESSAGE, 
				MainP2.iconPic);
				
			invalid = calculate.CalculateDifference(year, userYear, dayOfYear, hour, minute, userDayOfYear, userHour, userMinute);
			//needed to pass numerous variables into the AlarmCalc object's method. False is returned if alarm is set in the past.
		} while (invalid==true);
	}
	
	private String whenIsIt() {
		if (dayOfYear == userDayOfYear && year == userYear)
			//Today means user input year and user input day are the same as today, this year.
			when = "today";
		else if ((dayOfYear == (userDayOfYear - 1) && year == userYear) || 
			((dayOfYear == 366 || dayOfYear == 365) && userDayOfYear == 1) && year == (userYear - 1))
			/*"Tomorrow" means user input date - 1 is today's date, this year is the same as input year.
			or, today is the last day of the year and user input is the first day of next year.
			*/
			when = "tomorrow";
		else if ((((userDayOfWeek == 7 && (week == userWeek && year == userYear)) || (userDayOfWeek == 7 && (week == 52 && userWeek == 1) && (year == userYear - 1))))
			|| (((userDayOfWeek == 1 && (week == userWeek - 1 && year == userYear)) || (userDayOfWeek == 1 && (week == 52 && userWeek == 2) && (year == userYear - 1)))))
			/*"This weekend" means: User input is Saturday, this week and this year is the same as user input year
			or, user input is the first Saturday of next year and this is the last week of the year
			...or...
			User input is Sunday, next week and this year is the same as user input year
			or, user input is the first Sunday of next year and this is the last week of the year
			*/
			when = "this weekend"; 
		else if (year == userYear && month == userMonth && week == userWeek)
			//If the user input is the same as the current year, month and week (and none of the above conditions were met), it's "this week".
			when = "this week";
		else if (year == userYear && month == userMonth)
			//If the user input is the same as the current year and month (and none of the above conditions were met), it's "this month".
			when = "this month";
		else if (year == userYear)
			//If the user input is the same as the current year (and none of the above conditions were met), it's "this year".
			when = "this year";
		else
			when = "a long time from now";
				
		return when;
	}
}