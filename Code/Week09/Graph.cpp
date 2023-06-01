#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int V;
    int E;
    vector< vector<int> > adjList;
    vector< vector<int> > adjMatrix;

public:
    Graph(int vertices, int edges)
    {
        V = vertices;
        E = edges;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V));
    }

    void addEdge(int v, int w)
    {
        adjList[v].push_back(w);
        // adjList[w].push_back(v);

        adjMatrix[v][w]++;
    }

    void printAdjMatrix()
    {
        for (const auto &row : adjMatrix)
        {
            for (const auto &i : row)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int V, E;
    // cout << "Number of vertices: ";
    cin >> V;
    // cout << "Number of edges: ";
    cin >> E;
    Graph graph(V, E);
    int v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> v >> w;
        graph.addEdge(v, w);
    }
    // graph.addEdge(0, 1);
    // graph.addEdge(0, 2);
    // graph.addEdge(1, 2);
    // graph.addEdge(1, 4);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);
    graph.printAdjMatrix();
}