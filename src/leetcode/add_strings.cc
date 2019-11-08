/**
 * add_strings.cc
 * Purpose: Given two non-negative integers num1 and num2 represented as
 * string, return the sum of num1 and num2. 
 * 
 * https://leetcode.com/problems/add-strings/
 *
 * @author Rahul W
 * @version 0.1 11/07/19
 */


#include <string>
#include <iostream>


std::string addStrings(std::string num1, std::string num2) {
  size_t counter = 0;
  std::string result = "";
  int carryOn = 0;
  while(counter < num1.size() || counter < num2.size()) {
    int num1Latest = 0;
    int num2Latest = 0;
    if (counter < num1.size()) 
      num1Latest = num1.at(num1.size() - counter - 1) - '0';
    if (counter < num2.size()) 
      num2Latest = num2.at(num2.size() - counter - 1) - '0';
    int tempTotal = num1Latest + num2Latest + carryOn;
    carryOn = tempTotal / 10;
    tempTotal = tempTotal % 10;
    result = std::to_string(tempTotal).at(0) + result;
    counter++;
    /* carryOn = 0; */
  }
  if (carryOn == 1) result = '1' + result;
  return result;
}
