/*
 * =====================================================================================
 *
 *       Filename:  kefa_first_steps.cpp
 *
 *    Description: https://codeforces.com/problemset/problem/580/A
 *    Approach: Buy and sell stocks kinda
 *
 *        Version:  1.0
 *        Created:  11/05/2020 21:08:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>
#include <vector>

int main() {
  int num_days;
  std::cin >> num_days;
  std::vector<int> days;
  for (int i = 0; i < num_days; i++) {
    int day;
    std::cin >> day;
    days.push_back(day);
  }
  int max_days = 1;
  int current_days = 1;
  int prev = days.at(0);
  for (size_t i = 1; i < days.size(); i++) {
    if (days.at(i) >= prev) {
      current_days++;
    } else {
      current_days = 1;
    }
    prev = days.at(i);
    if (current_days > max_days) max_days = current_days;
  }
  std::cout << max_days << std::endl;
}
