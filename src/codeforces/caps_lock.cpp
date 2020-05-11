/*
 * =====================================================================================
 *
 *       Filename:  caps_lock.cpp
 *
 *    Description: https://codeforces.com/problemset/problem/131/A
 *    Approach: Simple loop
 *
 *        Version:  1.0
 *        Created:  11/05/2020 20:55:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string input;
  std::cin >> input;
  for (size_t i = 0; i < input.size(); i++) {
    if (i == 0)
      input.at(i) = toupper(input.at(i));
    else
      input.at(i) = tolower(input.at(i));
  }
  std::cout << input << std::endl;
}
