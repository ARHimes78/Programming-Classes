#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>
#include "CPPTrainTickets.h"
#include "Date.h"
	
	/*
	string reservation; //passenger name for this reservation
	string errorString; //string containing error information
	int numberOfPass; //number of passengers booked under this res
	Date book, dep, ret; //pertinent date pbjects
	bool bRoundTrip, bValidDate;
	string DepartureCity, dateString;
	float fare;
	*/
	
	CPPTrainTickets::CPPTrainTickets() : reservation(""), errorString(""), numberOfPass(1), bRoundTrip(false), 
		DepartureCity("Albuquerque"), dateString(""), fare(0) {
		//construtors in this file use C++11 constructors.
		//DepartureCity is set to Albuquerque because its radio button is selected by default.
	}

	CPPTrainTickets::CPPTrainTickets(string resN, int nPass, Date bk, Date dpt, Date rtn) : reservation(resN), 
		numberOfPass(nPass), DepartureCity("Albuquerque"), bRoundTrip(true) {
		noName();
		SetDates(bk, dpt, rtn);//might as well use SetDates().
	}
        
    CPPTrainTickets::CPPTrainTickets(string resN, int nPass, Date bk, Date dpt) : reservation(resN),
		numberOfPass(nPass), DepartureCity("Albuquerque"), bRoundTrip(false) {
		//this is the non-roundtrip constructor.
        noName();
		SetDates(bk, dpt);
	}

	void CPPTrainTickets::SetDates(Date bk, Date dpt, Date rtn) {
		book = bk;
		dep = dpt;
		ret = rtn;
		ValidateDate();
	}

	void CPPTrainTickets::SetDates(Date bk, Date dpt) {
		book = bk;
		dep = dpt;
        ValidateDate();
	}

	string CPPTrainTickets::GetReservationDescription() {
		/*Whatever this function returns will populate the summary text area:
		the reservation info string or an error if the dates are set incorrectly.
		*/
        if (!bValidDate)
            return errorString;
        else {
            stringstream reservationData;
                
            if (bRoundTrip)
                reservationData << "ROUND TRIP" << endl;

			reservationData << dateString << endl
				<< "Name on reservation: " << reservation << endl
				<< "Number of passengers: " << numberOfPass << endl
				<< "City of departure: " << DepartureCity << endl
				<< "Fare: $" << fare << endl;
                    
            return reservationData.str();
        }
	}

	void CPPTrainTickets::CalculateFare() {
            float fare2 = 0;
            
            fare = Calculate(dep);
            
            if (bRoundTrip)
                fare2 = Calculate(ret);
            
            fare = (fare + fare2) * numberOfPass;
	}

	void CPPTrainTickets::ValidateDate() {
		/*creates either an error string or a date string (round trip or non-round trip).
		If it's a date string, the fare is also calculated, so everything will have been taken care of
		in the constructor, except for setting the city of departure.
		*/
			
        stringstream tripDates;
            
        if (bRoundTrip) {
            if (!dep.isValidDate() || !ret.isValidDate()) {
                errorString = "Invalid date!";
                bValidDate = false;
            }
            else if (dep < book){//using overloaded operators, code changed in these if conditions.
                errorString = "Departure date set before booking date!\n";
                bValidDate = false;
            }
			else if (ret < dep){
                errorString = "Return date set before departure date!\n";
                bValidDate = false;
            }
            else if (ret < book){
                errorString = "Return date set before booking date!\n";
                bValidDate = false;
            }
            else {
                    
                tripDates << dep.GetDateStatus() << endl
                    << ret.GetDateStatus();
                dateString = tripDates.str();
                CalculateFare();
                bValidDate = true;
            }
        }
        else {
            if (!dep.isValidDate()) {
                errorString = "Invalid date!";
                bValidDate = false;
            }
            else if (dep.GetDayOfYear() < book.GetDayOfYear() && dep.GetYear() == book.GetYear()) {
                errorString = "Departure date set before booking date!\n";
                bValidDate = false;
            }
            else {
                tripDates << dep.GetDateStatus();
                dateString = tripDates.str();
                CalculateFare();
                bValidDate = true;
            }
        }
	}
        
        float CPPTrainTickets::Calculate(Date trip) {
			/*Created this function for CalculateFare() to calculate the departure price and, 
			if round trip, also the return price, which would require repeating this code.*/

            float f;
            //int daysDifference; <--Don't need this anymore
            
			/*
			This code from the previous version has basically been moved to the operator - method in Date.cpp.

            if (book.GetYear() == trip.GetYear()) {
                daysDifference = trip.GetDayOfYear() - book.GetDayOfYear();
                
            }
            else {
            //departure or return date is next year
                if (book.isLeapYear())
                    daysDifference = (366-book.GetDayOfYear()) + trip.GetDayOfYear();
                else
                    daysDifference = (365-book.GetDayOfYear()) + trip.GetDayOfYear();
            }
            */

            if (book - trip >= 30)//changed code with overloaded operator
                f = 39;
            else if (book - trip >= 14 && book - trip < 30)
                f = 79;
            else
                f = 129;
                
            return f;
        }

		void CPPTrainTickets::noName() {
			//In case the name field is left blank.
			if (reservation == "")
				reservation = "UNKNOWN";
		}