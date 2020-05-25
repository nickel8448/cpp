/**
 * @file generate_paranthesis.cpp
 * @author Rahul Wadhwani
 * @brief https://leetcode.com/problems/generate-parentheses/
 * @version 0.1
 * @date 2020-05-23
 *
 * @copyright Copyright (c) 2020
 *
 */

// input n = 3
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

void recurse(vector<string> &result, string running, int n, int open_brackets,
             int close_brackets) {
  if (running.size() == n * 2) {
    result.push_back(running);
    return;
  } else {
    if (open_brackets < n)
      recurse(result, running + "(", n, open_brackets + 1, close_brackets);
    if (close_brackets < open_brackets)
      // the reason we are using < open_brackets is because number of closing
      // brackets cannot be more than open brackets
      // This is a constraint
      recurse(result, running + ")", n, open_brackets, close_brackets + 1);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> result;
  string running;
  recurse(result, running, n, 0, 0);
  return result;
}

int main() {
  vector<string> result = generateParenthesis(3);
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result.at(i) << std::endl;
  }
  return 0;
}
