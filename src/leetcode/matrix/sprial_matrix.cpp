/**
 * @file sprial_matrix.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/spiral-matrix/
 * @version 0.1
 * @date 2020-05-24
 * @copyright Copyright (c) 2020
 */

/**
 * Approach: Simulation
 * Status: Pending
 */

#include <iostream>
#include <vector>

using std::vector;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix.size()));
  vector<int> result;
  return result;
}

int main() {
  vector<vector<bool>> visited(10, vector<bool>(10));
  for (int i = 0; i < visited.size(); i++) {
    for (int j = 0; j < visited.at(i).size(); j++) {
      std::cout << visited.at(i).at(j) << ", ";
    }
    std::cout << std::endl;
  }
}
