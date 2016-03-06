//Alan Himes
//ahimes1@cnm.edu
//Logger.cpp

#include "stdafx.h"
#include "Logger.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;
        
Logger::Logger() {
    Time();
    FileName();
    
    bLogOpen = true;
    
    output.open(filename);
    
    output << "Blackjack log\n" << endl;
    output << "Time: " << timeStamp() << "\t";
}



void Logger::StartLog(double initialBal) {
    stringstream ssStartBalance;
    
    ssStartBalance << "Starting balance - $" << initialBal << "\n" << endl;
    
    output << ssStartBalance.str();
}

void Logger::WriteLog(string s) {
    stringstream ssGameCompleted;
    
    Time();
    
    ssGameCompleted << "Time: " << timeStamp() << " " << s << "\n" << endl;
    
    output << ssGameCompleted.str();
}

void Logger::CloseLog(string s) {
    stringstream ssGameEnd;
    bLogOpen = false;
    Time();
    
    ssGameEnd << s << endl;
    
    output << ssGameEnd.str();
    output.close();
}

void Logger::Time() {
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);
    
    int i;
    
    for (i=0; i<20; ++i)
        timeRightNow[i] = 0;
        
    strftime(timeRightNow, 20, "%m_%d_%Y_%H_%M_%S", localtime(&in_time_t));
    
    
    //assigning the values to the time unit ints from characters in the char array
    char timeUnit[4] = {0};
    
    for (i=11; i<13; ++i)
        timeUnit[i - 11] = timeRightNow[i];
        
    hour = atoi(timeUnit);
    
    for (i=14; i<16; ++i)
        timeUnit[i - 14] = timeRightNow[i];
    
    min = atoi(timeUnit);
    
    for (i=17; i<19; ++i)
        timeUnit[i - 17] = timeRightNow[i];
        
    sec = atoi(timeUnit);
    
    for (i=3; i<5; ++i)
        timeUnit[i - 3] = timeRightNow[i];
        
    day = atoi(timeUnit);
    
    for (i=0; i<2; ++i)
        timeUnit[i] = timeRightNow[i];
    
    month = atoi(timeUnit);
    
    for (i=6; i<10; ++i)
        timeUnit[i - 6] = timeRightNow[i];
    
    year = atoi(timeUnit);
}

void Logger::FileName() {
    stringstream ssFileName;
    
    ssFileName << "Log_" << timeRightNow << ".txt";
    
    filename = ssFileName.str();
}

string Logger::timeStamp() {
    stringstream ssTimeStamp;
    
    /*zeroMin and zeroSec add the extra zero for min and sec less than 10
    so time doesn't look weird on the txt file.*/
    
    string zeroMin;
    string zeroSec;
    
    if (min < 10)
        zeroMin = "0";
    else
        zeroMin = "";
    
    if (sec < 10)
        zeroSec = "0";
    else
        zeroSec = "";
        
    ssTimeStamp << hour << ":" << zeroMin << min << ":" << zeroSec << sec;
    return ssTimeStamp.str();
}