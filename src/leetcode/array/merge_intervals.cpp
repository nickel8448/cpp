/*
 * =====================================================================================
 *
 *       Filename:  merge_intervals.cpp
 *
 *    Description: https://leetcode.com/problems/merge-intervals/
 *    Approach: Priority Queues
 *
 *        Version:  1.0
 *        Created:  19/05/2020 23:27:38
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
#include <queue>
#include <vector>

using std::vector;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  std::sort(intervals.begin(), intervals.end());
  vector<vector<int>> result;
  int counter = 0;
  std::cout << intervals.size() << std::endl;
  while (counter < intervals.size()) {
    int start = intervals.at(counter).at(0);
    while (counter + 1 < intervals.size() &&
           intervals.at(counter).at(1) < intervals.at(counter + 1).at(0)) {
      counter++;
    }
    int end = intervals.at(counter).at(1);
    result.push_back({start, end});
    counter++;
  }
  return result;
}

int main() {
  vector<vector<int>> intervals = {{1, 5}, {2, 6}, {8, 10}, {11, 12}};
  vector<vector<int>> result = merge(intervals);
  for (size_t i = 0; i < result.size(); i++) {
    for (size_t j = 0; j < result.at(i).size(); j++) {
      std::cout << result.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}
