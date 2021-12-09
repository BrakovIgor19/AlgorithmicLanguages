#include "Graph.h"

void Graph::AddVertex(int number)
{
	set<int> d = {};
	vertexes.emplace(number, d);
}

void Graph::AddEdge(int number, COORD connection)
{
	edges.emplace(number, connection);
}

void Graph::RemoveVertex(int number)
{
	for (auto& x: edges)
	{
		if ((x.second.X == number) || (x.second.Y == number));
		edges.erase(x.first);
		break;
	}
	vertexes.erase(number);
}

void Graph::RemoveEdge(int number)
{
	edges.erase(number);
}

int Graph::FindDegreeOutcome(int number)
{
	int degreeOutcome = 0;
	for (auto& x: vertexes.find(number)->second)
	{
		for (auto& y : edges)
		{
			if (y.second.X == number)
			{
				++degreeOutcome;
			}
		}
	}
	return degreeOutcome;
}
