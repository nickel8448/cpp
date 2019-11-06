#include <string>
#include "gtest/gtest.h"
#include "src/leetcode/isomorphic_strings.h"

TEST(ISOMORPHIC_STRING_TEST, ThreeCharacterTrue) {
  std::string s = "egg";
  std::string t = "add";
  ASSERT_EQ(true, isIsomorphic(s, t));
}

TEST(ISOMORPHIC_STRING_TEST, ThreeCharacterFalse) {
  std::string s = "foo";
  std::string t = "bar";
  ASSERT_EQ(false, isIsomorphic(s, t));
}

TEST(ISOMORPHIC_STRING_TEST, FiveCharacterTrue) {
  std::string s = "paper";
  std::string t = "title";
  ASSERT_EQ(true, isIsomorphic(s, t));
}

TEST(ISOMORPHIC_STRING_TEST, OneCharacterTrue) {
  std::string s = "p";
  std::string t = "t";
  ASSERT_EQ(true, isIsomorphic(s, t));
}

TEST(ISOMORPHIC_STRING_TEST, BlankTest) {
  std::string s = "";
  std::string t = "";
  ASSERT_EQ(true, isIsomorphic(s, t));
}

TEST(ISOMORPHIC_STRING_TEST, TwoCharacterFalse) {
  std::string s = "ab";
  std::string t = "aa";
  ASSERT_EQ(false, isIsomorphic(s, t));
}

TEST(ISOMORPHIC_STRING_TEST, EdgeCase) {
  std::string s = "abcdefghi";
  std::string t = "aaaaaaaaa";
  ASSERT_EQ(false, isIsomorphic(s, t));
}