/**
 * stl_palindrome.cc
 * Purpose: To check how to use stl algorithms to do check if a string a
 * palindrome string
 *  
 * @author Rahul W
 * @version 0.1 11/12/19
 */

#include <cctype>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <iostream>

bool IsNotAlphaOrSpace(char ch) {
  return !std::isalpha(ch) || std::isspace(ch);
}


bool IsPalindrome(std::string input) {
  // remove_if returns the past-the-end iterator for the new range of values
  // erase function erases the values which are past-the-end to free memory
  input.erase(std::remove_if(input.begin(), input.end(), IsNotAlphaOrSpace),
      input.end());

  auto ToUpperFun = [](unsigned char c) -> unsigned char {
    return std::toupper(c);
  };
  std::transform(input.begin(), input.end(), input.begin(), ToUpperFun);

  std::stringstream tokenizer(input);
  std::vector<char> tokens;

  // as a char comes in the input stream which is made up of tokenizer, the
  // element should be added to the beginning of the tokens vector
  tokens.insert(tokens.begin(),
      input.begin(),
      input.end());

  /* auto rItr = tokens.begin(); */
  /* for (rItr; rItr != tokens.end(); ++rItr) { */
  /*   std::cout << *rItr << std::endl; */
  /* } */

  std::copy(std::rbegin(tokens), std::rend(tokens),
      std::ostream_iterator<char>(std::cout, " "));

  return std::equal(tokens.begin(), tokens.begin() + tokens.size()/2,
      tokens.rbegin());
}

int main() {
  std::string str1 = "hello world";
  std::string str2 = "race,          car";
  std::cout << IsPalindrome(str1) << "\n";
  std::cout << IsPalindrome(str2) << "\n";
}
