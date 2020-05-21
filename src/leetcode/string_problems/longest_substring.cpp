/*
 * =====================================================================================
 *
 *       Filename:  longest_substring.cpp
 *
 *    Description:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *    Approach: Backtracking
 *
 *        Version:  1.0
 *        Created:  18/05/2020 23:00:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::string;

int lengthOfLongestSubstring(string s) {
  std::unordered_set<char> char_set;
  int ans = 0, start = 0, end = 0;
  while (start < s.size() && end < s.size()) {
    if (char_set.find(s.at(end)) == char_set.end()) {
      // not found in the map
      char_set.insert(s.at(end++));
      ans = std::max(ans, end - start);
    } else {
      char_set.erase(s.at(start++));
    }
  }
  return end - start;
}

int main() {
  string s = "dvdf";
  std::cout << lengthOfLongestSubstring(s) << std::endl;
}
