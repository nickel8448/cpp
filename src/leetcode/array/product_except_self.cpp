/**
 * @file product_except_self.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/product-of-array-except-self/
 * @version 0.1
 * @date 2020-05-29
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <vector>

using std::vector;

vector<int> productExceptSelf(vector<int> &nums) {
  // variable
  vector<int> prefix(nums.size());
  vector<int> suffix(nums.size());

  prefix.at(0) = 1;
  suffix.at(nums.size() - 1) = 1;
  // assigning starting values
  for (size_t i = 1; i < nums.size(); ++i) {
    prefix.at(i) = prefix.at(i - 1) * nums.at(i - 1);
  }
  int i = nums.size() - 2;
  while (i >= 0) {
    suffix.at(i) = suffix.at(i + 1) * nums.at(i + 1);
    i--;
  }

  vector<int> result(nums.size());
  for (size_t i = 0; i < nums.size(); ++i) {
    result.at(i) = prefix.at(i) * suffix.at(i);
  }
  return result;
}

int main() {
  vector<int> nums = {0, 1};
  vector<int> result = productExceptSelf(nums);
  for (int i = 0; i < result.size(); i++) {
    std::cout << result.at(i) << ", ";
  }
  std::cout << std::endl;
}
