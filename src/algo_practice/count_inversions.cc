#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using std::vector;

void SortAndCountInversions(vector<int> &left, vector<int> &right,
                            vector<int> &input, int &inversionTracker)
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

int SortAndCountInversions(vector<int> &input, int &inversionTracker) {
  if (input.size() < 2)
    return 0;
  int midIndex = input.size() / 2;
  vector<int> left;
  vector<int> right;

  // Dividing vectors in left and right side
  std::copy(input.begin(), input.begin() + midIndex, std::back_inserter(left));
  std::copy(input.begin() + midIndex, input.end(), std::back_inserter(right));

  // Working on the merge sort and counting inversions
  SortAndCountInversions(left, inversionTracker);
  SortAndCountInversions(right, inversionTracker);
  SortAndCountInversions(left, right, input, inversionTracker);
  return inversionTracker;
}

int main(int argc, char const *argv[])
{
  vector<int> mainVector;
  mainVector.push_back(6);
  mainVector.push_back(4);
  mainVector.push_back(2);
  mainVector.push_back(5);
  mainVector.push_back(3);
  mainVector.push_back(1);
  int inversionTracker = 0;
  std::cout << "Num of inversions: "
            << SortAndCountInversions(mainVector, inversionTracker)
            << std::endl;
  std::copy(mainVector.begin(), mainVector.end(), std::ostream_iterator<int>(std::cout, " "));
  return 0;
}
