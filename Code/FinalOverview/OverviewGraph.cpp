#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

class Graph
{
private:
    int V;
    int E;
    vector< vector<int> > adjList;
    vector< vector<int> > adjMatrix;

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
}
