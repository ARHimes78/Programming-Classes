#ifndef _CPPTRAINTICKETS_H
#define _CPPTRAINTICKETS_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class CPPTrainTickets {

	private:

	string reservation; //passenger name for this reservation
	string errorString; //string containing error information
	int numberOfPass; //number of passengers booked under this res
	Date book, dep, ret; //pertinent date pbjects
        //book = TODAY
	bool bRoundTrip, bValidDate;
	string DepartureCity, dateString;
	float fare;
	void CalculateFare();
	void ValidateDate();
    float Calculate(Date trip);
	void noName();

	public:

	CPPTrainTickets();
	CPPTrainTickets(string resN, int nPass, Date bk, Date dpt, Date rtn);
        CPPTrainTickets(string resN, int nPass, Date bk, Date dpt);
	void SetNumberOfPass(int n){numberOfPass = n;} //how many people?
	void SetDepartingCity(string city){DepartureCity = city;}// ABQ or CHI
	void SetDates(Date bk, Date dpt, Date rtn);
	void SetDates(Date bk, Date dpt);
	void SetReservationName(string name){reservation = name;}
        void SetRoundTrip(bool rt){bRoundTrip = rt;}
        bool isRoundTrip() {return bRoundTrip; }
	float GetTotalFare(){return fare;}
	string GetReservationDescription();
};

#endif