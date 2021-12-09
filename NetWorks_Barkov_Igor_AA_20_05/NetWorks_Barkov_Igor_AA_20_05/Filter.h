#include <string>
#include <vector>

using std::string;
using std::vector;
using std::stoi;

#ifndef Filter_H
#define	Filter_H

struct Filter
{
	vector<int> PipeSignRepair(const vector<vector<string>> &date, const string &str);
	vector<int> KCEffectiveness(const vector<vector<string>>& date, int effectiveness);
};

#endif 