#include "stock.h"
#include "Retrieve.h"
#include "import.h"
#ifndef categorize_h
#define categorize_h

void datacheck(StockMap & stockinfo)
{
	for (MapIterator itr = stockinfo.begin(); itr != stockinfo.end();)
	{
		if (itr->second.Price.size() != 241) stockinfo.erase(itr++);
		else ++itr;
	}
}

void categorize(StockMap & stockinfo, map<string, double> & IWB, matrix & BEAT, matrix & MEET, matrix & MISS, matrix & IWB_BEAT, matrix & IWB_MEET, matrix & IWB_MISS)
{
	for (MapIterator itr = stockinfo.begin(); itr != stockinfo.end(); ++itr)
	{
		vector<double> IWBinput;
		if (itr->second.group == "BEAT")
		{
			BEAT.push_back(itr->second.Price);
			auto itr2 = IWB.find(itr->second.start.erase(10));
			for (unsigned int i = 0; i < itr->second.Price.size(); ++i, ++itr2)
			{
				IWBinput.push_back(itr2->second);
			}
			IWB_BEAT.push_back(IWBinput);
		}
		else if (itr->second.group == "MEET")
		{
			MEET.push_back(itr->second.Price);
			auto itr2 = IWB.find(itr->second.start.erase(10));
			for (unsigned int i = 0; i < itr->second.Price.size(); ++i, ++itr2)
			{
				IWBinput.push_back(itr2->second);
			}
			IWB_MEET.push_back(IWBinput);
		}

		else if (itr->second.group == "MISS")
		{
			MISS.push_back(itr->second.Price);
			auto itr2 = IWB.find(itr->second.start.erase(10));
			for (unsigned int i = 0; i < itr->second.Price.size(); ++i, ++itr2)
			{
				IWBinput.push_back(itr2->second);
			}
			IWB_MISS.push_back(IWBinput);
		}
	}
}


#endif
#pragma once

