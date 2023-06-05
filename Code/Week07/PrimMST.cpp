#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph
{
private:
    int V;
    vector<vector<pii>> adjList;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(0);
    }

    void addEdge(int u, int v, int w)
    {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    vector<pii> PrimMST()
    {
        vector<bool> visited(V, false);
        vector<int> distance(V, INT_MAX);
        
    }
};

int main()
{
}
