/**
 * majority_element.cc
 * Purpose: Implementing majority element solution
 * https://leetcode.com/problems/majority-element/solution/
 *
 * @author Rahul W
 * @version 0.1 01/08/20
 *
 */

#include <vector>
#include <iostream>

using std::vector;

int majorityElementRec(vector<int> &nums);

template <typename iterator_type>
int countInRange(iterator_type itr, iterator_type end, const int num) {
  int count = 0;
  for (; itr != end; ++itr) {
    if (*itr == num)
      ++count;
  }
  return count;
}

int majorityElementRec(vector<int> &nums) {
  // base cases
  if (nums.size() == 0) return 0;
  if (nums.size() == 1) return nums.at(0);
  
  // Defining left and right sub problems
  size_t midIndex = nums.size() / 2;
  vector<int> leftVector(nums.begin(), nums.begin() + midIndex);
  vector<int> rightVector(nums.begin() + midIndex, nums.end());
  int left = majorityElementRec(leftVector);
  int right = majorityElementRec(rightVector);

  if (left == right)
    return left;

  int leftCount = countInRange(leftVector.begin(), leftVector.end(), left);
  int rightCount = countInRange(rightVector.begin(), rightVector.end(), right);

  return (leftCount > rightCount) ? left : right;
}

int main() {
  // vector<int> nums{3, 3, 3, 3, 3, 3, 1, 2};
  vector<int> nums2{4, 4, 3};
  // std::cout <<majorityElementRec(nums) << std::endl;
  std::cout <<majorityElementRec(nums2) << std::endl;
}