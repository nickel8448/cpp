#include <vector>
#include "gtest/gtest.h"
#include "src/leetcode/remove_duplicates.h"

TEST(REMOVEDUPLIACTES, BasicElements) {
  std::vector<int> testVector {1, 1, 2, 3, 4};
  ASSERT_EQ(4, removeDuplicates(testVector));
}

TEST(REMOVEDUPLIACTES, MultipleElements) {
  std::vector<int> nums {1, 1, 2, 2, 2, 3, 3, 3, 4};
  ASSERT_EQ(4, removeDuplicates(nums));
}

TEST(REMOVEDUPLIACTES, DuplicateAtTheEnd) {
  std::vector<int> nums {1, 4, 4, 4, 4, 4};
  ASSERT_EQ(2, removeDuplicates(nums));
}

TEST(REMOVEDUPLIACTES, DuplicateAtFront) {
  std::vector<int> nums {4, 4, 4, 4, 4, 9};
  ASSERT_EQ(2, removeDuplicates(nums));
}

TEST(REMOVEDUPLIACTES, OnlyDuplicates) {
  std::vector<int> nums {4};
  ASSERT_EQ(1, removeDuplicates(nums));
}

TEST(REMOVEDUPLIACTES, BigVector) {
  std::vector<int> nums {0, 1, 2, 2, 2, 2, 2, 3, 3, 4, 4, 5, 9};
  for (auto itr = nums.begin(); itr != nums.end(); itr++) {
    printf("%d, ", *itr);
  }
  printf("\n");
  ASSERT_EQ(7, removeDuplicates(nums));
}