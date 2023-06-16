#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int num_vertices;
    vector<vector<int>> adj_list;

public:
    Graph(int vertices) : num_vertices(vertices) {
        adj_list.resize(num_vertices);
    }

    void addEdge(int u, int v) {
        adj_list[u].push_back(v);
    }

    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& sorted_stack) {
        visited[v] = true;

        for (int neighbor : adj_list[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, sorted_stack);
            }
        }

        sorted_stack.push(v);
    }

    void topologicalSort() {
        vector<bool> visited(num_vertices, false);
        stack<int> sorted_stack;

        for (int v = 0; v < num_vertices; ++v) {
            if (!visited[v]) {
                topologicalSortUtil(v, visited, sorted_stack);
            }
        }

        cout << "Topological Sort: ";
        while (!sorted_stack.empty()) {
            cout << sorted_stack.top() << " ";
            sorted_stack.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
