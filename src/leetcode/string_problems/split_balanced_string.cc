/**
 * split_balanced_string.cc
 * https://leetcode.com/problems/split-a-string-in-balanced-strings/
 * Purpose: Retrieve the number of balanced substring in a string
 * 
 * Balanced strings are those who have equal quantity of 'L' and 'R' characters.
 * 
 * Given a balanced string s split it in the maximum amount of balanced strings.
 * 
 * Return the maximum amount of splitted balanced strings.
  * 
 * @author Rahul W
 * @version 0.1 11/06/19
 */

#include <iostream>

#include "split_balanced_string.h"


int balancedStringSplit(const std::string s) {
  if (s.size() <= 1) return 0;
  int result = 0;
  int alphabet = s[0];
  int numCharOne = 1, numCharTwo = 0;
  for (size_t i = 1; i < s.size(); i++) {
    if (s.at(i) == alphabet)
      numCharOne++;
    else
      numCharTwo++;
    if (numCharOne == numCharTwo) {
      result++;
      numCharOne = numCharTwo = 0;
      alphabet = s[i+1];
    }
  }
  return result;
}