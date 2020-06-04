/**
 * @file coin_change.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/coin-change/
 * @version 0.1
 * @date 2020-05-26
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using std::vector;

void backtrack(vector<int> &coins, int amount, int &nums, int current,
               vector<vector<int>> &result, vector<int> &running) {
  if (amount == 0) {
    if (current < nums) {
      result.push_back(running);
      nums = current;
    }
  } else {
    if (amount > 0) {
      for (size_t i = 0; i < coins.size(); ++i) {
        int current_element = coins.at(i);
        running.push_back(current_element);
        backtrack(coins, amount - current_element, nums, current + 1, result,
                  running);
        running.pop_back();
      }
    }
  }
}

int coinChange(vector<int> &coins, int amount, vector<vector<int>> &result) {
  vector<int> running;
  int nums = std::numeric_limits<int>::max();
  std::sort(coins.begin(), coins.end());
  backtrack(coins, amount, nums, 0, result, running);
  if (nums == std::numeric_limits<int>::max()) {
    return -1;
  }
  return nums;
}

int main() {
  vector<int> coins = {1, 2, 5};
  vector<vector<int>> result;
  std::cout << coinChange(coins, 100, result) << std::endl;
  for (size_t i = 0; i < result.size(); i++) {
    for (size_t j = 0; j < result.at(i).size(); j++) {
      std::cout << result.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}
