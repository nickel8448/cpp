#include "gtest/gtest.h"
#include "src/leetcode/split_balanced_string.h"

TEST(SPLITSTRING, RLRRLLRLRL) {
  std::string input = "RLRRLLRLRL";
  ASSERT_EQ(4, balancedStringSplit(input));
}

TEST(SPLITSTRING, RLLLLRRRLR) {
  std::string input = "RLLLLRRRLR";
  ASSERT_EQ(3, balancedStringSplit(input));
}

TEST(SPLITSTRING, LLLLRRRR) {
  std::string input = "LLLLRRRR";
  ASSERT_EQ(1, balancedStringSplit(input));
}

TEST(SPLITSTRING, LR) {
  std::string input = "LR";
  ASSERT_EQ(1, balancedStringSplit(input));
}

TEST(SPLITSTRING, LONE) {
  std::string input = "L";
  ASSERT_EQ(0, balancedStringSplit(input));
}

TEST(SPLITSTRING, BLANK) {
  std::string input = "";
  ASSERT_EQ(0, balancedStringSplit(input));
}

TEST(SPLITSTRING, LRLRLRLR) {
  std::string input = "LRLRLRLR";
  ASSERT_EQ(4, balancedStringSplit(input));
}
