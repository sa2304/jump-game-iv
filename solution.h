#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include <queue>
#include <set>
#include <vector>

class graph {
public:
  using Vertex = int;
  using Distance = int;

  void AddEdge(Vertex v1, Vertex v2) {
    edges_.push_back({v1, v2});
  }

  std::pair<int, std::map<Vertex, Vertex>> shortestPath(Vertex from, Vertex to) const {
    std::queue<std::pair<Vertex, Distance>> vertexes_queue;
    std::map<Vertex, Vertex> previous;
    std::set<int> visited;
    int shortest_distance = -1;
    bool found = false;
    visited.insert(from);
    vertexes_queue.push({from, 0});

    while (!vertexes_queue.empty() && !found) {
      auto [v1, dist] = vertexes_queue.front();
      vertexes_queue.pop();
      if (v1 == to) {
        shortest_distance = dist;
        found = true;
      }
      for (int v2 : incidentVertexes(v1)) {
        if (!visited.count(v2)) {
          vertexes_queue.push({v2, dist + 1});
          previous[v2] = v1;
          visited.insert(v2);
        }
      }
    }

    return { shortest_distance, previous };
  }

private:
  std::vector<int> incidentVertexes(int vertex) const {
    std::vector<int> result;
    for (auto [v1, v2] : edges_) {
      if (v1 == vertex) {
        result.push_back(v2);
      } else if (v2 == vertex) {
        result.push_back(v1);
      }
    }

    return result;
  }

  std::vector<std::pair<int,int>> edges_;
};

class Solution {
public:
  int minJumps(std::vector<int>& arr) {
    graph g;
    for (size_t i = 0; i < arr.size(); ++i) {
      for (size_t j = 0; j < arr.size(); ++j) {
        if (i == j) {
          continue;
        }

        if (i + 1 == j || j + 1 == i || arr[i] == arr[j]) {
          g.AddEdge(i, j);
        }
      }
    }

    auto [distance, previous] = g.shortestPath(0, arr.size()-1);
    return distance;
  }
};

#endif // SOLUTION_H
