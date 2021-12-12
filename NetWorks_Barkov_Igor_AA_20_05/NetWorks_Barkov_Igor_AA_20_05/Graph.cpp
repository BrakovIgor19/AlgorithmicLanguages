#include "Graph.h"

void Graph::AddVertex(int number)
{
	set<int> d = {};
	vertexes.emplace(number, d);
}

void Graph::AddEdge(int number, pair<int, int> connection)
{
	edges.emplace(number, connection);
	vertexes[connection.first].insert(number);
	vertexes[connection.second].insert(number);
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
	for (auto& [idVertex, edges]: vertexes)	
	{
		for (auto& idEdge: edges)
			if (idEdge == number)
			{
				++degreeOutcome;
			}
	}
	return degreeOutcome;
}
