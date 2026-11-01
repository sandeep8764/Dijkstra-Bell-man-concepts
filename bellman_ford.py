"""Bellman-Ford algorithm implementation.

Bellman-Ford finds the shortest path from a source to all vertices in a graph,
including graphs with negative edge weights, as long as no negative cycle is
reachable from the source.

Algorithm:
1. Initialize distances with source = 0 and others = infinity.
2. Relax all edges V - 1 times.
3. Check for a negative cycle reachable from the source.

Time complexity: O(V * E)
Space complexity: O(V)
"""


def bellman_ford(graph, source):
    """Return shortest distances from source using Bellman-Ford."""
    distances = {node: float('inf') for node in graph}
    distances[source] = 0

    vertices = list(graph.keys())

    for _ in range(len(vertices) - 1):
        updated = False
        for u in vertices:
            if distances[u] == float('inf'):
                continue
            for v, weight in graph[u].items():
                if distances[u] + weight < distances[v]:
                    distances[v] = distances[u] + weight
                    updated = True
        if not updated:
            break

    for u in vertices:
        if distances[u] == float('inf'):
            continue
        for v, weight in graph[u].items():
            if distances[u] + weight < distances[v]:
                raise ValueError("Graph contains a negative cycle reachable from source")

    return distances


if __name__ == "__main__":
    graph = {
        'A': {'B': 4, 'C': 2},
        'B': {'C': 3, 'D': 2},
        'C': {'B': 1, 'D': 5, 'E': 8},
        'D': {'E': 2},
        'E': {'D': 1}
    }

    result = bellman_ford(graph, 'A')
    print("Shortest distances from A:", result)
