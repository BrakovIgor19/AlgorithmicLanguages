#include"Cast.h"

vector<vector<string>> Cast::ToVectorVectorsString(const unordered_map<int, Pipe>& pipes)
{
	vector<vector<string>> date; date.reserve(pipes.size());
	vector<string> strDateBuf; strDateBuf.resize(4);
	for (auto& [id, pipe]: pipes)
	{
		strDateBuf[0] = to_string(id);
		strDateBuf[1] = to_string(pipe.lenght);
		strDateBuf[2] = to_string(pipe.diameter);
		strDateBuf[3] = pipe.signRepair;
		date.push_back(strDateBuf);
	}
	return date;
}

vector<vector<string>> Cast::ToVectorVectorsString(const unordered_map<int, KC>& KCs)
{
	vector<vector<string>> date; date.reserve(KCs.size());
	vector<string> strDateBuf; strDateBuf.resize(5);
	for (auto& [id, kc] : KCs)
	{
		strDateBuf[0] = to_string(id);
		strDateBuf[1] = kc.name;
		strDateBuf[2] = to_string(kc.numberWorkshops);
		strDateBuf[3] = to_string(kc.numberWorkshopsOperation);
		strDateBuf[4] = to_string(kc.effectiveness);
		date.push_back(strDateBuf);
	}
	return date;
}


