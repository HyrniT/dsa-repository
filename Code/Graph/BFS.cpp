#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
private:
    int V;
    vector< vector<int> > adjList;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int v, int w)
    {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    vector<int> BFS(int startVertex, int endVertex)
    {
        vector<bool> visited(V, false);
        vector<int> previous(V, -1);
        queue<int> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty())
        {
            int currentVertex = queue.front();
            queue.pop();

            if (currentVertex == endVertex)
                break;

            for (int adjVertex : adjList[currentVertex])
            {
                if (!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    previous[adjVertex] = currentVertex;
                    queue.push(adjVertex);
                }
            }
        }

        vector<int> shortestPath;
        int vertex = endVertex;
        while (vertex != -1)
        {
            shortestPath.push_back(vertex);
            vertex = previous[vertex];
        }
        reverse(shortestPath.begin(), shortestPath.end());

        return shortestPath;
    }
};

int main()
{
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    cout << "Shortest path from vertex 0 to 5 (use BFS): ";
    vector<int> shortestPath = graph.BFS(0, 5);

    for (int vertex : shortestPath)
        cout << vertex << " ";

    return 0;
}
