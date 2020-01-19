/**
 * dutch_flag.cc
 * Purpose: This program is a solution to the dutch problem using quick sort.
 * The array is partioned in 3 ways
 * 
 * @author Rahul W
 * @version 0.1 01/19/20
 */


#include <vector>
#include <utility>
#include <iterator>
#include <iostream>

using std::vector;
using std::pair;

pair<int, int> Partition(vector<int> &nums, int low, int high) {
  int pivotElement = nums.at(low), lt = low, gt = high, i = low + 1;
  while (i <= gt) {
    // case of left parition
    if(pivotElement > nums.at(i)) {
      std::swap(nums.at(i), nums.at(lt));
      ++lt;
    } // below if the case of right partition
    else if (pivotElement < nums.at(i)) {
      std::swap(nums.at(i), nums.at(gt));
      --gt;
    }
    ++i;
  }
  return std::make_pair(lt, gt);
}

void DutchFlag(vector<int> &nums, int low, int high) {
  pair<int, int> p = std::make_pair(0, 0);
  if(low < high) {
    p = Partition(nums, low, high);
    DutchFlag(nums, low, p.first);
    DutchFlag(nums, p.second, high);
  }
}

int main() {
  std::vector<int> nums = {0, 1, 2, 2, 2, 1, 0, 0};
  DutchFlag(nums, 0, nums.size() - 1);
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
}