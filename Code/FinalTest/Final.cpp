#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph
{
private:
	int V, E;
	vector<bool> visited;
	vector<vector<int>> adjList;
	vector<vector<pii>> adjListWeight;

public:
	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
		visited.resize(V, false);
		adjList.resize(V);
		adjListWeight.resize(V);
	}

	/*void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}*/

	void addEdge(int u, int v)
	{
		bool edgeExists = false;
		for (int neighbor : adjList[u]) 
		{
			if (neighbor == v) 
			{
				edgeExists = true;
				break;
			}
		}

		if (!edgeExists) 
		{
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
	}

	void addEdge(int u, int v, int w)
	{
		adjListWeight[u].push_back(make_pair(v, w));
		adjListWeight[v].push_back(make_pair(u, w));
	}

	void setVisit(int vertex, bool value)
	{
		visited[vertex] = value;
	}

	void setAllNotVisit()
	{
		for (int i = 0; i < V; i++)
		{
			setVisit(i, false);
		}
	}

	int getVertices()
	{
		return V;
	}

	int getEdges()
	{
		return E;
	}

	void setVertices(int V)
	{
		this->V = V;
	}

	void setEdges(int E)
	{
		this->E = E;
	}

	void setWeight(int u, int v, int newWeight) {
		for (auto& adjVertex : adjListWeight[u]) {
			if (adjVertex.first == v) {
				adjVertex.second = newWeight;
				break;
			}
		}

		for (auto& adjVertex : adjListWeight[v]) {
			if (adjVertex.first == u) {
				adjVertex.second = newWeight;
				break;
			}
		}
	}


	// Find the path from startVertex to endVertex use DFS
	vector<int> DFS(int startVertex, int endVertex)
	{
		vector<int> parrent(V, -1);
		stack<int> stack;

		stack.push(startVertex);
		visited[startVertex] = true;

		while (!stack.empty())
		{
			int currentVertex = stack.top();
			stack.pop();

			if (currentVertex == endVertex)
			{
				break;
			}

			for (const auto& adjVertex : adjList[currentVertex])
			{
				if (!visited[adjVertex])
				{
					stack.push(adjVertex);
					parrent[adjVertex] = currentVertex;
					visited[adjVertex] = true;
				}
			}
		}
		vector<int> result;
		int vertex = endVertex;
		while (vertex != -1)
		{
			result.push_back(vertex);
			vertex = parrent[vertex];
		}
		reverse(result.begin(), result.end());

		return result;
	}

	// Find the path from startVertex to endVertex use BFS
	vector<int> BFS(int startVertex, int endVertex)
	{
		vector<int> parrent(V, -1);
		queue<int> queue;

		queue.push(startVertex);
		visited[startVertex] = true;

		while (!queue.empty())
		{
			int currentVertex = queue.front();
			queue.pop();

			if (currentVertex == endVertex)
			{
				break;
			}

			for (const auto& adjVertex : adjList[currentVertex])
			{
				if (!visited[adjVertex])
				{
					queue.push(adjVertex);
					parrent[adjVertex] = currentVertex;
					visited[adjVertex] = true;
				}
			}
		}
		vector<int> result;
		int vertex = endVertex;
		while (vertex != -1)
		{
			result.push_back(vertex);
			vertex = parrent[vertex];
		}
		reverse(result.begin(), result.end());

		return result;
	}

	// Find the shortest path from startVertex to endVertex use Dijkstra
	vector<pii> Dijkstra(int startVertex, int endVertex)
	{
		vector<int> parrent(V, -1);
		vector<int> distance(V, INT_MAX);
		priority_queue<pii, vector<pii>, greater<pii>> pq;

		pq.push(make_pair(0, startVertex));
		distance[startVertex] = 0;

		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();

			visited[u] = true;

			for (const auto& adjVertex : adjListWeight[u])
			{
				int v = adjVertex.first;
				int w = adjVertex.second;

				if (!visited[v] && w + distance[u] < distance[v])
				{
					distance[v] = w + distance[u];
					parrent[v] = u;
					pq.push(make_pair(distance[v], v));
				}
			}
		}
		vector<pii> result;
		int vertex = endVertex;
		while (parrent[vertex] != -1)
		{
			result.push_back(make_pair(parrent[vertex], vertex));
			vertex = parrent[vertex];
		}
		reverse(result.begin(), result.end());
		return result;
	}

	// Find the shortest path from startVertex to endVertex use Prim
	vector<pii> Prim()
	{
		vector<int> parrent(V, -1);
		vector<int> distance(V, INT_MAX);
		priority_queue<pii, vector<pii>, greater<pii>> pq;

		int startVertex = 0;
		pq.push(make_pair(0, startVertex));
		distance[startVertex] = 0;

		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();

			visited[u] = true;

			for (const auto& adjVertex : adjListWeight[u])
			{
				int v = adjVertex.first;
				int w = adjVertex.second;

				if (!visited[v] && w < distance[v])
				{
					distance[v] = w;
					parrent[v] = u;
					pq.push(make_pair(distance[v], v));
				}
			}
		}
		vector<pii> result;
		for (int v = 1; v < V; v++)
		{
			result.push_back(make_pair(parrent[v], v));
		}
		return result;
	}
};

