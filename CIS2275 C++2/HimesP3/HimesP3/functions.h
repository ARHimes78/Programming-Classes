#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <iostream>
#include <string>
#include "crowsolver.h"

using namespace std;

void AskPitcherDimensions(CrowSolver *crow, double &pitchDia, double &pitchHei);
void AskPebbleDiam(CrowSolver *crow, double &pebDia);
void AskCrowData(CrowSolver *crow, string &name, double &beakLen);
void Clear();

#endif