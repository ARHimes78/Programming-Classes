//File: Date.cpp
//Modified for CIS 2277 Program 1
//Tuesday, Aug 27, 2013
#include "stdafx.h"
#include <string>
#include <ctime>
#include <sstream>
#include "Date.h"

using namespace std;

Date::Date()
{
	//Set the Date variables to the computer's date.
        
        
	time_t rawtime;
	tm OStime;
	bValidDate = true;

	time(&rawtime);

	//Old Way p.389
	//OStime = localtime(&rawtime);

	//New way, not deprecated
	localtime_s(&OStime, &rawtime);

	month = OStime.tm_mon + 1;
	day = OStime.tm_mday;
	year = OStime.tm_year + 1900;

	description = "Today's Date";
        DetermineLeapYear();
        InitializeDayCount();//added
	CalcDayOfYear();
}


Date::Date(int m, int d, int y, string desc)
{
	SetDate(m, d, y, desc);
}


void Date::SetDate(int m, int d, int y, string desc)
{
	month = m;
	day = d;
	year = y;
	description = desc;
	DetermineLeapYear();
        InitializeDayCount();//added
	CalcDayOfYear();
        
        ValidateThisDate();//sets bValidDate which can be retreived with isValidateDate.

}


void Date::SetDate(Date dt)
{
	month = dt.GetMonth();
	day = dt.GetDay();
	year = dt.GetYear();
	description = dt.GetDesc();
	DetermineLeapYear();
        InitializeDayCount();//added
	CalcDayOfYear();
        
        ValidateThisDate();//sets bValidDate which can be retreived with isValidateDate.
}


string Date::GetFormattedDate()
{
	stringstream strDate;
	strDate << description;
	
	string monName[12] = {"January", "February", "March",
		"April", "May", "June", "July", "August", 
		"September", "October", "November", "December"};


	strDate << ": " << monName[month-1] << " " << day 
			<< ", " << year;

	return strDate.str();
}


void Date::ValidateThisDate() {
    if (day <= dayCount[month-1] && (month >= 1 || month <= 12)) 
        bValidDate = true;
    else if (day <= 29 && month == 2 && bLeap)
        bValidDate = true;
    else
        bValidDate = false;
}

string Date::GetDateStatus(){
    if (!bValidDate)
        dateStatus = "Invalid date!";
    else
        dateStatus = GetFormattedDate();
        
    return dateStatus;
}

void Date::CalcDayOfYear()
{
	//set up array of days in each month
	//for non-leap year year
	/*int dayCount[12] = {31,28,31,30,31,30,
		31,31,30,31,30,31};*/
        //Changed dayCount[] to global scope to use in ValidateThisDate().
        //it's being initialized in its own method.
	dayOfYear = 0;

	//add the days up to the previous month
	for(int i = 1; i < month; ++i)
	{
		dayOfYear += dayCount[i-1];

		//if adding Feb, check if leap year
		if(i == 2 && bLeap == true)
			dayOfYear += 1;

	}

	dayOfYear += day;
}

void Date::DetermineLeapYear()
{
	//A year is a leap year if it is divisible by four, 
	//unless it is a century date (i.e,  1900). 
	//If it is a century date, it is a leap year only 
	//if it is divisible by 400 (i.e., 2000).

	if(year%4 == 0 && year % 100 != 0)
		bLeap = true;
	else if(year % 400 == 0)
		bLeap = true;
	else
		bLeap = false;
}

void Date::InitializeDayCount() {
    int tempDayCount[12] = {31,28,31,30,31,30,
            31,31,30,31,30,31};
                
        int i;
        for (i=0; i<12; ++i)
            dayCount[i] = tempDayCount[i];
        //initializing dayCount here.
}