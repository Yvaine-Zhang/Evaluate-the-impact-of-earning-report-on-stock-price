#ifndef TestPrintInExcel_h
#define TestPrintInExcel_h
#include "stdafx.h"
#include "BitsAndPieces\StringConversions.hpp"
#include "ExcelDriver.hpp"
#include "ExcelMechanisms.hpp"
#include "VectorsAndMatrices\Vector.cpp"
#include "VectorsAndMatrices\NumericMatrix.cpp" // Template
#include "ExceptionClasses\DatasimException.hpp"
#include <vector>
#include <string>
using namespace std;
Vector<double, long> DVector(vector<double> v);

int TestPrintInExcel(vector<double> CAAR_BEAT, vector<double> CAAR_MEET, vector<double> CAAR_MISS, vector<double> AAR_BEAT, vector<double> AAR_MEET, vector<double> AAR_MISS);

#endif
#pragma once
