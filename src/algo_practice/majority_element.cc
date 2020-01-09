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
  int leftMax = majorityElementRec(leftVector);
  int rightMax = majorityElementRec(rightVector);

  if (leftMax == rightMax) return leftMax;

  int leftCount = countInRange(leftVector.begin(), leftVector.end(), leftMax);
  int rightCount = countInRange(rightVector.begin(), rightVector.end(), rightMax);

  return (leftCount > rightCount) ? leftMax : rightMax;
}

int main() {
  vector<int> nums{3, 3, 3, 3, 3, 3, 1, 2};
  std::cout <<majorityElementRec(nums) << std::endl;

}