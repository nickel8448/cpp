/**
 * @file subarray_sum.cpp
 * @author https://leetcode.com/problems/subarray-sum-equals-k/
 * @brief
 * @version 0.1
 * @date 2020-05-24
 *
 * @copyright Copyright (c) 2020
 *
 * Approach:
 * 1. Can't sort because that will change the indicies of the elements
 * 2. Sliding window could be an option but do not know what should be the size
 * of the window
 * 3. Dynamic programming? Maybe not
 * 4. Brute force/backtrack will give O(n^2) - It lead to time limit execeeded
 */

#include <iostream>
#include <vector>

using std::vector;

int subarraySum(vector<int>& nums, int k) {
  if(nums.size() == 0) return 0;
  int num = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    int sum = nums.at(i);
    if(sum == k) {
      ++num;
    }
    for (size_t j = i + 1; j < nums.size(); ++j) {
      sum += nums.at(j);
      if (sum == k) {
        ++num;
      }
    }
  }
  return num;
}

int main() {
  vector<int> nums = {28,54,7,-70,22,65,-6};
  std::cout << subarraySum(nums, 100) << std::endl;
}
