/**
 * @file reconstrust_itenary.cpp
 * @author Rahul Wadhwani
 * @brief
 * @version 0.1
 * @date 2020-06-04
 *
 * @copyright Copyright (c) 2020
 * Apporach: hierholzer's algorithm to construct a eucledian path of the itenary
 * Status: Completed
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

typedef std::priority_queue<string, vector<string>, std::greater<string>> pq;
typedef std::unordered_map<string, pq> mp;

void dfs(string origin, vector<string> &result, mp &adj_list) {
  // 1. Check if this is an airport of origin
  if (adj_list.find(origin) != adj_list.end()) {
    pq &destination_list = adj_list.at(origin);
    while (!destination_list.empty()) {
      string destination = destination_list.top();
      destination_list.pop();
      dfs(destination, result, adj_list);
    }
  }
  result.push_back(origin);
}

vector<string> findItinerary(vector<vector<string>> &tickets) {
  // graph adjacency map
  mp adj_list;
  // Create the graph
  for (size_t i = 0; i < tickets.size(); ++i) {
    string airport = tickets.at(i).at(0), dest = tickets.at(i).at(1);
    if (adj_list.find(airport) != adj_list.end()) {
      adj_list.at(airport).push(dest);
    } else {
      pq new_pq;
      new_pq.push(dest);
      adj_list.insert(std::make_pair(airport, new_pq));
    }
  }
  vector<string> result;
  dfs("JFK", result, adj_list);
  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  vector<vector<string>> tickets = {
      {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  vector<vector<string>> tickets2 = {{"JFK", "SFO"},
                                     {"JFK", "ATL"},
                                     {"SFO", "ATL"},
                                     {"ATL", "JFK"},
                                     {"ATL", "SFO"}};
  vector<vector<string>> tickets3 = {
      {"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
  findItinerary(tickets3);
  return 0;
}
