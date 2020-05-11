/*
 * =====================================================================================
 *
 *       Filename:  merge_sorted_array.cpp
 *
 *    Description: Solution to problem
 * https://leetcode.com/problems/merge-sorted-array/
 *
 *        Version:  1.0
 *        Created:  11/05/2020 13:28:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>
#include <vector>

using std::vector;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int nums2_end_pointer = n - 1;
  int nums1_end_pointer = m - 1;
  int counter = m + n - 1;
  while (nums1_end_pointer >= 0 && nums2_end_pointer >= 0) {
    if (nums2.at(nums2_end_pointer) > nums1.at(nums1_end_pointer)) {
      nums1.at(counter--) = nums2.at(nums2_end_pointer--);
    } else {
      nums1.at(counter--) = nums1.at(nums1_end_pointer--);
    }
  }
  while (nums2_end_pointer >= 0) {
    nums1.at(counter--) = nums2.at(nums2_end_pointer--);
  }
  std::copy(nums1.begin(), nums1.end(),
            std::ostream_iterator<int>(std::cout, " "));
}
