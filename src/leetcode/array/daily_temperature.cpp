/*
 * =====================================================================================
 *
 *       Filename:  daily_temperature.cpp
 *
 *    Description: https://leetcode.com/problems/daily-temperatures/
 *    Approach: Use a stack
 *
 *        Version:  1.0
 *        Created:  22/05/2020 17:10:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

using std::vector;

vector<int> dailyTemperatures(vector<int>& T) {
  vector<int> result(T.size(), 0);
  if(T.size() == 0) return result;
  int pointer = T.size() - 1;
  // pair -> (temperature, index)
  std::stack<std::pair<int, int>> temp_stack;
  while (pointer != -1) {
    int current_temp = T.at(pointer);
    auto p = std::make_pair(current_temp, pointer);
    if (temp_stack.size() == 0) {
      result.at(pointer) = 0;
    } else if (current_temp >= temp_stack.top().first) {
      // current day is warmer than the current day on the stack
      while (temp_stack.size() != 0 && current_temp >= temp_stack.top().first) {
        temp_stack.pop();
      }
      if (temp_stack.size() != 0) {
        result.at(pointer) = temp_stack.top().second - pointer;
      } else {
        result.at(pointer) = 0;
      }
    } else if (current_temp <= temp_stack.top().first) {
      // current day is colder than the current day on stack
      result.at(pointer) = temp_stack.top().second - pointer;
    }
    temp_stack.push(p);
    --pointer;
  }
  return result;
}

int main() {
  vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> result = dailyTemperatures(T);
  std::copy(result.begin(), result.end(),
            std::ostream_iterator<int>(std::cout, " "));
}
