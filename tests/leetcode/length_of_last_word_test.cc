#include <string>
#include "gtest/gtest.h"
#include "src/leetcode/strings/length_of_last_word.h"

TEST(LENGTH_LAST_WORD, LeetCode) {
  std::string input = "Hello World";
  ASSERT_EQ(5, lengthOfLastWord(input));
}


TEST(LENGTH_LAST_WORD, OneWord) {
  std::string input = "Hello";
  ASSERT_EQ(0, lengthOfLastWord(input));
}

TEST(LENGTH_LAST_WORD, FiveWords) {
  std::string input = "Hello World Rahul Wadhwani One";
  ASSERT_EQ(3, lengthOfLastWord(input));
}
