#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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

    void DFS(int startVertex)
    {
        vector<bool> visited(V, false);
        stack<int> stack;
        
        stack.push(startVertex);
        visited[startVertex] = true;

        while(!stack.empty())
        {
            int currentVertex = stack.top();
            stack.pop();

            cout << currentVertex << " ";

            for(int neighbor : adjList[currentVertex])
            {
                if(!visited[neighbor])
                {
                    stack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(V, false);
        queue<int> queue;

        queue.push(startVertex);
        visited[startVertex] = true;

        while(!queue.empty())
        {
            int currentVertex = queue.front();
            queue.pop();

            cout << currentVertex << " ";

            for(int neighbor : adjList[currentVertex])
            {
                if(!visited[neighbor])
                {
                    queue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main()
{
    /* Exercise 1 */
    int V = 5, E = 6;
    // cout << "Number of vertices: ";
    // cin >> V;
    // cout << "Number of edges: ";
    // cin >> E;
    Graph graph(V, E);
    // int v, w;
    // for (int i = 0; i < E; i++)
    // {
    //     cin >> v >> w;
    //     graph.addEdge(v, w);
    // }
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.printAdjMatrix();
    cout << endl;

    /* Exercise 2 */
    graph.DFS(0);
    cout << endl;

    /* Exercise 3 */
    graph.BFS(0);
    cout << endl;

}