#ifndef Graph_H
#define	Graph_H

#include <set>
#include <unordered_map>
#include <windows.h>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::unordered_map;
using std::set;
using std::pair;
using std::vector;


struct Graph
{
	unordered_map<int, set<int>> vertexes;
	unordered_map<int, pair<int, int>> edges;
	unordered_map<int, double> edgeWeights;
	void AddVertex(int number);
	void AddEdge(int number, pair<int, int> connection);
	void RemoveVertex(int number);
	void RemoveEdge(int number);
	int FindDegreeOutcome(int number);
	int FindIdEdges(int id1, int id2);
	unordered_map<int, int> TopologicalSorting();
	vector<int> FindingShortestPathDijkstra(int vertex1, int vertex2);
	

};

#endif

