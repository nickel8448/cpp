/**
 * second_largest.cc
 * Purpose: To implement an algorithms that finds the 2nd largest element in an
 * unsorted array of size n
 *
 * @author Rahul W
 * @version 0.1 12/28/19
 *
 * TODO: Implement the rest from this paper - http://users.csc.calpoly.edu/~dekhtyar/349-Spring2010/lectures/lec03.349.pdf
 */

#include <cstddef>
#include <iostream>

int FindMaxRecursive(int startElement, int endElement, int arr[]) {
  if (startElement == endElement)
    return arr[startElement];  // base case
  int midValue = startElement + (endElement - startElement) / 2;
  int maxOne = FindMaxRecursive(startElement, midValue, arr);
  int maxTwo = FindMaxRecursive(1 + midValue, endElement, arr);
  if (maxOne > maxTwo)
    return maxOne;
  return maxTwo;
}

int main() {
  int arr[] = {10, 2, 40, 12, 53, 52};
  int size = sizeof(arr) / sizeof(arr[0]);
  std::cout << FindMaxRecursive(0, size, arr) << std::endl;
}