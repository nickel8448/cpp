/*
 * =====================================================================================
 *
 *       Filename:  three_sum.cpp
 *
 *    Description: https://leetcode.com/problems/3sum/
 *    Approach: Brute force
 *
 *        Version:  1.0
 *        Created:  19/05/2020 10:52:27
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
#include <unordered_map>
#include <vector>

using std::vector;

void twoSum(vector<vector<int>> &result, vector<int> &nums, int i);

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> result;
  std::sort(nums.begin(), nums.end());
  for (size_t i = 0; i < nums.size(); ++i) {
    if (i == 0 || nums.at(i) != nums.at(i - 1)) {
      vector<int> temp(nums.begin(), nums.end());
      twoSum(result, temp, i);
    }
  }
  return result;
}

void twoSum(vector<vector<int>> &result, vector<int> &nums, int i) {
  int left = i + 1, right = nums.size() - 1;
  while (left < right) {
    int sum = nums.at(left) + nums.at(right) + nums.at(i);
    if (sum < 0 || (left > i + 1 && nums.at(left) == nums.at(left - 1))) {
      left++;
    } else if (sum > 0 || (right < nums.size() - 1 && nums.at(right) == nums.at(right + 1))) {
      right--;
    } else {
      result.push_back({nums.at(left++), nums.at(right--), nums.at(i)});
    }
  }
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = threeSum(nums);
  for (size_t i = 0; i < result.size(); i++) {
    for (size_t j = 0; j < result.at(i).size(); j++) {
      std::cout << result.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}
