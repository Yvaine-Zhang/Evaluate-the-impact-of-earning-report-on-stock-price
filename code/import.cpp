#include "import.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

void CSVReader::GetData(StockMap & stockinfo)
{
	ifstream file;
	file.open(fileName);
	string ticker, ann, start, end, actual, estimate, surprise, group;
	getline(file, ticker);
	while (file.good()) {
		stock stockinput;
		getline(file, ticker, ',');
		if (ticker == "") continue;
		getline(file, ann, ',');
		getline(file, start,',');
		getline(file, end, ',');
		getline(file, actual, ',');
		getline(file, estimate, ',');
		getline(file, surprise, ',');
		getline(file, group);
		stockinput.ann = ann;
		stockinput.start = start;
		stockinput.end = end; 
		stockinput.actual = stod(actual);
		stockinput.estimate = stod(estimate);
		stockinput.surprise = stod(surprise);
		stockinput.group = group;
		stockinfo[ticker] = stockinput;
	}
	file.close();
}

void CSVReader::display(StockMap & stockinfo)
{
	
	for (MapIterator it = stockinfo.begin(); it != stockinfo.end(); it++)
	{
		cout << "Key: " << it->first << "  " << "Values: " << it->second.group;
		cout << endl;
	}
}

