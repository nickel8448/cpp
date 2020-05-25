/**
 * @file subarray_sum_equals.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/subarray-sum-equals-k/
 * @version 0.1
 * @date 2020-05-25
 *
 * @copyright Copyright (c) 2020
 *
 * Approach: Use HashMap
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

int subarraySum(vector<int> &nums, int k) {
  // cumalative_sum -> count
  unordered_map<int, int> sum_count_map;
  sum_count_map.insert(std::make_pair(0, 1));
  int sum = 0, num = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    sum += nums.at(i);
    if (sum_count_map.find(sum - k) != sum_count_map.end()) {
      num += sum_count_map.at(sum - k);
    }
    if (sum_count_map.find(sum) != sum_count_map.end()) {
      sum_count_map[sum]++;
    } else {
      sum_count_map.insert(std::make_pair(sum, 1));
    }
  }
  return num;
}

int main() {
  vector<int> nums = {0, 0, 0, 0, 0, 0, 0};
  std::cout << subarraySum(nums, 0) << std::endl;
  return 0;
}
