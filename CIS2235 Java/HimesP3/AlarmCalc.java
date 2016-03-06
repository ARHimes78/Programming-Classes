import javax.swing.*;
import java.util.*;

public class AlarmCalc {

private Calendar calendar; //"now" calendar object
private Calendar userCalendar; //user input calendar object
private int hour, minute, month, date, year, week, dayOfYear;//these all pertain to "now".
private int userHour, userMinute, userMonth, userDate, userYear, userWeek, userDayOfYear, userDayOfWeek;
	//anything with "user" is from user input.
	
public static String when;
	//when is set to static so that it can be set to "in the past" in AlarmCalc if a time before the present has been entered.
private String[] array;
	
private int i, daysBetweenYears;
private long totalMinutes, totalUserMinutes, minutesDifference, hoursDifference; 
private long yearsDifference, daysDifference, remainingHours;
boolean leapYear;
	
	AlarmCalc() {
		currentTime();
		
		minutesDifference = 0;
		daysBetweenYears = 0;
		daysDifference = 0; 
		remainingHours = 0;
		yearsDifference = 0;
		daysDifference = 0;
		remainingHours = 0; 
		when = "";

	}
	
	private void currentTime() {
		calendar = new GregorianCalendar();
		userCalendar = new GregorianCalendar();
		
		hour = calendar.get(Calendar.HOUR_OF_DAY); //Upon construction, current time units variables are assigned.
		minute = calendar.get(Calendar.MINUTE);
		month = calendar.get(Calendar.MONTH);
		date = calendar.get(Calendar.DATE);
		year = calendar.get(Calendar.YEAR);
		week = calendar.get(Calendar.WEEK_OF_YEAR);
		dayOfYear = calendar.get(Calendar.DAY_OF_YEAR);
		
	}
	
	public void getTime(String userAmPm, String inputString) throws NumberFormatException, ArrayIndexOutOfBoundsException {
		
		array = inputString.split(",");
		//array elements are created from inputString
		userMonth = Math.abs(Integer.parseInt(array[0]) - 1); 
		//using absolute value in case of a negative number input
		userDate = Math.abs(Integer.parseInt(array[1]));
		userYear = Math.abs(Integer.parseInt(array[2]));
		userHour = Math.abs(Integer.parseInt(array[3]));
		userMinute = Math.abs(Integer.parseInt(array[4]));
		
		
			
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
	
	public String CalculateDifference(){
		
		for (i=year; i<userYear; i++) {
			//accumulate 365 days for each year between user input year and current year
			daysBetweenYears += 365;
			if ((i % 4 == 0 && i % 100 != 0) || (i % 100 == 0 && i % 400 == 0)) {
				//adding one additional day for every leap year between the years
				daysBetweenYears++;
			}
		}
				
		totalMinutes = (dayOfYear * 60 * 24) + (hour * 60) + minute;//taking all the variables and creating total minutes
		totalUserMinutes = (daysBetweenYears * 60 * 24) + (userDayOfYear * 60 * 24) + (userHour * 60) + userMinute;
			if ((totalUserMinutes - totalMinutes < 0) || userYear < year) {
				when = "in the past";
				return "Please enter a future time.";
			}
			else {
				if (((userYear % 4 == 0 && userYear % 100 != 0) || (userYear % 100 == 0 && userYear % 400 == 0)) && userCalendar.get(userCalendar.MONTH) >= 2)
					leapYear = true;
				else
					leapYear = false;
				
				minutesDifference = totalUserMinutes - totalMinutes;
				
				yearsDifference = userCalendar.get(userCalendar.YEAR) - calendar.get(userCalendar.YEAR);
				
				if (leapYear && userDayOfYear < dayOfYear - 1 || userDayOfYear < dayOfYear)
					--yearsDifference;
				
				if (userDayOfYear >= dayOfYear)
					daysDifference = userDayOfYear - dayOfYear;
				else {
					daysDifference = 365 - (dayOfYear - userDayOfYear);
					
				}
				
				remainingHours = (minutesDifference / 60) % 24;
				
				if (userHour <= hour && userMinute < minute) {
					if (daysDifference == 0){
						daysDifference = 364;
						--yearsDifference;
					}
					else
						--daysDifference;
				}
					
				return "The alarm will sound in: " + yearsDifference + 
						" years, " + daysDifference + " days, and " + remainingHours + " hours.";
				
			}	
	}
}
