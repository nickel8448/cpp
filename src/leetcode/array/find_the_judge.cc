/**
 * find_the_judge.cc
 * Purpose: https://leetcode.com/problems/find-the-town-judge/
 * Approach: Directed graph and calculated indegree and outdegree
 *
 * @author Rahul W
 * @version 0.1 10/20/19
 */

#include <iostream>
#include <vector>

using std::vector;

int findJudge(int N, vector<vector<int>>& trust) {
  vector<int> indegree(N + 1, 0);
  vector<int> outdegree(N + 1, 0);
  for (auto& relation : trust) {
    outdegree.at(relation[0])++;
    indegree.at(relation[1])++;
  }
  for (int i = 1; i <= N; i++) {
    if (indegree.at(i) == N - 1 && outdegree.at(i) == 0) return i;
  }
  return -1;
}

int main() {
  vector<vector<int>> input = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
  std::cout << findJudge(4, input) << std::endl;
}
