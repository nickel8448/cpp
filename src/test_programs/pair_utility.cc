/**
 * pair_utility.cc
 * Purpose: To test how the pair class works
 *  
 * @author Rahul W
 * @version 0.1 11/04/19
 */

#include <utility>
#include <string>
#include <iostream>

int main() {
  std::pair<int, std::string> random;
  std::pair<int, std::string> random2 = std::make_pair(100, "hello");
  random.first = 10;
  random.second = "Hello";
  std::cout << random2.first << std::endl;
}