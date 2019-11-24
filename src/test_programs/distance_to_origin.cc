/**
 * remove_short_words.cc
 * Purpose: Problem 7 from Chapter 7. Write a function using remove_if to
 *  
 * @author Rahul W
 * @version 0.1 11/13/19
 */

#include <vector>
#include <numeric>
#include <cmath>
#include <iostream>


// Function computes the distance to origin for the given points
double DistanceToOrigin(const std::vector<double>* points) {
  double innerProduct = std::inner_product(points->begin(), points->end(),
      points->begin(), 0);
  return sqrt(innerProduct);
}


int main() {
  std::vector<double> points{15.0, -8};
  std::cout << DistanceToOrigin(&points) << std::endl;
}
