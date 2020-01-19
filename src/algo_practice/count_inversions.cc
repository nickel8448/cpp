#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>

#include "count_inversions.h"

using std::vector;

void SortAndCountInversions(vector<int> &left, vector<int> &right,
                            vector<int> &input, unsigned long &inversionTracker)
{
  // Filling values in the left and right array
  vector<int> leftVector(left.begin(), left.end());
  vector<int> rightVector(right.begin(), right.end());

  size_t  i = 0, j = 0, outputCounter = 0;

  while (i < leftVector.size() && j < rightVector.size()) {
    if (leftVector.at(i) < rightVector.at(j)) {
      input.at(outputCounter) = leftVector.at(i);
      ++i;
    } else {
      input.at(outputCounter) = rightVector.at(j);
      ++j;
      inversionTracker += leftVector.size() - i;
    }
    ++outputCounter;
  }

  while (i < leftVector.size()) {
    input.at(outputCounter) = leftVector.at(i);
    ++i;
    ++outputCounter;
  } 
  while (j < rightVector.size()) {
    input.at(outputCounter) = rightVector.at(j);
    ++j;
    ++outputCounter;
  }
}

unsigned long CountInversions(vector<int> &input) {
  unsigned long inversionTracker = 0;
  return CountInversionsRec(input, inversionTracker);
}

unsigned long CountInversionsRec(vector<int> &input,
                                 unsigned long &inversionTracker) {
  if (input.size() < 2)
    return 0;
  int midIndex = input.size() / 2;
  vector<int> left;
  vector<int> right;

  // Dividing vectors in left and right side
  std::copy(input.begin(), input.begin() + midIndex, std::back_inserter(left));
  std::copy(input.begin() + midIndex, input.end(), std::back_inserter(right));

  // Working on the merge sort and counting inversions
  CountInversionsRec(left, inversionTracker);
  CountInversionsRec(right, inversionTracker);
  SortAndCountInversions(left, right, input, inversionTracker);
  return inversionTracker;
}

int main() {
  // Reading the numbers from the file into a vector
  std::ifstream is("res/inversion.txt");
  if (is.fail()) std::cout << "File could not be opened" << std::endl;
  std::istream_iterator<int> start(is), end;
  vector<int> numbers(start, end);

  std::cout << "Number of inversions: " << CountInversions(numbers) << std::endl;
}