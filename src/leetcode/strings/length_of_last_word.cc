/**
 * length_of_last_word.cc
 * Purpose: Given a string s consists of upper/lower-case alphabets and empty 
 * space characters ' ', return the length of last word in the string.
 *
 * https://leetcode.com/problems/length-of-last-word/ 
 *
 * @author Rahul W
 * @version 0.1 11/08/19
 */


#include <sstream>

int lengthOfLastWord(std::string s) {
  std::stringstream tempStream(s);
  std::string tempString;
  int counter = 0;
  while (tempStream >> tempString) {
    counter++;
  }
  if (counter == 0) return 0;
  return tempString.size();
}
