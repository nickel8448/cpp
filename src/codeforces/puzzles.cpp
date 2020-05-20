/*
 * =====================================================================================
 *
 *       Filename:  puzzles.cpp
 *
 *    Description: https://codeforces.com/problemset/problem/337/A
 *
 *        Version:  1.0
 *        Created:  11/05/2020 22:37:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int children, num_puzzles, pieces;
  std::cin >> children >> num_puzzles;
  std::vector<int> puzzles;
  for(int i = 0; i < num_puzzles; i++) {
    std::cin >> pieces;
    puzzles.push_back(pieces);
  }
  int min_size = INT_MAX;
  std::sort(puzzles.begin(), puzzles.end());
  for (size_t i = 0; i <= puzzles.size() - children; i++) {
    int first_element = puzzles.at(i);
    int last_element = puzzles.at(i + children - 1);
    if ((last_element - first_element) < min_size)
      min_size = last_element - first_element;
  }
  std::cout << min_size << std::endl;
  return 0;
}
