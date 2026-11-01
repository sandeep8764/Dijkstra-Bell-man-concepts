#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

using Graph = unordered_map<string, vector<pair<string, int>>>;

void dijkstra(const Graph& graph, const string& source) {
    unordered_map<string, int> dist;
    for (const auto& [node, neighbors] : graph) {
        dist[node] = INT_MAX;
    }
    dist[source] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currentDist, node] = pq.top();
        pq.pop();

        if (currentDist != dist[node]) continue;

        for (const auto& [neighbor, weight] : graph.at(node)) {
            int newDistance = currentDist + weight;
            if (newDistance < dist[neighbor]) {
                dist[neighbor] = newDistance;
                pq.push({newDistance, neighbor});
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

    dijkstra(graph, "A");
    return 0;
}
