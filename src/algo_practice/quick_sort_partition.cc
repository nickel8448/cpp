/**
* maximum_subarray.cc
* Purpose: Implementing maximum subarray problem
*
* @author Rahul W
* @version 0.1 01/08/20
*
**/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::vector;

void QuickParition(vector<int> &nums, int pivotIndex) {
  if (pivotIndex != 0) std::swap(nums[pivotIndex], nums[0]);
  vector<int> temp(nums.size());
  int leftIndex = 0;
  int rightIndex = nums.size() - 1;

  int pivotElement = nums[0];

  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums.at(i) > pivotElement) {
      temp.at(rightIndex) = nums.at(i);
      --rightIndex;
    } else {
      temp.at(leftIndex) = nums.at(i);
      ++leftIndex;
    }
  }
  temp.at(leftIndex) = pivotElement;
  nums = temp;
}

int main() {
  vector<int> nums{5, 8, 2, 3, 1, 4, 7, 6};
  QuickParition(nums, 3);
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout,  " "));
}