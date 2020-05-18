#define _CRT_SECURE_NO_WARNINGS
#include "import.h"
#include "TestPrintInExcel.h"
#include "Retrieve.h"
#include "stock.h"
#include "matrix.h"
#include "Calculate.h"
#include "Categorize.h"
#include <stdio.h>
#include <string> 
#include <iostream>
#include <sstream>  
#include <vector>
#include <map>
#include <locale>
#include <iomanip>
#include "curl.h"
#include "stdafx.h"

using namespace std;
 
bool isnum(string s)
{
	stringstream sin(s);
	double t;
	char p;
	if (!(sin >> t))

		return false;
	if (sin >> p)
		return false;
	else
		return true;
}

int main()

{
	StockMap stockinfo;
	map<string, double> IWB;
	matrix BEAT;
	matrix MEET;
	matrix MISS;
	matrix IWB_BEAT;
	matrix IWB_MEET;
	matrix IWB_MISS;



	vector<double> aveAAR_MEET(240);
	vector<double> aveCAAR_MEET(240);
	vector<double> aveAAR_BEAT(240);
	vector<double> aveCAAR_BEAT(240);
	vector<double> aveCAAR_MISS(240);
	vector<double> aveAAR_MISS(240);


	bool a = true;
	int attempt = 0;
	while (a)
	{	
		string str;
		cout << endl;
		cout << "Pick a choice from the list:" << endl << endl
			<< "1.Retrieve historical price data for all stocks" << endl
			<< "2.Pull information for one stock from one group" << endl
			<< "3.Show AAR or CAAR for one group" << endl
			<< "4.Show the excel graph with CAAR for all 3 groups" << endl
			<< "5.Exit your program" << endl << endl;
		cin >> str;

		int answer;
		if (isnum(str))
		{
			answer = std::stoi(str);
		}
		else { answer = 100; }

		if (attempt == 0 && answer != 1 && answer != 5)
		{
			cout << endl << "please retrieve data first, PRESS 1" << endl;
			answer = 100;
		}

		switch (answer)
		{
		case 1:
		{
			cout << endl << "Retrieving historical price data for all stocks..." << endl << endl;

			CSVReader reader("StructData.csv");

			reader.GetData(stockinfo);// populate the maps; [ticker: start, end, group]

			GetStock(stockinfo);
			GetIWB(IWB);

			datacheck(stockinfo);
			categorize(stockinfo, IWB, BEAT, MEET, MISS, IWB_BEAT, IWB_MEET, IWB_MISS);

			matrix stockR_MISS = R(MISS);
			matrix IWBR_MISS = R(IWB_MISS);
			//AR  *3
			matrix SAR_MISS = AR(stockR_MISS, IWBR_MISS);
			//BOOT *3
			matrix outcome_MISS = Boot(SAR_MISS);
			aveAAR_MISS = outcome_MISS[0];
			aveCAAR_MISS = outcome_MISS[1];

			matrix stockR_BEAT = R(BEAT);
			matrix IWBR_BEAT = R(IWB_BEAT);
			//AR  *3
			matrix SAR_BEAT = AR(stockR_BEAT, IWBR_BEAT);
			//BOOT *3
			matrix outcome_BEAT = Boot(SAR_BEAT);
			aveAAR_BEAT = outcome_BEAT[0];
			aveCAAR_BEAT = outcome_BEAT[1];


			matrix stockR_MEET = R(MEET);
			matrix IWBR_MEET = R(IWB_MEET);
			//AR  *3
			matrix SAR_MEET = AR(stockR_MEET, IWBR_MEET);
			//BOOT *3
			matrix outcome_MEET = Boot(SAR_MEET);
			aveAAR_MEET = outcome_MEET[0];
			aveCAAR_MEET = outcome_MEET[1];

			cout << "Retrieve successfully! Thank you for your patience!" << endl << endl;
			attempt++;
			break;
		}
		case 2:
		{
			cout << endl << "Please input stock ticker" << endl << endl;
			string ticker_y;
			cin >> ticker_y;
			bool flag = false;
			for (auto it = stockinfo.begin(); it != stockinfo.end(); ++it)
			{
				if (it->first == ticker_y) { flag = true; break; }
			}
			if (flag == true)
			{
				cout << "StartTime: " << stockinfo[ticker_y].start << endl
					<< "EndTime: " << stockinfo[ticker_y].end.erase(10) << endl
					<< "Announcement Date: " << stockinfo[ticker_y].ann << endl
					<< "Group: " << stockinfo[ticker_y].group << endl
					<< "Actual EPS: " << stockinfo[ticker_y].actual << endl
					<< "Estimate EPS: " << stockinfo[ticker_y].estimate << endl
					<< "Surprise: " << stockinfo[ticker_y].surprise << endl << endl;
				cout << "Date" << "        " << "Price" << endl;
				for (unsigned int i = 0; i < stockinfo[ticker_y].Price.size(); ++i)
				{
					cout << stockinfo[ticker_y].Date[i] << "  " << stockinfo[ticker_y].Price[i] << endl;
				}
			}
			else { cout << "Sorry, the information for this stock is missing here!" << endl; break; }
			break;
		}
		case 3:
		{
			string str_3;
			cout <<endl << "Show AAR or CAAR:" << endl
				<< "1.AAR" << endl
				<< "2.CAAR" << endl << endl;
			cin >> str_3;
			int answer;
			if (isnum(str_3))
			{
				answer = std::stoi(str_3);
			}
			else { answer = 100; }
			switch (answer)
			{
			case 1:
			{
				string str_1;
				cout <<endl << "Select the group:" << endl
					<< "1.BEAT" << endl
					<< "2.MEET" << endl
					<< "3.MISS" << endl<<endl;
				cin >> str_1;
				int answer_group;
				if (isnum(str_1))
				{
					answer_group = std::stoi(str_1);
				}
				else { answer_group = 100; }
				cout << answer_group << endl;
				switch (answer_group)
				{
				case 1:
					cout << aveAAR_BEAT << endl;
					break;
				case 2:
					cout << aveAAR_MEET << endl;
					break;

				case 3:

					cout << aveAAR_MISS << endl;
					break;
				default:
					cout << "Bad choice! Please try again: ";
				}
				break;
			}
			case 2:
			{
				string str_1;
				cout << endl << "Select the group:" << endl
					<< "1.BEAT" << endl
					<< "2.MEET" << endl
					<< "3.MISS" << endl << endl;
				cin >> str_1;
				int answer_group;
				if (isnum(str_1))
				{
					answer_group = std::stoi(str_1);
				}
				else { answer_group = 100; }
				switch (answer_group)
				{
				case 1:
					cout << aveCAAR_BEAT << endl;
					break;
				case 2:
					cout << aveCAAR_MEET << endl;
					break;
				case 3:
					cout << aveCAAR_MISS << endl;
					break;
				default:
					cout <<endl << "Bad choice! Please try again: ";
				}
				break;
			}
			default:
				cout <<endl << "Bad choice! Please try again: ";
			}
			break;
		}

		case 4:
		{

			TestPrintInExcel(aveCAAR_BEAT, aveCAAR_MEET, aveCAAR_MISS, aveAAR_BEAT, aveAAR_MEET, aveAAR_MISS);
			break;
		}
		case 5:
			a = false;
			cout << endl << "successfully exit!" << endl << endl;
			exit(0);
			break;
		default:
			cout << endl << "Bad choice! Please try again: " << endl;

		}
	}
	//system("pause");
	return 0;

}
