/**
 * quicksort.cc
 * Purpose: In this program quick sort is implemented 
 * 
 * @author Rahul W
 * @version 0.1 01/16/20
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>

using std::vector;

// Function paritions the array using first element as the parition element
int Partition(vector<int> &nums, int low, int high) {
  int pivotIndex = low;
  int paritionElement = nums.at(pivotIndex);
  int potentialPivotIndex = low + 1;
  for (int i = low + 1; i <= high; ++i) {
    if (paritionElement > nums.at(i)) {
      std::swap(nums.at(potentialPivotIndex), nums.at(i));
      ++potentialPivotIndex;
    }
  }
  std::swap(nums.at(potentialPivotIndex - 1), nums.at(pivotIndex));
  return potentialPivotIndex - 1;
}


// Function uses the last element in the array as the pivot element
int ParitionEndElement(vector<int> &nums, int low, int high) {
  int pivotIndex = high;
  int paritionElement = nums.at(pivotIndex);
  int potentialPivotIndex = low;
  for (int i = low; i < high; ++i) {
    if (paritionElement > nums.at(i)) {
      std::swap(nums.at(i), nums.at(potentialPivotIndex));
      ++potentialPivotIndex;
    }
  }
  std::swap(nums.at(potentialPivotIndex), nums.at(pivotIndex));
  return potentialPivotIndex;
}

// Function does the partioning of an array by selecting median-of-median
// element from the array
int PartitionWithMedian(vector<int> &nums, int low, int high) {
  // Median calculation
  int x = nums.at(low), y = nums.at((high + low) / 2), z = nums.at(high);
  int toSwap = 0;
  if ((y>z && y<x) || (y>x && y<z)) toSwap = y;
  else if ((z>y && z<x) || (z>x && z<y)) toSwap = z;
  else toSwap = x;
  //TODO: Swap the pivotElement with the high index and continue
  std::swap(nums.at(toSwap), nums.at(high));
  int pivotIndex = high;
  int paritionElement = nums.at(pivotIndex);
  int potentialPivotIndex = low;
  for (int i = low; i < high; ++i) {
    if (paritionElement > nums.at(i)) {
      std::swap(nums.at(i), nums.at(potentialPivotIndex));
      ++potentialPivotIndex;
    }
  }
  std::swap(nums.at(potentialPivotIndex), nums.at(pivotIndex));
  return potentialPivotIndex;
}

void QuickSort(vector<int> &nums, int low, int high,
               unsigned long &numComparisons) {
  numComparisons += (high - low);
  int p = 0;
  if ((high - low) > 0) {
    p = ParitionEndElement(nums, low, high);
    QuickSort(nums, low, p - 1, numComparisons);
    QuickSort(nums, p + 1, high, numComparisons);
  }
}

int main() {
  vector<int> nums = {5, 8, 7, 1, 3, 2, 6, 4};
  std::ifstream is("res/quicksort.txt");
  if (is.fail()) std::cout << "File could not be opened" << std::endl;
  std::istream_iterator<int> start(is), end;
  std::vector<int> numbers(start, end);
  unsigned long numComparisons = 0;
  // std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " " ));
  QuickSort(numbers, 0, numbers.size() - 1, numComparisons);
  std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " " ));
  std::cout << numComparisons << std::endl;
}