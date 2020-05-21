/*
 * =====================================================================================
 *
 *       Filename:  combination_sum.cpp
 *
 *    Description: https://leetcode.com/problems/combination-sum/
 *    Approach: Backtracking
 *
 *        Version:  1.0
 *        Created:  18/05/2020 12:50:29
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

void dfs(vector<int>& candidates, vector<vector<int>>& result,
         vector<int>& temp, int target, int index);

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> result;
  vector<int> temp;
  std::sort(candidates.begin(), candidates.end());
  dfs(candidates, result, temp, target, 0);
  return result;
}

void dfs(vector<int>& candidates, vector<vector<int>>& result,
         vector<int>& temp, int target, int index) {
  if (target < 0) {
    return;
  } else if (target == 0) {
    vector<int> to_push(temp);
    result.push_back(to_push);
  } else {
    for (size_t i = index; i < candidates.size(); ++i) {
      int element = candidates.at(i);
      temp.push_back(candidates.at(i));
      dfs(candidates, result, temp, target - element, i);
      temp.pop_back();
    }
  }
}

int main() {
  vector<int> nums = {2, 3, 6, 7};
  vector<vector<int>> result = combinationSum(nums, 7);
  std::cout << "Printing result" << std::endl;
  for (size_t i = 0; i < result.size(); i++) {
    for (size_t j = 0; j < result.at(i).size(); j++) {
      std::cout << result.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}
