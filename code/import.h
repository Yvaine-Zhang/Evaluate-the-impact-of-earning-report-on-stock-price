#include "stock.h"
#ifndef importdata_h
#define importdata_h
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;


typedef map<string, stock> StockMap;
typedef StockMap::iterator MapIterator;
typedef vector<string>::iterator VecIterator;

class CSVReader
{
	string fileName;
public:
	CSVReader(string filename) :fileName(filename){}

	void GetData(StockMap & stockinfo);
	void display(StockMap & stockinfo);
};



#endif // !
#pragma once

