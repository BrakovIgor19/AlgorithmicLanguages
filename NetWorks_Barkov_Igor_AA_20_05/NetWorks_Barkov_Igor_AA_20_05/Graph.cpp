#include "Graph.h"

void Graph::AddVertex(int number)
{
	set<int> d = {};
	vertexes.emplace(number, d);
}

void Graph::AddEdge(int number, pair<int, int> connection)
{
	edges.emplace(number, connection);
	vertexes[connection.first].insert(connection.second);
	vertexes[connection.second].insert(connection.first);
}

void Graph::RemoveVertex(int number)
{ 
	std::vector<int> bufVector;
	for (auto& [id, edge] : edges)
	{
		if ((edge.first == number) || (edge.second == number))
		{
			bufVector.push_back(id);
		}
	}
	for (int i = 0; i < bufVector.size(); ++i)
	{
		edges.erase(bufVector[i]);
	}
	vertexes.erase(number);
}

void Graph::RemoveEdge(int number)
{
	
	for (auto& [id, edges]: vertexes)
	{
		edges.erase(number);
	}
	edges.erase(number);
}

int Graph::FindDegreeOutcome(int number)
{
	int degreeOutcome = 0; 
	for (auto& [id, pipe]: edges)
		if (pipe.first == number)
		{
			++degreeOutcome;
		}
	return degreeOutcome;
}

unordered_map<int, int> Graph::TopologicalSorting()
{
	unordered_map<int, int> sortingMap;
	int k = vertexes.size();
	Graph graph; graph.vertexes = this->vertexes; graph.edges = this->edges;
	int sizeVertexes = graph.vertexes.size();
	for (int i = 0; i < sizeVertexes; ++i)
	{
		for (auto& [id, Set] : graph.vertexes)
		{
			if (graph.FindDegreeOutcome(id) == 0)
			{
				sortingMap.emplace(id, k);
				--k;
				graph.RemoveVertex(id);
				break;
			}
		}
	}
	return sortingMap;
}
