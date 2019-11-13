/**
 * stl_average.cc
 * Purpose: To test what kind of values are returned when a set is used with an
 * iterator
 *  
 * @author Rahul W
 * @version 0.1 10/15/19
 */

#include <numeric>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>


void AccumlateTest(const std::list<int>& numbers) {
  std::cout << "Average is: " <<
    std::accumulate(numbers.begin(), numbers.end(), 0) / numbers.size() <<
    std::endl;
}


void NthElementTest(const std::list<int>& numbers) {
  std::vector<int> numVec(numbers.begin(), numbers.end());
  std::nth_element(numVec.begin(), numVec.begin() + numVec.size()/2,
      numVec.end());
  std::copy(numVec.begin(), numVec.end(),
      std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  std::cout << "Median is: " << numVec[numVec.size()/2] << "\n";
}


int main() {
  std::list<int> numbers;
  for (int i = 0; i < 10; ++i) {
    numbers.push_back(rand() % 100);
  }
  // Printing the numbers list
  std::cout << "Printing the list: " << std::endl;
  std::copy(numbers.begin(), numbers.end(),
      std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  /* AccumlateTest(numbers); */
  NthElementTest(numbers);
}
