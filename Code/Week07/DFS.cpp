#include <iostream>
#include <stack>
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

    vector<int> DFS(int startVertex, int endVertex)
    {
        vector<bool> visited(V, false);
        vector<int> previous(V, -1);
        stack<int> stack;

        visited[startVertex] = true;
        stack.push(startVertex);

        while(!stack.empty())
        {
            int currentVertex = stack.top();
            stack.pop();

            if(currentVertex == endVertex)
                break;

            for(int adjVertex : adjList[currentVertex])
            {
                if(!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    previous[adjVertex] = currentVertex;
                    stack.push(adjVertex);
                }
            }
        }

        vector<int> shortestPath;
        int vertex = endVertex;
        while (vertex != -1) // while (vertex != startVertex)
        {
            shortestPath.push_back(vertex);
            vertex = previous[vertex];
        }
        // shortestPath.push_back(startVertex);
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

    cout << "Shortest path from vertex 0 to 5 (use DFS): ";
    vector<int> shortestPath = graph.DFS(0, 5);

    for (int vertex : shortestPath)
        cout << vertex << " ";

    return 0;
}