void Cau1_DFS(Graph graph, int start, int end, int visit, int avoid)
{
	cout << "Use DFS:" << endl;
	vector<int> result, path1, path2;
	graph.setVisit(avoid, true);
	graph.setVisit(end, true);
	path1 = graph.DFS(start, visit);
	graph.setVisit(end, false);
	path2 = graph.DFS(visit, end);
	path2.erase(path2.begin());
	
	result.insert(result.end(), path1.begin(), path1.end());
	result.insert(result.end(), path2.begin(), path2.end());

	for (const auto& vertex : result)
	{
		cout << vertex << " ";
	}
	cout << endl;
}

void Cau1_BFS(Graph graph, int start, int end, int visit, int avoid)
{
	cout << "Use BFS:" << endl;
	vector<int> result, path1, path2;
	graph.setVisit(avoid, true);
	graph.setVisit(end, true);
	path1 = graph.BFS(start, visit);
	graph.setVisit(end, false);
	path2 = graph.BFS(visit, end);
	path2.erase(path2.begin());

	result.insert(result.end(), path1.begin(), path1.end());
	result.insert(result.end(), path2.begin(), path2.end());

	for (const auto& vertex : result)
	{
		cout << vertex << " ";
	}
	cout << endl;
}

void Cau2a(Graph graph, int start, int end, int visit1, int visit2)
{
	
	int V = graph.getVertices();
	int E = graph.getEdges();
	Graph g(V, E);
	vector<pii> mst = graph.Prim();
	for (const auto& vertex : mst)
	{
		cout << vertex.first << " " << vertex.second << endl;
		g.addEdge(vertex.first, vertex.second);
	}
	graph.setAllNotVisit();
	vector<pii> path = graph.Dijkstra(start, end);
	for (const auto& vertex : path)
	{
		cout << vertex.first << " " << vertex.second << endl;
		g.addEdge(vertex.first, vertex.second);
	}


	/*
	vector<int> path1, path2, path3, result;
	path1 = g.BFS(start, visit1);
	for (const auto& vertex : path1)
	{
		//cout << vertex.first << " " << vertex.second << endl;
		cout << vertex << " ";
	}
	g.setVisit(visit1, false);
	path2 = g.BFS(visit1, visit2);
	for (const auto& vertex : path2)
	{
		//cout << vertex.first << " " << vertex.second << endl;
		cout << vertex << " ";
	}
	g.setVisit(visit2, false);
	path3 = g.BFS(visit2, end);
	
	result.insert(result.end(), path1.begin(), path1.end());
	result.insert(result.end(), path2.begin(), path2.end());
	result.insert(result.end(), path3.begin(), path3.end());

	for (const auto& vertex : path1)
	{
		cout << vertex.first << " ";
	}
	cout << endl;*/
}


void Bai3(int arr[], int n, int x)
{
	bool check = false;
	int a, b, c;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] == x)
				{
					a = i;
					b = j;
					c = k;
					check = true;
				}
			}
		}
	}
	if (check)
	{
		cout << "True (" << arr[a] << " + " << arr[b] << " + " << arr[c] << ") = " << x << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}

int main()
{
	freopen("Graph.txt", "r", stdin);

	cout << "Bai 1" << endl;
	int V, E;
	cin >> V >> E;
	Graph graph1(V, E);
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		graph1.addEdge(u, v);
	}

	Cau1_BFS(graph1, 0, 9, 8, 5);
	Cau1_DFS(graph1, 0, 9, 8, 5);
	cout << endl;

	cout << "Bai 2" << endl;
	cin >> V >> E;
	Graph graph2(V, E);
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph2.addEdge(u, v, w);
	}
	Cau2a(graph2, 0, 9, 7, 8);
	cout << endl;

	cout << "Bai 3" << endl;
	int arr[] = { 9, 3, 2, 5, 4, 7, 8, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Bai3(arr, n, 10);
}