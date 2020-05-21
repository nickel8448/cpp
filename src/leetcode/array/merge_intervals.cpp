<<<<<<< HEAD
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
=======
#include <algorithm>
#include <iostream>
>>>>>>> 96951f08eb26c7b6a812773a818bcc0a5dce38f9
#include <vector>

using std::vector;

<<<<<<< HEAD
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
=======
vector<vector<int>> merge(vector<vector<int>> &intervals) {
  vector<vector<int>> result;
  if(intervals.size() == 0) {
    return result;
  } else if(intervals.size() == 1) {
    return intervals;
  }
  std::sort(intervals.begin(), intervals.end());
  int counter = 0;
  vector<int> end_points;
  while (counter < intervals.size()) {
    int start = intervals.at(counter).at(0);
    int end = intervals.at(counter).at(1);
    end_points.push_back(end);
    while (counter + 1 < intervals.size() && end >= intervals.at(counter + 1).at(0)) {
      end = std::max(end, intervals.at(counter + 1).at(1));
      end_points.push_back(end);
      counter++;
    }
    auto new_end = std::max_element(end_points.begin(), end_points.end());
    end_points.clear();
    counter++;
    result.push_back({start, *new_end});
>>>>>>> 96951f08eb26c7b6a812773a818bcc0a5dce38f9
  }
  return result;
}

int main() {
<<<<<<< HEAD
  vector<vector<int>> intervals = {{1, 5}, {2, 6}, {8, 10}, {11, 12}};
  vector<vector<int>> result = merge(intervals);
  for (size_t i = 0; i < result.size(); i++) {
    for (size_t j = 0; j < result.at(i).size(); j++) {
      std::cout << result.at(i).at(j) << " ";
=======
  vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
  vector<vector<int>> results = merge(intervals);
  for (size_t i = 0; i < results.size(); ++i) {
    for (size_t j = 0; j < results.at(i).size(); ++j) {
      std::cout << results.at(i).at(j) << ", ";
>>>>>>> 96951f08eb26c7b6a812773a818bcc0a5dce38f9
    }
    std::cout << std::endl;
  }
}
