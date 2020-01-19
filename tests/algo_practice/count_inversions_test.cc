#include <vector>

#include "gtest/gtest.h"
#include "src/algo_practice/count_inversions.h"

using std::vector;

TEST(COUNT_INVERSION_TEST, SixNumbers) {
  vector<int> nums{1, 3, 5, 2, 4, 6};
  ASSERT_EQ(3, CountInversions(nums));
}