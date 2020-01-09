/**
 * maximum_subarray.cc
 * Purpose: Implementing maximum subarray problem
 *
 * @author Rahul W
 * @version 0.1 01/08/20
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 

using std::vector;

// Declaring the functions to be implemented later
int FindMaximumSubarrayCrossing(const vector<int> &vec);
int FindMaximumSubarray(const vector<int> &vec);
int FindMaximumNumber(const int &a, const int &b, const int &c);

int FindMaximumSubarray(const vector<int> &vec) {
  if (vec.size() == 1) {
    return vec.at(0);
  }
  int midIndex = vec.size() / 2;
  vector<int> leftArray(vec.begin(), vec.begin() + midIndex);
  vector<int> rightArray(vec.begin() + midIndex, vec.end());
  int maximumSumLeftSubarray = FindMaximumSubarray(leftArray);
  int maximumSumRightSubarray = FindMaximumSubarray(rightArray);
  int maximumSumCrossingSubarray = FindMaximumSubarrayCrossing(vec);
  return std::max({maximumSumLeftSubarray, maximumSumRightSubarray,
                   maximumSumCrossingSubarray});
}

int FindMaximumSubarrayCrossing(const vector<int> &vec) {
  int midIndex = vec.size() / 2, leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
  for (auto itr = vec.rbegin() + midIndex; itr != vec.rend(); ++itr) {
    sum += *itr;
    if (sum > leftSum) leftSum = sum;
  }
  sum = 0;
  for (auto itr = vec.begin() + midIndex + 1; itr != vec.end(); ++itr) {
    sum += *itr;
    if (sum > rightSum) rightSum = sum;
  }
  if (leftSum == INT_MIN || rightSum == INT_MIN) {
    return (leftSum == INT_MIN) ? rightSum : leftSum;
  }
  return (leftSum + rightSum);
}

int main() {
  vector<int> vec {3, -1, -1, 10, -3, -2, 4};
  int midIndex = vec.size() / 2;
  std::cout << FindMaximumSubarray(vec) << std::endl;
}