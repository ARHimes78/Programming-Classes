//Alan Himes
//ahimes1@cnm.edu
//Logger.h

#ifndef _LOGGER_H
#define _LOGGER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Logger {
    private:
        string filename;
        bool bLogOpen;
        char timeRightNow[20];
        int hour, min, sec, day, month, year;
        ofstream output;
        void Time();
        void FileName();
        string timeStamp();
    public:
        Logger();
        void StartLog(double initialBal);
        void WriteLog(string s);
        void CloseLog(string s);
        bool IsLogOpen() {return bLogOpen;}
};

#endif