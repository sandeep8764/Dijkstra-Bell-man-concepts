# Dijkstra and Bellman-Ford Algorithms

This folder contains separate files for each shortest-path concept in both Python and C++.

## Concepts included

1. Dijkstra's Algorithm
2. Bellman-Ford Algorithm

## Files

- `dijkstra.py` - Dijkstra's shortest path algorithm in Python
- `bellman_ford.py` - Bellman-Ford shortest path algorithm in Python
- `dijkstra.cpp` - Dijkstra's shortest path algorithm in C++
- `bellman_ford.cpp` - Bellman-Ford shortest path algorithm in C++

## Algorithm summary

### Dijkstra's Algorithm
Dijkstra's algorithm finds the shortest path from a source node to all other nodes in a graph with non-negative edge weights.

### Bellman-Ford Algorithm
Bellman-Ford finds the shortest path even when graph edges have negative weights, as long as there is no negative cycle reachable from the source.

## How to run

```bash
python3 dijkstra.py
python3 bellman_ford.py
```
