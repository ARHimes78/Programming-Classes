#ifndef _CROWSOLVER_H
#define _CROWSOLVER_H

#include <iostream>
#include <string>
#include <cmath> //remove
#include <sstream> //remove
#include <iomanip> //remove
#include <limits> // remove
#include <ios> // remove


using namespace std;

class CrowSolver
{
    private:
        int caseNumber;
        double pitcherDia, pitcherHei;
        string crowName;
        double beakLength;
        double pebbleDia;
        int numPebbles;
        void CalcPebbles();

    public:
        CrowSolver();
        void SetPitcherDimensions(double dia, double hei);
        void SetCrowInfo(string name, double beak);
        void SetPebbleDiameter(double dia);
        int GetPebbles() {return numPebbles;};
        string GetDescription();
        bool abort;
};

#endif