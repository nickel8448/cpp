/**
 * @file possible_bipartition.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/possible-bipartition/
 * @version 0.1
 * @date 2020-05-28
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#define WHITE 0
#define RED 1
#define BLUE 2

using std::queue;
using std::vector;

bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
  vector<vector<int>> adj(N + 1); // adjacency list for undirected graph
  vector<int> color(N + 1,
                    WHITE); // color of each vertex in graph is initially white
  vector<bool> explored(N + 1, false); // track of all the vertex being explored

  // creating adjacency list
  for (auto &edge : dislikes) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (!explored[i]) {
      // component has not been coloured yet
      // marking it as red and pushing it to the queue
      color[i] = RED;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        // checking if u has already been explored
        if (explored[u]) {
          continue;
        }
        explored[u] = true;
        // visiting adjacent nodes of v
        for (auto v : adj[u]) {
          // Checking if there is a conflict in the colours
          if (color[v] == color[u]) {
            return false;
          }
          if (color[u] == RED)
            color[v] = BLUE;
          else
            color[v] = RED;
          q.push(v);
        }
      }
    }
  }
  return true;
}

int main() {
  vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
  std::cout << possibleBipartition(4, dislikes) << std::endl;
}
