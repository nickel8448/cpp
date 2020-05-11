/*
 * =====================================================================================
 *
 *       Filename:  evenness_iq_test.cpp
 *
 *    Description: https://codeforces.com/problemset/problem/25/A
 *    Approach: Brute Force
 *
 *        Version:  1.0
 *        Created:  11/05/2020 23:20:23
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

int main() {
  int num, input;
  std::cin >> num;
  std::vector<int> nums;
  for (int i = 0; i < num; i++) {
    std::cin >> input;
    nums.push_back(input);
  }
  int num_even = 0, num_odd = 0, odd_index, even_index;
  for (int i = 0; i < num; i++) {
    if (nums.at(i) % 2 == 0) {
      num_even++;
      even_index = i;
    } else {
      num_odd++;
      odd_index = i;
    }
  }
  if (num_even < num_odd)
    std::cout << even_index + 1 << std::endl;
  else
    std::cout << odd_index + 1 << std::endl;
}
