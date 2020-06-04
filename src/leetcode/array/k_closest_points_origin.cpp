/**
 * @file k_closest_points_origin.cpp
 * @author Rahul Wadhwani
 * @brief
 * @version 0.1
 * @date 2020-05-30
 *
 * @copyright Copyright (c) 2020
 * Approach: calculate the closest points to the origin and store them in a heap
 * to know which are the K closest points to the origin
 */

#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using std::vector;

typedef std::pair<vector<int>, double> vec_distance;

vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
  struct compare {
    bool operator()(const vec_distance &lhs, const vec_distance &rhs) {
      return lhs.second < rhs.second;
    }
  };
  std::priority_queue<vec_distance, vector<vec_distance>, compare> pq;

  // calculate the distance from the origin for all the points
  for (size_t i = 0; i < points.size(); ++i) {
    double distance_from_origin = std::sqrt(std::pow(points.at(i).at(0), 2) +
                                            std::pow(points.at(i).at(1), 2));
    vec_distance current = std::make_pair(points.at(i), distance_from_origin);
    pq.push(current);
    if (pq.size() > K) {
      pq.pop();
    }
  }
  vector<vector<int>> result;
  while (pq.size() != 0) {
    result.push_back(pq.top().first);
    pq.pop();
  }
  return result;
}

int main() {
  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  kClosest(points, 2);
  return 0;
}
