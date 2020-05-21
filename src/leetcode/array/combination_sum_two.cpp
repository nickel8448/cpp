/*
 * =====================================================================================
 *
 *       Filename:  combination_sum_two.cpp
 *
 *    Description: https://leetcode.com/problems/combination-sum-ii/
 *    Approach: Backtracking with a map
 *
 *        Version:  1.0
 *        Created:  18/05/2020 15:22:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void dfs(vector<int>& candidates, int target, int index,
         vector<vector<int>>& result, vector<int>& nums);

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  vector<vector<int>> result;
  std::sort(candidates.begin(), candidates.end());
  vector<int> nums;
  dfs(candidates, target, 0, result, nums);
  return result;
}

void dfs(vector<int>& candidates, int target, int index,
         vector<vector<int>>& result, vector<int>& nums) {
  if (target < 0) {
    return;
  } else if (target == 0) {
    vector<int> temp(nums);
    result.push_back(temp);
  } else {
    for (size_t i = index; i < candidates.size(); ++i) {
      if (i > index && candidates.at(i) == candidates.at(i - 1)) continue;
      nums.push_back(candidates.at(i));
      dfs(candidates, target - candidates.at(i), i + 1, result, nums);
      nums.pop_back();
    }
  }
}

int main() {
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  vector<vector<int>> result = combinationSum2(candidates, 8);
  for (size_t i = 0; i < result.size(); i++) {
    for (size_t j = 0; j < result.at(i).size(); j++) {
      std::cout << result.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}
