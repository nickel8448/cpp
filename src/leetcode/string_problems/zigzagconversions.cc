/**
 * zigzagconversions.cc
 * 
 * Purpose:
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * https://leetcode.com/problems/zigzag-conversion/ 
 *   
 * @author Rahul W
 * @version 0.1 02/13/20
 */

#include <iostream>
#include <map>

#include "zigzagconversions.h"

std::string convert(std::string s, int numRows) {
  std::map<int, std::string> outputMap;
  int pos = 0;
  bool incre = true;
  for (int i = 0; i < s.length(); ++i) {
    if (pos == numRows) incre = false;
    if (pos == 1) incre = true;
    if (incre) ++pos;
    else --pos;
    auto itr = outputMap.find(pos);
    if (itr != outputMap.end()) {
      // key is in the map
      itr->second = itr->second + s.at(i);
    } else {
      // key is not in the map
      outputMap[pos] = s.at(i);
    }
  }
  std::string outputString = "";
  for (auto itr = outputMap.begin(); itr != outputMap.end(); ++itr) {
    std::cout << "Key: " << itr->first << " Value: " << itr->second << std::endl;
    outputString += itr->second;
  }
  return outputString;
}

int main() {
  std::string s("PAYPALISHIRING");
  std::cout << convert(s, 3) << std::endl;
  std::cout << convert(s, 4) << std::endl;
  std::cout << convert(s, 5) << std::endl;
}