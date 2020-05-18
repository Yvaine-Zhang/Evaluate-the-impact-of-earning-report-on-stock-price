//
//  CalFunction.h
//  Final
//
//  Created by zxy on 12/8/18.
//  Copyright © 2018 zxy. All rights reserved.
//

#ifndef CalFunction_h
#define CalFunction_h
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <map>
#include <ctime>
#include "matrix.h"
using namespace std;



//OVERLOADING
matrix operator -(const matrix &m1, const matrix &m2);

vector<double> operator+(const vector<double>& v1, const vector<double>& v2);

vector<double> operator/(const vector<double>& v1, long s);

vector<double> operator*(const vector<double>& v1, double s);

ostream& operator<<(ostream& os, const vector<double>& v);

//R
matrix R(matrix &type);

//AR
matrix AR(matrix RS, matrix RIWB);

//RANDOM
matrix Randomselect(matrix AR);

//AVERAGE
vector<double> average(const matrix & type);
//
matrix  Boot(matrix SAR);

#endif /* CalFunction_h */

