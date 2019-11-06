/**
 * isomorphic_strings.cc
 * https://leetcode.com/problems/isomorphic-strings/
 * Purpose: Check if two strings are isomorphic
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself. 
 * 
 * @author Rahul W
 * @version 0.1 11/05/19
 */


#include <map>
#include <utility>
#include <set>
#include <iostream>
#include "isomorphic_strings.h"

bool isIsomorphicUsingMap(std::string s, std::string t) {
  std::map<char, int> diffMap;
  std::set<char> secondSet;
  
  // assuming that the length of s and t is the same
  for (size_t i = 0; i < s.length(); i++) {
    int diffInChar = s.at(i) - t.at(i);
    if (diffMap.find(s.at(i)) == diffMap.end()) {
      // not found
      diffMap.insert(std::make_pair(s.at(i), diffInChar));
      // if the value already exists in the set means it should already be mapped
      if (secondSet.find(t.at(i)) != secondSet.end()) {
        return false;
      } else {
        secondSet.insert(t.at(i));
      }
    }
    else {
      // char exists in the map
      int currentDiff = diffMap.find(s.at(i))->second;
      if (currentDiff != diffInChar)
        return false;
    }
  }
  return true;
}


bool isIsomorphic(std::string s, std::string t) {
  int cs[128] = {0};
  int ct[128] = {0};
  for (size_t i = 0; i < s.length(); i++) {
    if (cs[s[i]] != ct[t[i]]) return false;
    else if (!cs[s[i]]) { // checking only one segment
      cs[s[i]] = i + 1;
      ct[t[i]] = i + 1;
    }
  }
  return true;
}

// int main() {
//   std::cout << isIsomorphic("paper", "title") << std::endl;
// }