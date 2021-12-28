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

vector<int> Graph::FindingShortestPathDijkstra(int vertex1, int vertex2)
{
	double INF = (double)INT_MAX;
	unordered_map<int, pair<bool, double>> vectorShortestPaths;
	pair<bool, double> Startpair = { false, INF }, startsPairs = { false, 0 };
	for (auto& [id, sets]: vertexes)
	{
		if (id != vertex1)
		{
			vectorShortestPaths.emplace(id, Startpair);
		}
	}
	vectorShortestPaths.emplace(vertex1, startsPairs);
	int permanent_label = vertex1;
	double min; int Idmin;
	for (int i = 0; i < vertexes.size() - 1; ++i)
	{
		for (auto& id : vertexes[permanent_label])
		{
			int edgeId = FindIdEdges(permanent_label, id);
			if (edgeId != -1)
			{
				if (edgeWeights[edgeId] + vectorShortestPaths[permanent_label].second < vectorShortestPaths[id].second)
				{
					vectorShortestPaths[id].second = edgeWeights[edgeId] + vectorShortestPaths[permanent_label].second;
				}
			}
		}
		vectorShortestPaths[permanent_label].first = true;
		min = INF;
		for (auto& [id, pair] : vectorShortestPaths)
		{
			if ((pair.second < min) && (pair.first != true))
			{
				min = pair.second;
				Idmin = id;
			}
		}		
		permanent_label = Idmin;		
	}
	int distance = vectorShortestPaths[vertex2].second;
	vector<int> vertx; int bufvert = vertex2, bufIdedge;
	if ((distance - INF >= 0) && (distance - INF <= 0.001))
	{
		vertx.push_back(-1);
		return vertx;
	}
	vertx.push_back(bufvert);
	while (distance > 0.001)
	{
		for (auto& id : vertexes[bufvert])
		{
			bufIdedge = FindIdEdges(id, bufvert);
			if ((distance - edgeWeights[bufIdedge] - vectorShortestPaths[id].second >= 0) && ((distance - edgeWeights[bufIdedge] - vectorShortestPaths[id].second <= 0.001)))
			{
				bufvert = id;
				vertx.push_back(bufvert);
				distance -= edgeWeights[bufIdedge];
				break;
			}
		}
	}
	std::reverse(vertx.begin(), vertx.end());
	return vertx;
}

int Graph::FindIdEdges(int id1, int id2)
{
	for (auto& [id, pair] : edges)
	{
		if ((pair.first == id1) && (pair.second == id2))
		{
			return id;
		}
	}
	return -1;
}
