/*
 * =====================================================================================
 *
 *       Filename:  declined_finalists.cpp
 *
 *    Description: Solution to problem:
 * https://codeforces.com/problemset/problem/859/A
 *
 *        Version:  1.0
 *        Created:  09/05/2020 12:09:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int k;
  std::cin >> k;
  std::vector<int> contestants;
  for (int i = 0; i < k; i++) {
    int contestantRank;
    std::cin >> contestantRank;
    contestants.push_back(contestantRank);
  }
  auto it = max_element(contestants.begin(), contestants.end());
  if (*it > 25) {
    printf("%d\n", *it - 25);
  } else {
    printf("%d\n", 0);
  }
}
