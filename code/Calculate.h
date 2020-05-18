#pragma once
//
//  Calculate.hpp
//  Final
//
//  Created by zxy on 12/8/18.
//  Copyright ?2018 zxy. All rights reserved.
//

#ifndef Calculate_h
#define Calculate_h
#include "CalFunction.h"
#include <stdio.h>
#include <vector>

#include "matrix.h"
using namespace std;



class Calculation
{
public:
	matrix selectAR;

	Calculation(matrix selectAR_) { selectAR = selectAR_; }

	vector<double> AAR();
	vector<double> CAAR();

};

#endif /* Calculate_hpp */

