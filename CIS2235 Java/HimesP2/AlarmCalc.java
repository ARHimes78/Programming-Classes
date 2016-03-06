import javax.swing.*;


public class AlarmCalc {
	private int i, daysBetweenYears;
	private long totalMinutes, totalUserMinutes, minutesDifference, hoursDifference, remainingMinutes;

	public AlarmCalc() {
		daysBetweenYears = 0;
	}
	
	public boolean CalculateDifference(int year, int userYear, int dayOfYear, int hour, int minute, int userDayOfYear, int userHour, int userMinute) {	
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
				
			if (totalUserMinutes - totalMinutes < 0) {
				JOptionPane.showMessageDialog(null, "Please enter a future time.", "That's in the past!", JOptionPane.INFORMATION_MESSAGE, MainP2.iconPic);
				return true;
			}
			else {
				minutesDifference = totalUserMinutes - totalMinutes;
				hoursDifference = minutesDifference / 60; //truncates remaining decimal amount
				remainingMinutes = minutesDifference % 60;
				JOptionPane.showMessageDialog(null, "The alarm will sound in:\n" + hoursDifference + 
						" hours and " + remainingMinutes + " minutes.", "Alarm Info", JOptionPane.INFORMATION_MESSAGE, MainP2.iconPic);
				return false;
			}
	}
}