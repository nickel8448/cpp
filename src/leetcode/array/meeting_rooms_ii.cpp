/**
 * @file meeting_rooms_ii.cpp
 * @author Rahul Wadhwani
 * @brief 
 * @version 0.1
 * @date 2020-06-02
 * 
 * @copyright Copyright (c) 2020
 *
 * Approach:
 * 1. Sort the vector
 * 2. Add the end time to the priority queue
 * 3. If the priority queue top has endtime <= start_time pop
 * 4. Return the size of the queue
 *
 * 0, 30, 
 * 2, 20, 
 * 5, 10, 
 * 5, 15, 
 * 15, 20, 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;

int minMeetingRooms(vector<vector<int>>& intervals) {
  vector<bool> visited(intervals.size());
  int result = 0;
  std::sort(intervals.begin(), intervals.end());
  for(size_t i = 0; i < intervals.size(); ++i) {
    int end_time = intervals.at(i).at(1);
    if(!visited.at(i)) {
      for(size_t j = i + 1; j < intervals.size(); ++j) {
        if(!visited.at(j) && intervals.at(j).at(0) >= end_time) {
          visited.at(j) = true;
          end_time = intervals.at(j).at(1);
        }
      }
    }
    visited.at(i) = true;
    ++result;
  }
  return result;
}

int minMeetingRoomsHeap(vector<vector<int>>& intervals) {
  if(intervals.size() == 0) return 0;
  if(intervals.at(0).size() == 0) return 1;
  std::sort(intervals.begin(), intervals.end());
  struct min_compare {
    bool operator()(int lhs, int rhs) {
      return lhs > rhs;
    }
  };
  std::priority_queue<int, vector<int>, min_compare> end_timing;
  end_timing.push(intervals.at(0).at(1));
  for(size_t i = 1; i < intervals.size(); ++i) {
    int start_time = intervals.at(i).at(0);
    int end_time = intervals.at(i).at(1);
    if(end_timing.size() != 0 && end_timing.top() <= start_time) {
      end_timing.pop();
    }
    end_timing.push(end_time);
  }
  return end_timing.size();
}

int main() {
  vector<vector<int>> intervals = {{0, 30}, {5, 15}, {5, 10}, {2, 20}, {15, 20}};
  std::cout << minMeetingRoomsHeap(intervals) << std::endl;
  std::sort(intervals.begin(), intervals.end());
  for(size_t i = 0; i < intervals.size(); ++i) {
    for(size_t j = 0; j < intervals.at(i).size(); ++j) {
      std::cout << intervals.at(i).at(j) << ", ";
    }
    std::cout << std::endl;
  }
}
