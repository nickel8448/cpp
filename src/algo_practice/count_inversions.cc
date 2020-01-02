#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using std::vector;

int MergeInversions(const vector<int> &input, int &inversionTracker)
{
  vector<int> tempVector;
}

int CountInversions(const vector<int> &input, int &inversionTracker)
{
  if (input.size() < 2)
    return 0;
  int midIndex = input.size() / 2;
  vector<int> left;
  vector<int> right;
  // Copying values into the left and right vector
  std::copy(input.begin(), input.begin() + midIndex, std::back_inserter(left));
  std::copy(input.begin() + midIndex, input.end(), std::back_inserter(right));
  int inversionCount = CountInversions(left, inversionTracker);
  inversionCount += CountInversions(right, inversionTracker);
  inversionCount += MergeInversions(input, inversionTracker);
  return 0;
}

int main(int argc, char const *argv[])
{
  vector<int> mainVector;
  mainVector.push_back(1);
  mainVector.push_back(3);
  mainVector.push_back(5);
  mainVector.push_back(2);
  mainVector.push_back(4);
  mainVector.push_back(6);
  int inversionTracker = 0;
  CountInversions(mainVector, inversionTracker);
  return 0;
}
