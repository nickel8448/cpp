/**
 * @file two_city_scheduling.cpp
 * @author Rahul Wadhwani
 * @brief
 * @version 0.1
 * @date 2020-06-03
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int twoCitySchedCost(vector<vector<int>> &costs) {
  int cost = 0;
  std::sort(costs.begin(), costs.end(),
            [](const vector<int> &o1, const vector<int> &o2) {
              return o1[0] - o1[1] < (o2[0] - o2[1]);
            });
  int n = costs.size() / 2;
  for (size_t i = 0; i < n; ++i) {
    cost += costs.at(i).at(0) + costs.at(i + n).at(1);
  }
  return cost;
}

int main() {
  vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
  std::cout << twoCitySchedCost(costs) << std::endl;
}
