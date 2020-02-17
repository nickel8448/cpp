/**
 * reverse_words_in_a_string.cc
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/
 *
 * Purpose: Given a string, you need to reverse the order of characters in
 * each word within a sentence while still preserving whitespace and initial
 * word order
 * 
 * @author Rahul W
 * @version 0.1 11/07/19
 */

#include <sstream>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>

#include "reverse_words_in_a_string.h"


std::string reverseWords(std::string s) {
  int front = 0;
  for (size_t i = 0; i <= s.size(); i++) {
    if (i == s.size() || s.at(i) == ' ') {
      std::reverse(&s[front], &s[i]);
      front = i + 1;
    }
  }
  return s;
}
