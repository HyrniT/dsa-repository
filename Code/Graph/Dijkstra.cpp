#include <iostream>
#include<vector>

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

    
};