/**
 * vector_intersection.cc
 * Purpose: Solution to question 16 from Chapter 7. Elements are stored in
 * sorted order in two vector<int>s. Show the common elements using 
 * set_intersection
 *   
 * @author Rahul W
 * @version 0.1 11/15/19
 */


#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>


int main() {
  std::vector<int> vec1 = {2, 7, 9, 10, 12, 59, 100};
  std::vector<int> vec2 = {1, 7, 7, 24, 50, 52, 59};
  std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),
      std::ostream_iterator<int>(std::cout, " "));
}
