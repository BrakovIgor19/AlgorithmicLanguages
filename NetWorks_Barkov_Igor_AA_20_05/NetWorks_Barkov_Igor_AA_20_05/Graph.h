#include <set>
#include <unordered_map>
#include <windows.h>

using std::string;
using std::unordered_map;
using std::set;
using std::pair;

#ifndef Graph_H
#define	Graph_H

struct Graph
{
	unordered_map<int, set<int>> vertexes;
	unordered_map<int, pair<int, int>> edges;
	void AddVertex(int number);
	void AddEdge(int number, pair<int, int> connection);
	void RemoveVertex(int number);
	void RemoveEdge(int number);
	int FindDegreeOutcome(int number);
	unordered_map<int, int> TopologicalSorting();

};

#endif
