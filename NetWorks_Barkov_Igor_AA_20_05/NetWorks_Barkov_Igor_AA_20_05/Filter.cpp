#include "Filter.h"

vector<int> Filter::PipeSignRepair(const vector<vector<string>> &date, const string &str)
{
	vector<int> filterPipes; filterPipes.reserve(date.size());
	for (int i = 0; i < date.size(); ++i)
	{
		if (date[i][3] == str)
		{
			filterPipes.push_back(i);
		}
	}
	return filterPipes;
}

vector<int> Filter::KCEffectiveness(const vector<vector<string>> &date, int effectiveness)
{
	vector<int> filterKCs; filterKCs.reserve(date.size());
	for (int i = 0; i < date.size(); ++i)
	{
		if (stoi(date[i][4]) >= effectiveness)
		{
			filterKCs.push_back(i);
		}
	}
	return filterKCs;
}
