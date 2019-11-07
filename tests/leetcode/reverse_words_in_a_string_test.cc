#include <string>
#include "gtest/gtest.h"
#include "src/leetcode/reverse_words_in_a_string.h"

TEST(REVERSEWORDS, LeetCodeSample) {
  std::string input = "Let's take LeetCode contest";
  std::string expected = "s'teL ekat edoCteeL tsetnoc";
  ASSERT_EQ(expected, reverseWords(input));
}

TEST(REVERSEWORDS, SingleLetter) {
  std::string input = "a";
  std::string expected = "a";
  ASSERT_EQ(expected, reverseWords(input));
}

TEST(REVERSEWORDS, TwoLetter) {
  std::string input = "AB";
  std::string expected = "BA";
  ASSERT_EQ(expected, reverseWords(input));
}

TEST(REVERSEWORDS, TwoLowercaseLetter) {
  std::string input = "aa";
  std::string expected = "aa";
  ASSERT_EQ(expected, reverseWords(input));
}
