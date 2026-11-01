#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

using Graph = unordered_map<string, vector<pair<string, int>>>;

void bellmanFord(const Graph& graph, const string& source) {
    unordered_map<string, int> dist;
    vector<pair<string, string>> edges;

    for (const auto& [node, neighbors] : graph) {
        dist[node] = INT_MAX;
        for (const auto& [neighbor, weight] : neighbors) {
            edges.push_back({node, neighbor});
        }
    }
    dist[source] = 0;

    int vertexCount = graph.size();
    for (int i = 0; i < vertexCount - 1; ++i) {
        bool updated = false;
        for (const auto& [u, v] : edges) {
            if (dist[u] == INT_MAX) continue;
            for (const auto& [neighbor, weight] : graph.at(u)) {
                if (neighbor == v && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }

    for (const auto& [u, v] : edges) {
        for (const auto& [neighbor, weight] : graph.at(u)) {
            if (neighbor == v && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative cycle reachable from source.\n";
                return;
            }
        }
    }

    cout << "Shortest distances from " << source << ":\n";
    for (const auto& [node, distance] : dist) {
        cout << node << " -> " << distance << "\n";
    }
}

int main() {
    Graph graph = {
        {"A", {{"B", 4}, {"C", 2}}},
        {"B", {{"C", 3}, {"D", 2}}},
        {"C", {{"B", 1}, {"D", 5}, {"E", 8}}},
        {"D", {{"E", 2}}},
        {"E", {{"D", 1}}}
    };

    bellmanFord(graph, "A");
    return 0;
}
