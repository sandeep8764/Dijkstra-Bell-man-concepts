# Dijkstra and Bellman-Ford Algorithms in C++

This repository contains separate C++ implementations for two important shortest-path algorithms.

## Concepts included

1. Dijkstra's Algorithm
2. Bellman-Ford Algorithm

## Files

- `dijkstra.cpp` - Dijkstra's shortest path algorithm in C++
- `bellman_ford.cpp` - Bellman-Ford shortest path algorithm in C++

## Algorithm summary

### Dijkstra's Algorithm
Dijkstra's algorithm finds the shortest path from a source node to all other nodes in a graph with non-negative edge weights.

### Bellman-Ford Algorithm
Bellman-Ford finds the shortest path even when graph edges have negative weights, as long as there is no negative cycle reachable from the source.

## How to run

```bash
g++ -std=c++17 dijkstra.cpp -o dijkstra
./dijkstra

g++ -std=c++17 bellman_ford.cpp -o bellman_ford
./bellman_ford
```

## Notes

- Dijkstra is faster for graphs with non-negative weights.
- Bellman-Ford is more general and supports negative edge weights, with cycle detection.

