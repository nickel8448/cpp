#include <iostream>
#include <vector>

using std::vector;

// Solution to Num of Islands LeetCode question
void dfs(const vector<vector<char>> &grid, vector<vector<bool>> &visited,
         size_t i, size_t j);

int numIslands(vector<vector<char>> &grid) {
  int num = 0;
  vector<vector<bool>> visited(grid.size(), vector<bool>(grid.at(0).size()));
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid.at(i).size(); j++) {
      if (!visited.at(i).at(j) && grid.at(i).at(j) == '1') {
        num++;
        dfs(grid, visited, i, j);
      }
    }
  }
  return num;
}

void dfs(const vector<vector<char>> &grid, vector<vector<bool>> &visited,
         size_t i, size_t j) {
  if (i >= 0 && i < grid.size() && j >= 0 && j < grid.at(i).size()) {
    if (grid.at(i).at(j) == '1' && !visited.at(i).at(j)) {
      visited.at(i).at(j) = true;
      dfs(grid, visited, i - 1, j);
      dfs(grid, visited, i + 1, j);
      dfs(grid, visited, i, j + 1);
      dfs(grid, visited, i, j - 1);
    }
  }
}

int main() {

  // Leetcode test case
  // [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
  // [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
  vector<vector<char>> grid{
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
  };
  std::cout << numIslands(grid) << std::endl;
  return 0;
}
