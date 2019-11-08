#include <string>
#include "gtest/gtest.h"
#include "src/leetcode/add_strings.h"

TEST(ADD_STRINGS_TEST, SimpleThreeDigit) {
  std::string num1 = "123";
  std::string num2 = "123";
  ASSERT_EQ("246", addStrings(num1, num2));
}

TEST(ADD_STRINGS_TEST, CarryOverThreeDigit) {
  std::string num1 = "129";
  std::string num2 = "123";
  ASSERT_EQ("252", addStrings(num1, num2));
}

TEST(ADD_STRINGS_TEST, NumOneDigit) {
  std::string num1 = "1";
  std::string num2 = "123";
  ASSERT_EQ("124", addStrings(num1, num2));
}

TEST(ADD_STRINGS_TEST, NumTwoDigit) {
  std::string num1 = "123";
  std::string num2 = "1";
  ASSERT_EQ("124", addStrings(num1, num2));
}

TEST(ADD_STRINGS_TEST, TwoDigits) {
  std::string num1 = "1";
  std::string num2 = "1";
  ASSERT_EQ("2", addStrings(num1, num2));
}

TEST(ADD_STRINGS_TEST, BigNumbers) {
  std::string num1 = "4599";
  std::string num2 = "4522";
  ASSERT_EQ("9121", addStrings(num1, num2));
}

TEST(ADD_STRINGS_TEST, OneBlank) {
  std::string num1 = "4";
  std::string num2 = "0";
  ASSERT_EQ("4", addStrings(num1, num2));
}

TEST(ADD_STRINGS_TEST, Ten) {
  std::string num1 = "1";
  std::string num2 = "9";
  ASSERT_EQ("10", addStrings(num1, num2));
}
