/*
 * =====================================================================================
 *
 *       Filename:  queue_at_the_school.cpp
 *
 *    Description: Problem: https://codeforces.com/problemset/problem/266/B
 *    Logic: 1st approach: Brute force - Did not find any other solution to this
 * online
 *    Solution: Submitted the solution using brute force approach
 *
 *        Version:  1.0
 *        Created:  10/05/20 22:28:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdlib.h>
#include <string>

int main() {
  int queue_length, sec_time;
  std::cin >> queue_length >> sec_time;
  std::cin.ignore();
  std::string que;
  std::getline(std::cin, que);
  for (int j = 0; j < sec_time; ++j) {
    for (int i = 1; i < queue_length; ++i) {
      if (que.at(i - 1) == 'B' && que.at(i) == 'G') {
        std::swap(que[i - 1], que[i]);
        i++;
      }
    }
  }
  std::cout << que << std::endl;
}
