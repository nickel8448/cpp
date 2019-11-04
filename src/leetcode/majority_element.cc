/**
 * majority_element.cc
 * Purpose: Functions to implement mergesort
 * 
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * @author Rahul W
 * @version 0.1 10/28/19
 */

#include <iostream>
#include "majority_element.h"


int boyerMooreMajority(std::vector<int>& nums) {
  int currentNum = nums.at(0);
  int counter = 1;

  for (size_t i = 1; i < nums.size(); i++) {
    if (currentNum == nums.at(i)) {
      counter++;
    } else {
      counter--;
      if (counter == 0) {
        currentNum = nums.at(i);
        counter = 1;
      }
    }
  }
  return currentNum;
}


int majorityElement(std::vector<int>& nums) {
  return boyerMooreMajority(nums);
}