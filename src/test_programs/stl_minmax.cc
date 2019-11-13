/**
 * stl_minmax.cc
 * Purpose: To test what kind of values are returned when a set is used with an
 * iterator
 *  
 * @author Rahul W
 * @version 0.1 10/15/19
 */

#include <algorithm>
#include <list>
#include <iostream>
#include <iterator>


void MinAndMaxTest(const std::list<int>& numbers) {
  auto[min, max] = std::minmax_element(numbers.begin(), numbers.end());
  std::cout << "Min number is: " << *min << std::endl;
  std::cout << "Max number is: " << *max << std::endl;
}


int main() {
  std::list<int> numbers;
  for (int i = 0; i < 10; ++i) {
    numbers.push_back(rand() % 100);
  }
  // Printing the numbers list
  std::copy(numbers.begin(), numbers.end(),
      std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  std::cout << "Printing the minimum and maximum number" << std::endl;
  MinAndMaxTest(numbers);
}
