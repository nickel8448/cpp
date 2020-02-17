/**
 * remove_duplicates.cc
 * Purpose: Removes duplicates from sorted array
 * 
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * @author Rahul W
 * @version 0.1 10/28/19
 */

#include <vector>
#include <iostream>

/**
 * @brief  Function returns the number of unique elements in an integer vector 
 * @note  The leetcode problem requires the function to return the number of 
 * unduped elements
 * @param  nums: Sorted vector of int numbers
 */
int removeDuplicates(std::vector<int>& nums) {
  int i = 0;
  size_t j = 1;
  int size = nums.size();

  for (j; j < size; j++) {
    if (nums[i] != nums[j]) {
      i++;
      nums[i] = nums[j];
    }
  }
  return i + 1;
}


/**
 * @brief  Function removes duplicates from a sorted array
 * @note  The leetcode problem requires the function to return the number of 
 * unduped elements
 * @param  nums: Sorted vector of int numbers
 */
int removeDuplicatesByErasing(std::vector<int>& nums) {
  for (size_t i = 0; i < nums.size(); i++) {
    while (i + 1 < nums.size() && nums.at(i) == nums.at(i + 1)) {
      nums.erase(nums.begin() + i);
    }
  }
  return nums.size();
}