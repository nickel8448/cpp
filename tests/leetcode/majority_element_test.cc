#include <vector>
#include "gtest/gtest.h"
#include "src/leetcode/majority_element.h"


TEST(MAJORITY_ELEMENT, easyElements) {
  std::vector<int> testVector {3, 2, 3};
  ASSERT_EQ(3, majorityElement(testVector));
}

TEST(MAJORITY_ELEMENT, twoAndOne) {
  std::vector<int> testVector {2,2,1,1,1,2,2};
  ASSERT_EQ(2, majorityElement(testVector));
}

TEST(MAJORITY_ELEMENT, eightSeven) {
  std::vector<int> testVector {8, 8, 7, 7, 7};
  ASSERT_EQ(7, majorityElement(testVector));
}

TEST(MAJORITY_ELEMENT, SIXANDFIVE) {
  std::vector<int> testVector {6, 5, 5};
  ASSERT_EQ(5, majorityElement(testVector));
}