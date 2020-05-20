/**
 * valid_perfect_square.cc
 * Purpose: https://leetcode.com/problems/find-the-town-judge/
 * Approach: Used binary search to get find the perfect square
 *
 * @author Rahul W
 * @version 0.1 10/20/19
 */

#include <iostream>

bool isPerfectSquare(int num) {
  int low = 0;
  int high = num;
  bool result = false;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long squared_value = mid * mid;
    if (squared_value > num) {
      high = mid - 1;
    } else if (squared_value < num) {
      low = mid + 1;
    } else {
      result = true;
      break;
    }
  }
  return result;
}
