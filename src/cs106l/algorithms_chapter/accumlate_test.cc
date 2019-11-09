/**
 * accumlate_test.cc
 * Purpose: Testing how the accumlate function works
 *  
 * @author Rahul W
 * @version 0.1 11/07/19
 */

#include <numeric>
#include <vector>
#include <iostream>

int main() {
  std::vector<int> allNums{1, 2, 3, 4, 5, 6};
  std::cout << std::accumulate(allNums.begin(), allNums.end(), 0.0) / allNums.size() << std::endl;
}
