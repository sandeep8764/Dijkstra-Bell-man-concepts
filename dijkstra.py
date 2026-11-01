"""Dijkstra's algorithm implementation.

Dijkstra's algorithm finds the shortest path from a source node to all other
nodes in a graph whose edge weights are non-negative.

Algorithm:
1. Set the distance of source to 0 and all other vertices to infinity.
2. Pick the unvisited vertex with the smallest tentative distance.
3. Visit all neighbors and relax edges.
4. Repeat until all vertices are processed.

Time complexity: O((V + E) log V) using a min-heap.
Space complexity: O(V)
"""

import heapq


def dijkstra(graph, source):
    """Return the shortest distances from the source to every node."""
    distances = {node: float('inf') for node in graph}
    distances[source] = 0

    min_heap = [(0, source)]

    while min_heap:
        current_distance, node = heapq.heappop(min_heap)

        if current_distance > distances[node]:
            continue

        for neighbor, weight in graph[node].items():
            new_distance = current_distance + weight
            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                heapq.heappush(min_heap, (new_distance, neighbor))

    return distances


if __name__ == "__main__":
    graph = {
        'A': {'B': 4, 'C': 2},
        'B': {'C': 3, 'D': 2},
        'C': {'B': 1, 'D': 5, 'E': 8},
        'D': {'E': 2},
        'E': {'D': 1}
    }

    result = dijkstra(graph, 'A')
    print("Shortest distances from A:", result)
