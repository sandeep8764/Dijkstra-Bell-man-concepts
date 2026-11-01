# Dijkstra and Bellman-Ford Algorithms in C++

This repository contains separate C++ implementations of two important shortest-path algorithms: **Dijkstra's Algorithm** and **Bellman-Ford Algorithm**.

The purpose of this repository is to understand how both algorithms work, how they calculate shortest paths, and when to use each algorithm.

## Concepts Covered

1. Dijkstra's Algorithm
2. Bellman-Ford Algorithm
3. Shortest Path in Weighted Graphs
4. Edge Relaxation
5. Priority Queue (Min Heap)
6. Negative Edge Weights
7. Negative Cycle Detection
8. Time and Space Complexity
9. Comparison between Dijkstra and Bellman-Ford

## Files

| File | Description |
|---|---|
| `dijkstra.cpp` | Dijkstra's shortest-path algorithm in C++ |
| `bellman_ford.cpp` | Bellman-Ford shortest-path algorithm in C++ |

## 1. Dijkstra's Algorithm

Dijkstra's algorithm finds the shortest distance from a source node to all other nodes in a weighted graph with **non-negative edge weights**.

### How it works

1. Initialize the distance of every node as infinity.
2. Set the source node's distance to `0`.
3. Use a Min Heap (Priority Queue) to process the node with the smallest distance.
4. Explore its adjacent nodes.
5. Relax the edges if a shorter path is found.
6. Repeat until the priority queue becomes empty.

### Key Concepts
- Greedy Algorithm
- Min Heap / Priority Queue
- Adjacency List
- Edge Relaxation
- Shortest Path Calculation

## 2. Bellman-Ford Algorithm

Bellman-Ford finds the shortest distance from a source node to all other nodes, even when the graph contains **negative edge weights**.

It can also detect negative weight cycles reachable from the source node.

### How it works

1. Initialize the distance of every node as infinity.
2. Set the source node's distance to `0`.
3. Relax all edges repeatedly for `V-1` iterations.
4. Check all edges one more time.
5. If any distance can still be reduced, a reachable negative weight cycle exists.

### Key Concepts
- Dynamic Programming Approach
- Edge Relaxation
- Negative Edge Weights
- Negative Cycle Detection
- Repeated Edge Relaxation

## 3. Graph Diagram

Consider the following directed weighted graph:

```text
          4
     A --------> B
     |           |
   5 |           | 2
     |           |
     v           v
     C --------> D
          3
```

Assume node `A` is the source node.

Possible shortest distances from A:

| Node | Shortest Distance |
|---|---:|
| A | 0 |
| B | 4 |
| C | 5 |
| D | 6 |

The shortest path to D is:

`A → B → D`

Total cost = `4 + 2 = 6`.

Both Dijkstra and Bellman-Ford can calculate these distances because all edge weights are non-negative.

## 4. Dijkstra vs Bellman-Ford

| Feature | Dijkstra | Bellman-Ford |
|---|---|---|
| Approach | Greedy | Repeated edge relaxation |
| Negative weights | Not supported in general | Supported |
| Negative cycle detection | No | Yes |
| Data structure | Min Heap + Adjacency List | Distance Array + Edge List |
| Edge relaxation | When processing a node | Repeatedly for all edges |
| Time Complexity | `O((V+E) log V)` | `O(V × E)` |
| Best suited for | Non-negative edge weights | Graphs with negative edge weights |

### Important Differences

**1. Working Strategy**

- Dijkstra selects the node with the smallest tentative distance using a Min Heap.
- Bellman-Ford relaxes every edge repeatedly to find shorter paths.

**2. Negative Edge Weights**

- Dijkstra does not guarantee correct results with negative edge weights.
- Bellman-Ford supports negative edge weights.

**3. Negative Cycle Detection**

- Dijkstra cannot detect negative weight cycles.
- Bellman-Ford can detect a negative cycle reachable from the source by performing one additional relaxation check after `V-1` iterations.

**4. Performance**

- Dijkstra is generally faster and preferred for graphs with non-negative weights.
- Bellman-Ford is slower but more flexible.

## 5. Time and Space Complexity

Let:
- `V` = Number of vertices
- `E` = Number of edges

| Algorithm | Time Complexity | Auxiliary Space |
|---|---|---|
| Dijkstra (Min Heap + Adjacency List) | `O((V+E) log V)` | `O(V+E)` |
| Bellman-Ford | `O(V × E)` | `O(V)` |

## 6. What I Learned

Through this implementation and study, I learned:

- How shortest-path algorithms work in weighted graphs.
- How to implement Dijkstra's Algorithm using a Min Heap and Priority Queue in C++.
- How to implement Bellman-Ford using repeated edge relaxation.
- The concept of edge relaxation and distance updates.
- Why Dijkstra requires non-negative edge weights.
- How Bellman-Ford handles negative edge weights.
- How to detect negative weight cycles.
- The differences in time complexity, working strategies, and use cases of both algorithms.
- How to select the appropriate shortest-path algorithm based on graph properties.

## 7. How to Run

Compile and execute Dijkstra:

```bash
g++ -std=c++17 dijkstra.cpp -o dijkstra
./dijkstra
```

Compile and execute Bellman-Ford:

```bash
g++ -std=c++17 bellman_ford.cpp -o bellman_ford
./bellman_ford
```

## 8. Conclusion

Both Dijkstra and Bellman-Ford are important shortest-path algorithms.

- **Dijkstra:** Best choice for graphs with non-negative edge weights when efficient shortest-path computation is required.
- **Bellman-Ford:** Useful when negative edge weights are present or negative cycle detection is required.

Understanding both algorithms helps build a strong foundation in Graph Theory, Shortest Path Problems, and Data Structures & Algorithms.
