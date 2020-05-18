#include <string>
#include <vector>
#include "matrix.h"
using namespace std;

#ifndef stock_h
#define stock_h



struct stock
{
	string start;
	string end;
	string ann; //announcement date
	string group;
	double actual; //actual EPS
	double estimate;
	double surprise; //actual - estimate
	vector<string> Date;
	vector<double> Price;


};

#endif
#pragma once

