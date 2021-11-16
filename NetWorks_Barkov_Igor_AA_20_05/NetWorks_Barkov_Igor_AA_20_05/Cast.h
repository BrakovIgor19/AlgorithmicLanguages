#include <string>
#include <vector>
#include "Pipe.h"
#include "KC.h"


#ifndef Cast_H
#define	Cast_H

using std::string;
using std::vector;
using std::to_string;
using std::stoi;
using std::stof;

struct Cast
{
	static vector<vector<string>> ToVectorVectorsString(const vector<Pipe> &pipes);
	static vector<vector<string>> ToVectorVectorsString(const vector<KC> &KCs);
	template<class T>
	static vector<T> ToVectorObject(const vector<vector<string>>& date)
	{
		return -1;
	}
	template<>
	static vector<Pipe> ToVectorObject<Pipe>(const vector<vector<string>>& date)
	{
		vector<Pipe> pipes; pipes.reserve(date.size());
		Pipe pipeBuf;
		for (int i = 1; i < date.size(); ++i)
		{
			pipeBuf.id = stoi(date[i][0]);
			pipeBuf.lenght = stof(date[i][1]);
			pipeBuf.diameter = stoi(date[i][2]);
			pipeBuf.signRepair = date[i][3];
			pipes.push_back(pipeBuf);
		}
		return pipes;
	}
	template<>
	static vector<KC> ToVectorObject<KC>(const vector<vector<string>>& date)
	{
		vector<KC> KCs; KCs.reserve(date.size());
		KC KCBuf;
		for (int i = 1; i < date.size(); ++i)
		{
			KCBuf.id = stoi(date[i][0]);
			KCBuf.name = date[i][1];
			KCBuf.numberWorkshops = stoi(date[i][2]);
			KCBuf.numberWorkshopsOperation = stoi(date[i][3]);
			KCBuf.effectiveness = stoi(date[i][4]);
			KCs.push_back(KCBuf);
		}
		return KCs;
	}
};

#endif


