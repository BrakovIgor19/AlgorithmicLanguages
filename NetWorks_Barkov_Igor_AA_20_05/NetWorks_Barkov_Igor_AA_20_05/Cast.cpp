#include"Cast.h"

vector<vector<string>> Cast::ToVectorVectorsString(const vector<Pipe> &pipes)
{
	vector<vector<string>> date; date.reserve(pipes.size());
	vector<string> strDateBuf; strDateBuf.reserve(4);
	for (int i = 0; i < pipes.size(); ++i)
	{
		strDateBuf[0] = to_string(pipes[i].id);
		strDateBuf[1] = to_string(pipes[i].lenght);
		strDateBuf[2] = to_string(pipes[i].diameter);
		strDateBuf[3] = pipes[i].signRepair;
		date.push_back(strDateBuf);
	}
	return date;
}

vector<vector<string>> Cast::ToVectorVectorsString(const vector<KC> &KCs)
{
	vector<vector<string>> date; date.reserve(KCs.size());
	vector<string> strDateBuf; strDateBuf.reserve(5);
	for (int i = 0; i < KCs.size(); ++i)
	{
		strDateBuf[0] = to_string(KCs[i].id);
		strDateBuf[1] = KCs[i].name;
		strDateBuf[2] = to_string(KCs[i].numberWorkshops);
		strDateBuf[3] = to_string(KCs[i].numberWorkshopsOperation);
		strDateBuf[4] = to_string(KCs[i].effectiveness);
		date.push_back(strDateBuf);
	}
	return date;
}


