/*
 * =====================================================================================
 *
 *       Filename:  longest_common_substring.cpp
 *
 *    Description: https://leetcode.com/problems/longest-palindromic-substring/
 *
 *        Version:  1.0
 *        Created:  18/05/2020 22:23:51
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

using std::string;

int expand_from_middle(string& s, int left, int right);

string longestPalindrome(string s) {
  if (s.length() == 0) return "";
  int start = 0, end = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    int len1 = expand_from_middle(s, i, i);
    int len2 = expand_from_middle(s, i, i + 1);
    int len = std::max(len1, len2);
    int current_length = end - start;
    if (len > current_length) {
      start = i - ((len - 1) / 2);
      end = i + (len / 2);
    }
  }
  return s.substr(start, end + 1);
}

int expand_from_middle(string& s, int left, int right) {
  if (left > right || s.length() == 0) return 0;
  while (left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
    left--;
    right++;
  }
  return right - left - 1;
}

int main() { std::cout << longestPalindrome("hello") << std::endl; }
