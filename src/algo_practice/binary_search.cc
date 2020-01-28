/**
 * binary_search.cc
 * Purpose: Implementing binary search on 1D and 2D vectors
 *
 * @author Rahul W
 * @version 0.1 01/19/20
 *
 */

#include <iterator>
#include <vector>
#include <iostream>

using std::vector;

// Recursive function to do binary search on a 1D vector
int FindNumInVectorRec(vector<int>& nums, int start, int end, int numToFind) {
  if (end >= start) {
    int mid = (start + end) / 2; 
    if (nums.at(mid) == numToFind) return mid;

    if (numToFind > nums.at(mid)) {
      return FindNumInVectorRec(nums, mid + 1, end, numToFind);
    }
    else {
      return FindNumInVectorRec(nums, start, mid - 1, numToFind);
    }
  }
  return -1;
}

int FindNumInVector(vector<int>& nums, int numToFind) {
  return FindNumInVectorRec(nums, 0, nums.size() - 1, numToFind);
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (size_t i = 1; i <= nums.size(); ++i) {
    std::cout << FindNumInVector(nums, i) << std::endl;
  }
}