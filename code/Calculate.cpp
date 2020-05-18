//
//  Calculate.cpp
//  Final
//
//  Created by zxy on 12/8/18.
//  Copyright © 2018 zxy. All rights reserved.
//

#include "Calculate.h"
#include <iostream>
#include <algorithm>    // random_shuffle    

using namespace std;

matrix operator-(const matrix &m1, const matrix &m2)
{
	long a = m1.size();
	long b = m1[0].size();
	matrix m3;
	m3.resize(a);
	for (long i = 0; i < a; i++)
	{
		m3[i].resize(b);
		for (int j = 0; j < b; j++)
			m3[i][j] = m1[i][j] - m2[i][j];
	}
	return m3;
}
vector<double> operator+(const vector<double>& v1, const vector<double>& v2)
{
	long s = v1.size();
	vector<double> U(s);
	for (long i = 0; i < s; i++) U[i] = v1[i] + v2[i];
	return U;
}

vector<double> operator/(const vector<double>& v1, long s)
{
	long z = v1.size();
	vector<double> U(z);
	for (long i = 0; i < z; i++) U[i] = v1[i] / s;
	return U;
}

vector<double> operator*(const vector<double>& v1, double s)
{
	long z = v1.size();
	vector<double> U(z);
	for (long i = 0; i < z; i++) U[i] = s * v1[i];
	return U;
}

ostream& operator<<(ostream& os, const vector<double>& v)
{
	os << " ";
	for (unsigned int i = 0; i < v.size(); i++) {
		os << v[i];
		if (i != v.size())
			os << ", ";
	}
	os << "\n";
	return os;
}

matrix R(matrix &type)
{
	long a = type.size();
	long b = type[0].size();
	matrix RS(a);
	for (long i = 0; i < a; i++)
	{
		RS[i].resize(b - 1);
		for (int j = 0; j < b - 1; j++)
			RS[i][j] = (type[i][j + 1] - type[i][j]) / type[i][j];
	}
	return RS;
}

matrix AR(matrix RS, matrix RIWB)
{
	matrix AR = RS - RIWB;
	return AR;
}

matrix Randomselect(matrix AR)
{
	int a = 100;
	int d = AR.size();
	matrix randAR;
	srand(unsigned(time(NULL)));
	vector<int> L(a);
	for (int i = 0; i < a; i++)
	{
		L[i] = rand() % d;
		for (int j = 0; j < i; j++)
		{
			if (L[i] == L[j])
			{
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < a; i++)
	{
		randAR.push_back(AR[L[i]]);
	}
	return randAR;
}

vector<double> average(const matrix & type)
{
	vector<double> averesult = type[0];
	for (unsigned int i = 1; i < type.size(); i++) {
		averesult = averesult + type[i];
	}
	averesult = averesult / type.size();
	return averesult;
}

matrix  Boot(matrix SAR)
{

	matrix Averesult;
	vector<double> AveAAR(240);
	vector<double> AveCAAR(240);
	for (int i = 0; i < 5; i++)
	{
		matrix selectS = Randomselect(SAR);
		Calculation Calculation1(selectS);
		vector<double> SelectAAR = Calculation1.AAR();
		vector<double> SelectCAAR = Calculation1.CAAR();
		AveAAR = AveAAR * (i / (i + 1.0)) + SelectAAR / (i + 1);
		AveCAAR = AveCAAR * (i / (i + 1.0)) + SelectCAAR / (i + 1);
	}
	Averesult.push_back(AveAAR);
	Averesult.push_back(AveCAAR);
	return Averesult;
}


//AAR
vector<double>  Calculation::AAR()
{
	vector<double> AAR1 = average(selectAR);
	return AAR1;
}
//CAAR
vector<double>  Calculation::CAAR()
{
	//vector<double> AAR2 = average(selectAR);
	vector<double> AAR2 = this->AAR();
	vector<double> CAAR1(AAR2.size());
	CAAR1[0] = AAR2[0];
	for (unsigned int i = 1; i < AAR2.size(); ++i)
	{
		CAAR1[i] = CAAR1[i - 1] + AAR2[i];
	}
	return CAAR1;
}

