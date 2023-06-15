#include <iostream>
#include <vector>

#define INF 99999

struct Edge {
    int source, destination, weight;
};

void BellmanFord(std::vector<Edge>& edges, int numVertices, int source) {
    std::vector<int> distance(numVertices, INF);
    distance[source] = 0;

    // Relax all edges |numVertices| - 1 times
    for (int i = 0; i < numVertices - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            std::cout << "Đồ thị có chu trình âm." << std::endl;
            return;
        }
    }

    // Print the shortest distances
    std::cout << "Khoảng cách ngắn nhất từ đỉnh " << source << ":" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Đỉnh " << i << ": " << distance[i] << std::endl;
    }
}

int main() {
    int numVertices = 5; // Số đỉnh của đồ thị
    int numEdges = 8;    // Số cạnh của đồ thị
    int source = 0;      // Đỉnh nguồn

    std::vector<Edge> edges;
    Edge edge;

    edge.source = 0;
    edge.destination = 1;
    edge.weight = 4;
    edges.push_back(edge);

    edge.source = 0;
    edge.destination = 2;
    edge.weight = 2;
    edges.push_back(edge);

    edge.source = 1;
    edge.destination = 2;
    edge.weight = -1;
    edges.push_back(edge);

    edge.source = 1;
    edge.destination = 3;
    edge.weight = 1;
    edges.push_back(edge);

    edge.source = 2;
    edge.destination = 3;
    edge.weight = 3;
    edges.push_back(edge);

    edge.source = 2;
    edge.destination = 4;
    edge.weight = 2;
    edges.push_back(edge);

    edge.source = 3;
    edge.destination = 4;
    edge.weight = 4;
    edges.push_back(edge);

    edge.source = 4;
    edge.destination = 3;
    edge.weight = -5;
    edges.push_back(edge);

    BellmanFord(edges, numVertices, source);

    return 0;
}


