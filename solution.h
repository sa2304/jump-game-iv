#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <unordered_map>

class Solution {
public:

  int minJumps(std::vector<int>& arr) {
    using Index = int;
    using Value = int;
    std::unordered_map<Value, std::set<Index>> jumps;
    int n = arr.size();
    for (size_t i = 0; i < n; ++i) {
      jumps[arr[i]].insert(i);
    }

    std::queue<Index> bfs_queue;
    std::set<Index> visited;
    int level = 0;

    bfs_queue.push(0);
    visited.insert(0);

    while (!bfs_queue.empty()) {
      int level_nodes_count = bfs_queue.size();
      while (level_nodes_count--) {
        Index index = bfs_queue.front();
        bfs_queue.pop();
        if (index == n - 1) {
          return level;
        }

        Index prev_index = index - 1;
        if (0 <= prev_index && !visited.count(prev_index)) {
          bfs_queue.push(prev_index);
          visited.insert(prev_index);
        }

        Index next_index = index + 1;
        if (next_index < n && !visited.count(next_index)) {
          bfs_queue.push(next_index);
          visited.insert(next_index);
        }

        for (Index jump_index : jumps.at(arr[index])) {
          if (!visited.count(jump_index)) {
            bfs_queue.push(jump_index);
            visited.insert(jump_index);
          }
        }
        jumps[arr[index]].clear();
      }
      ++level;
    }

    return level;
  }
};

#endif // SOLUTION_H
