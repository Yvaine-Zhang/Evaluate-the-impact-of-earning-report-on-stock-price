
//TestMatrixExcel.cpp
//
// Test output of a matrix in Excel. Here we 
// use the Excel Driver object directly.
//
// (C) Datasim Education BV 2006
//

#include "stdafx.h"
#include "Calculate.h"
#include "BitsAndPieces\StringConversions.hpp"
#include "ExcelDriver.hpp"
#include "ExcelMechanisms.hpp"
#include "VectorsAndMatrices\NumericMatrix.cpp" // Template
#include "ExceptionClasses\DatasimException.hpp"
#include <vector>
#include <string>
using namespace std;
Vector<double, long> DVector(vector<double> v)
{

	Vector<double, long> v_d(v.size(), 0);
	for (long i = v_d.MinIndex(); i <= v_d.MaxIndex(); i++)
	{
		v_d[i] = v[i];
	}
	return v_d;
}
int TestPrintInExcel(vector<double> CAAR_BEAT, vector<double> CAAR_MEET, vector<double> CAAR_MISS, vector<double> AAR_BEAT, vector<double> AAR_MEET, vector<double> AAR_MISS)
{
	Vector<double, long> xarr(240);
	list<std::string> labels;
	labels.push_back("CAAR BEAT");
	labels.push_back("CAAR MEET");
	labels.push_back("CAAR MISS");
	list<Vector<double, long> > yarr;
	list<std::string> labels_2;
	labels_2.push_back("CAAR_BEAT");
	labels_2.push_back("CAAR_MEET");
	labels_2.push_back("CAAR_MISS");
	labels_2.push_back("ARR_BEAT");
	labels_2.push_back("ARR_MEET");
	labels_2.push_back("ARR_MISS");

	yarr.push_back(DVector(CAAR_BEAT));
	yarr.push_back(DVector(CAAR_MEET));
	yarr.push_back(DVector(CAAR_MISS));

	list<Vector<double, long> > yarr_table;
	yarr_table.push_back(DVector(CAAR_BEAT));
	yarr_table.push_back(DVector(CAAR_MEET));
	yarr_table.push_back(DVector(CAAR_MISS));
	yarr_table.push_back(DVector(AAR_BEAT));
	yarr_table.push_back(DVector(AAR_MEET));
	yarr_table.push_back(DVector(AAR_MISS));

	for (long i = xarr.MinIndex(); i <= xarr.MaxIndex(); i++)
	{
		xarr[i] = i - 120;
	}

	std::string sheetName("CAAR");

	ExcelDriver& excel = ExcelDriver::Instance();
	excel.MakeVisible(true);		// Default is INVISIBLE!

	try
	{
		printInExcel(xarr, labels, yarr, "CAAR", "T", "CAAR");
		excel.CreateC(xarr, labels_2, yarr_table, "T");
	}
	catch (DatasimException& e)
	{
		e.print();
	}
	catch (...)
	{
		// Catches everything else
	}

	getchar();
	return 0;
}
