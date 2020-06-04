/**
 * @file subsets_ii.cpp
 * @author Rahul Wadhwani
 * @brief
 * @version 0.1
 * @date 2020-05-25
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using std::set;
using std::vector;

void backtrack(vector<vector<int>> &result, vector<int> &running,
               vector<int> &nums, set<vector<int>> &vector_set, int index) {
  if (vector_set.find(running) == vector_set.end()) {
    std::sort(running.begin(), running.end());
    vector_set.insert(running);
    result.push_back(running);
  }
  for (size_t i = index; i < nums.size(); ++i) {
    running.push_back(nums.at(i));
    backtrack(result, running, nums, vector_set, i + 1);
    running.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  vector<vector<int>> result;
  vector<int> running;
  std::sort(nums.begin(), nums.end());
  set<vector<int>> vector_set;
  backtrack(result, running, nums, vector_set, 0);
  return result;
}

int main() {
  vector<int> nums = {1, 2, 2};
  vector<vector<int>> results = subsetsWithDup(nums);
  for (size_t i = 0; i < results.size(); ++i) {
    for (size_t j = 0; j < results.at(i).size(); ++j) {
      std::cout << results.at(i).at(j) << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
