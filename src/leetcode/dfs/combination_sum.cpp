/**
 * @file combination_sum.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/combination-sum-ii/
 * @version 0.1
 * @date 2020-05-23
 *
 * DFS backtracking approach
 *
 *
 * @copyright Copyright (c) 2020
 *
 */

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void dfs(vector<int> &candidates, int target, vector<vector<int>> &result,
         vector<int> &running_vec, int index) {
  if (target == 0) {
    vector<int> temp(running_vec);
    result.push_back(temp);
  } else {
    for (size_t i = index; i < candidates.size(); ++i) {
      if (i > index && candidates.at(i) == candidates.at(i - 1))
        continue;
      int element = candidates.at(i);
      if (target - element >= 0) {
        running_vec.push_back(element);
        dfs(candidates, target - element, result, running_vec, i + 1);
        running_vec.pop_back();
      }
    }
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
  vector<vector<int>> result;
  if (candidates.size() == 0)
    return result;
  std::sort(candidates.begin(), candidates.end());
  vector<int> running_vec;
  dfs(candidates, target, result, running_vec, 0);
  return result;
}

int main() {
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  vector<vector<int>> result = combinationSum2(candidates, 8);
  for (size_t i = 0; i < result.size(); ++i) {
    for (size_t j = 0; j < result.at(i).size(); ++j) {
      std::cout << result.at(i).at(j) << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}