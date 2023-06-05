#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph
{
private:
    int V, E;
    vector<vector<pii> > adjList;
    vector<vector<int> > adjMatrix;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V));
    }

    Graph(int vertices, int edges)
    {
        V = vertices;
        E = edges;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V));
    }

    void addEdge(int u, int v, int w)
    {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));

        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    vector<pii> PrimMST()
    {
        vector<bool> visited(V, false);
        vector<int> distance(V, INT_MAX);
        vector<int> previous(V, -1);
        int minWeight = 0;

        priority_queue<pii, vector<pii>, greater<pii> > pq;

        int startVertex = 0;
        distance[startVertex] = 0;
        pq.push(make_pair(0, startVertex));

        while (!pq.empty())
        {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            minWeight += w;

            for (const auto &adjVertex : adjList[u])
            {
                int v = adjVertex.first;
                int weight = adjVertex.second;

                if (!visited[v] && weight < distance[v])
                {
                    // cout << u << " " << v << endl;
                    distance[v] = weight;
                    pq.push(make_pair(distance[v], v));
                    previous[v] = u;
                }
            }
        }

        cout << "Min weight of graph: " << minWeight << endl;

        vector<pii> mst;
        for (int v = 1; v < V; v++)
        {
            mst.push_back(make_pair(previous[v], v));
        }

        return mst;
    }
};

int main()
{
    // Read from Adj Matrix
    /*
    freopen("input1.txt", "r", stdin);
    int V;
    cin >> V;

    Graph graph(V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            int weight;
            cin >> weight;
            if (weight > 0)
            {
                graph.addEdge(i, j, weight);
            }
        }
    }
    */

    // Read from Adj List
    freopen("input2.txt", "r", stdin);
    int V, E;
    cin >> V >> E;

    Graph graph(V, E);

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    vector<pii> mst = graph.PrimMST();

    for (const auto &edge : mst)
    {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
