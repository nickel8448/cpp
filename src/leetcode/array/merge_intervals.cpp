#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  vector<vector<int>> result;
  if (intervals.size() == 0) {
    return result;
  } else if (intervals.size() == 1) {
    return intervals;
  }
  std::sort(intervals.begin(), intervals.end());
  int counter = 0;
  vector<int> end_points;
  while (counter < intervals.size()) {
    int start = intervals.at(counter).at(0);
    int end = intervals.at(counter).at(1);
    end_points.push_back(end);
    while (counter + 1 < intervals.size() &&
           end >= intervals.at(counter + 1).at(0)) {
      end = std::max(end, intervals.at(counter + 1).at(1));
      end_points.push_back(end);
      counter++;
    }
    auto new_end = std::max_element(end_points.begin(), end_points.end());
    end_points.clear();
    counter++;
    result.push_back({start, *new_end});
  }
  return result;
}

int main() {
  vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
  vector<vector<int>> results = merge(intervals);
  for (size_t i = 0; i < results.size(); ++i) {
    for (size_t j = 0; j < results.at(i).size(); ++j) {
      std::cout << results.at(i).at(j) << ", ";
    }
    std::cout << std::endl;
  }
}
