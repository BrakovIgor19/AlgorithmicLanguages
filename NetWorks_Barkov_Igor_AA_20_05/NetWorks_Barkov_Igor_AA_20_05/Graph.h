#include <set>
#include <unordered_map>
#include <windows.h>

using std::string;
using std::unordered_map;
using std::set;

#ifndef Graph_H
#define	Graph_H

struct Graph
{
	unordered_map<int, set<int>> vertexes;
	unordered_map<int, COORD> edges;
	void AddVertex(int number);
	void AddEdge(int number, COORD connection);
	void RemoveVertex(int number);
	void RemoveEdge(int number);
	int FindDegreeOutcome(int number);
};

#endif
