#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <climits>

using namespace std;

//          dist  node
typedef pair<int, int> pii;
class Graph
{
private:
    int V;
    int E;

    // Use for BFS and DFS
    vector< vector<int> > adjList;
    vector< vector<int> > adjMatrix;

    // Use for Dijkstra and Prim
    vector< vector<pii> > adjListWeight;

public:
    Graph() {}

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

    void addEdgeWeight(int u, int v, int w)
    {
        adjListWeight[u].push_back(make_pair(v, w));
        // adjListWeight[v].push_back(make_pair(u, w));

        adjMatrix[u][v]++;
    }

    void readAdjList(string fileName)
    {
        ifstream file(fileName);

        if (file.is_open())
        {
            file >> V >> E;
            adjList.resize(V);
            adjMatrix.resize(V, vector<int>(V));

            int v, w;
            for (int i = 0; i < E; i++)
            {
                file >> v >> w;
                addEdge(v, w);
            }

            file.close();
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }
    }

    void readAdjListWithWeight(string fileName)
    {
        ifstream file(fileName);
        if (file.is_open())
        {
            file >> V >> E;
            adjListWeight.resize(V);
            adjMatrix.resize(V, vector<int>(V));

            int u, v, w;
            for (int i = 0; i < E; i++)
            {
                file >> u >> v >> w;
                addEdgeWeight(u, v, w);
            }
            
            file.close();
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }
    }

    void readAdjMatrix(string fileName)
    {
        ifstream file(fileName);

        if (file.is_open())
        {
            // Unknown the vertices of graph
            /*
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                vector<int> row;
                int value;
                while (ss >> value)
                {
                    row.push_back(value);
                }
                adjMatrix.push_back(row);
            }

            file.close();

            V = adjMatrix.size();
            adjList.resize(V);
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (adjMatrix[i][j] != 0)
                    {
                        adjList[i].push_back(j);
                    }
                }
            }
            */

            // Known the vertices of graph
            file >> V;
            adjMatrix.resize(V, vector<int>(V));
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    file >> adjMatrix[i][j];
                }
            }

            file.close();

            adjList.resize(V);
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (adjMatrix[i][j] != 0)
                    {
                        adjList[i].push_back(j);
                    }
                }
            }
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            for (const auto &adjVertex : adjList[i])
            {
                cout << i << " " << adjVertex << endl;
            }
        }
        cout << endl;
    }

    void printAdjMatrix()
    {
        for (const auto &row : adjMatrix)
        {
            for (const auto &value : row)
            {
                cout << value << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void writeAdjList(string fileName)
    {
        ofstream file(fileName);

        if (file.is_open())
        {
            file << V << endl
                 << E << endl;
            for (int i = 0; i < V; i++)
            {
                for (const auto &adjVertex : adjList[i])
                {
                    file << i << " " << adjVertex << endl;
                }
            }
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }

        file.close();
    }

    void writeAdjMatrix(string fileName)
    {
        ofstream file(fileName);

        if (file.is_open())
        {
            for (const auto &row : adjMatrix)
            {
                for (const auto &value : row)
                {
                    file << value << " ";
                }
                file << endl;
            }
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }

        file.close();
    }

    void DFS(int startVertex, int endVertex)
    {
        vector<bool> visited(V, false);
        vector<int> temp;
        stack<int> stack;
        bool found = false;

        stack.push(startVertex);
        visited[startVertex] = true;

        while (!stack.empty())
        {
            int currentVertex = stack.top();
            stack.pop();

            temp.push_back(currentVertex);

            if (currentVertex == endVertex)
            {
                found = true;
                break;
            }

            for (int adjVertex : adjList[currentVertex])
            {
                if (!visited[adjVertex])
                {
                    stack.push(adjVertex);
                    visited[adjVertex] = true;
                }
            }
        }

        if (found)
        {
            for (int v : temp)
                cout << v << " ";
        }
        else
            cout << "non-exist path";
        cout << endl;
    }

    void BFS(int startVertex, int endVertex)
    {
        vector<bool> visisted(V, false);
        queue<int> queue;
        vector<int> temp;
        bool found = false;

        queue.push(startVertex);
        visisted[startVertex] = true;

        while (!queue.empty())
        {
            int currentVertex = queue.front();
            queue.pop();

            temp.push_back(currentVertex);

            if (currentVertex == endVertex)
            {
                found = true;
                break;
            }

            for (int adjVertex : adjList[currentVertex])
            {
                if (!visisted[adjVertex])
                {
                    queue.push(adjVertex);
                    visisted[adjVertex] = true;
                }
            }
        }

        if (found)
        {
            for (int v : temp)
                cout << v << " ";
        }
        else
            cout << "non-exist path";
        cout << endl;
    }

    vector<int> shortestDFS(int startVertex, int endVertex)
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
        while (vertex != -1)
        {
            shortestPath.push_back(vertex);
            vertex = previous[vertex];
        }
        reverse(shortestPath.begin(), shortestPath.end());

        return shortestPath;
    }

    vector<int> shortestBFS(int startVertex, int endVertex)
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

    vector<int> Dijkstra(int startVertex)
    {
        vector<bool> visited(V, false);
        vector<int> distance(V, INT_MAX);

        priority_queue<pii, vector<pii>, greater<pii> > pq;

        pq.push(make_pair(0, startVertex));
        distance[startVertex] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            visited[u] = true;

            for (const auto &adjVertex : adjListWeight[u])
            {
                int v = adjVertex.first;
                int weight = adjVertex.second;

                if (!visited[v] && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }
    }

    vector<int> shortestDijkstra(int startVertex, int endVertex)
    {
        vector<bool> visited(V, false);
        vector<int> distance(V, INT_MAX);
        vector<int> previous(V, -1);

        priority_queue<pii, vector<pii>, greater<pii> > pq;

        distance[startVertex] = 0;
        pq.push(make_pair(0, startVertex));

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            visited[u] = true;

            for (const auto &adjVertex : adjListWeight[u])
            {
                int v = adjVertex.first;
                int weight = adjVertex.second;

                if (!visited[v] && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
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

    vector<pii> Prim()
    {
        
    }
};

int main()
{
    Graph graph;
    // graph.readAdjList("input1.txt");
    // graph.printAdjMatrix();
    // graph.printAdjList();
    // graph.writeAdjMatrix("output1.txt");

    graph.readAdjMatrix("input2.txt");
    graph.printAdjMatrix();
    graph.printAdjList();
    graph.writeAdjList("output2.txt");

    cout << "Shortest path from vertex 0 to 4 (use DFS): ";
    vector<int> shortestPathDFS = graph.shortestDFS(0, 4);
    for (int vertex : shortestPathDFS)
        cout << vertex << " ";
    cout << endl;

    cout << "Shortest path from vertex 0 to 4 (use BFS): ";
    vector<int> shortestPathBFS = graph.shortestBFS(0, 4);
    for (int vertex : shortestPathBFS)
        cout << vertex << " ";
    cout << endl;



    return 0;
}
