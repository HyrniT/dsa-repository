#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph
{
private:
    int V;
    vector< vector< pair<int, int> > > adjList;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int v, int w, int weight)
    {
        adjList[v].push_back(make_pair(w, weight));
        // adjList[w].push_back(make_pair(v, weight));
    }

    vector<int> shortestPathDijkstra(int startVertex, int endVertex)
    {
        vector<int> distance(V, INT_MAX);
        vector<int> previous(V, -1);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        distance[startVertex] = 0;
        pq.push(make_pair(0, startVertex));

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (const auto &neighbor : adjList[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;
                int newDistance = distance[u] + weight;

                if (newDistance < distance[v])
                {
                    distance[v] = newDistance;
                    previous[v] = u;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        if (distance[endVertex] == INT_MAX)
        {
            cout << "Not found path from " << startVertex << " to " << endVertex << endl;
            return vector<int>();
        }

        vector<int> path;
        int current = endVertex;
        while (current != -1)
        {
            path.push_back(current);
            current = previous[current];
        }

        reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    int numVertices = 6;
    Graph graph(numVertices);

    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 5);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 3);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 5, 7);
    graph.addEdge(0, 5, 10);

    vector<int> shortestPath = graph.shortestPathDijkstra(0, 4);

    cout << "Shortest path from vertex 0 to 4 (use Dijkstra): ";
    for (int vertex : shortestPath)
        cout << vertex << " ";

    return 0;
}
