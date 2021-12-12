#include <string>
#include <vector>
#include <unordered_map>
#include "Pipe.h"
#include "KC.h"


#ifndef Cast_H
#define	Cast_H

using std::string;
using std::vector;
using std::to_string;
using std::stoi;
using std::stof;
using std::unordered_map;

struct Cast
{
	static vector<vector<string>> ToVectorVectorsString(const unordered_map<int, Pipe> &pipes);
	static vector<vector<string>> ToVectorVectorsString(const unordered_map<int, KC> &KCs);
	template<class T>
	static unordered_map<int, T> ToVectorObject(const vector<vector<string>>& date)
	{
		return -1;
	}
	template<>
	static unordered_map<int, Pipe> ToVectorObject<Pipe>(const vector<vector<string>>& date)
	{
		unordered_map<int, Pipe> pipes; 
		int id; Pipe pipeBuf;
		for (int i = 1; i < date.size(); ++i)
		{
			id = stoi(date[i][0]);
			pipeBuf.lenght = stof(date[i][1]);
			pipeBuf.diameter = stoi(date[i][2]);
			pipeBuf.signRepair = date[i][3];
			pipes.emplace(id, pipeBuf);
		}
		return pipes;
	}
	template<>
	static unordered_map<int, KC> ToVectorObject<KC>(const vector<vector<string>>& date)
	{
		unordered_map<int, KC> KCs;
		int id; KC KCBuf;
		for (int i = 1; i < date.size(); ++i)
		{
			id = stoi(date[i][0]);
			KCBuf.name = date[i][1];
			KCBuf.numberWorkshops = stoi(date[i][2]);
			KCBuf.numberWorkshopsOperation = stoi(date[i][3]);
			KCBuf.effectiveness = stoi(date[i][4]);
			KCs.emplace(id, KCBuf);
		}
		return KCs;
	}
};

#endif


