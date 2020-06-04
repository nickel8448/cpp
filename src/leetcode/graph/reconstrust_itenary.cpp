/**
 * @file reconstrust_itenary.cpp
 * @author Rahul Wadhwani
 * @brief
 * @version 0.1
 * @date 2020-06-04
 *
 * @copyright Copyright (c) 2020
 * Status: Non-completed
 */

#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

vector<string> findItinerary(vector<vector<string>>& tickets) {
  std::unordered_map<string, std::priority_queue<string, vector<string>, std::greater<string>>> adj_list;

  // inserting values in the map
  for (size_t i = 0; i < tickets.size(); ++i) {
    string airport = tickets.at(i).at(0), dest = tickets.at(i).at(1);
    if (adj_list.find(airport) != adj_list.end()) {
      adj_list.at(airport).push(dest);
    } else {
      std::priority_queue<string, vector<string>, std::greater<string>> new_pq;
      new_pq.push(dest);
      adj_list.insert(std::make_pair(airport, new_pq));
    }
  }

  vector<string> result;
  result.push_back("JFK");
  for (size_t i = 0; i < tickets.size(); ++i) {
    string next_airport = adj_list.at(result.back()).top();
    adj_list.at(result.back()).pop();
    result.push_back(next_airport);
  }
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
  findItinerary(tickets2);
  return 0;
}
