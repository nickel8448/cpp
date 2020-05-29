/**
 * @file top_k_frequent_elements.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/top-k-frequent-elements/
 * @version 0.1
 * @date 2020-05-29
 *
 * @copyright Copyright (c) 2020
 *
 * Approach: Used a heap to keep a track of top k frequent numbers. Did not use
 * a map because that would have made the run time to be O(nlogn) and not
 * O(nlogk)
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using std::vector;

/**
 * @brief Returns the top k frequent elements in a vector
 * This function uses heap to do that
 * @param nums
 * @param k
 * @return vector<int>
 */
vector<int> topKFrequent(vector<int> &nums, int k) {
  struct comp {
    bool operator()(const std::pair<int, int> &lhs,
                    const std::pair<int, int> &rhs) {
      return lhs.second > rhs.second;
    }
  };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      comp>
      pq;
  // num -> frequency
  std::unordered_map<int, int> frequency_map;
  for (size_t i = 0; i < nums.size(); ++i) {
    int element = nums.at(i);
    if (frequency_map.find(element) != frequency_map.end()) {
      frequency_map[element]++;
    } else {
      frequency_map.insert(std::make_pair(element, 1));
    }
  }

  // Inserting the element in the priority_queue
  for (auto itr = frequency_map.begin(); itr != frequency_map.end(); itr++) {
    if (k > 0) {
      std::pair<int, int> to_push(itr->first, itr->second);
      pq.push(to_push);
      k--;
    }
  }

  vector<int> result;
  while (pq.size() != 0) {
    result.push_back(pq.top().first);
    pq.pop();
  }

  return result;
}
