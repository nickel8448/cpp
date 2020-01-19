/**
 * insertionsort_vector.cc
 * Purpose: In this program, insertion sort is implemented on vectors
 * 
 * @author Rahul W
 * @version 0.1 01/10/20
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::vector;

void InsertionSort(vector<int> &nums) {
  for (size_t i = 1; i < nums.size(); ++i) {
    int currentElement = nums.at(i);
    int prevIndex = i - 1;
    while (prevIndex >= 0 && nums.at(prevIndex) > currentElement) {
      nums.at(prevIndex + 1) = nums.at(prevIndex);
      --prevIndex;
    }
    nums.at(prevIndex + 1) = currentElement;
  }
}

int main() {
  vector<int> nums{7, 9, 2, 1, 3};
  InsertionSort(nums);
  std::copy(nums.begin(), nums.end(),
            std::ostream_iterator<int>(std::cout, " "));
}