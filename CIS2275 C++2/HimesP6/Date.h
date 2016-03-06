//File: Date.h
//Modified for CIS 2277 Program 1

#ifndef _DATE_H
#define _DATE_H

#include <string>
using namespace std;

class Date
{
	private:
			int month, day, year;
			string description;
			int dayOfYear;
			bool bLeap;
            int dayCount[12];//added, moved from CalcDayOfYear().
            string dateStatus;
            bool bValidDate;//added
			void CalcDayOfYear();
			void DetermineLeapYear();
            void InitializeDayCount();//added
                        

	public:
			Date();
			Date(int m, int d, int y, string desc);

			void SetDate(int m, int d, int y, string desc);
            void SetDate(Date dt);
			void SetDesc(string d){ description = d; }

			string GetFormattedDate();

			int GetDayOfYear(){ return dayOfYear;}
			int GetYear(){ return year;}
			int GetMonth(){ return month;}
			int GetDay(){ return day;}
			string GetDesc() { return description; }
			bool isLeapYear(){ return bLeap; }
            bool isValidDate(){ return bValidDate; }

			void ValidateThisDate();//added functions
            string GetDateStatus();//

			bool operator > (const Date d);
			bool operator < (const Date d);
			int operator - (const Date d);
};

#endif