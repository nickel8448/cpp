/**
 * remove_short_words.cc
 * Purpose: Problem 7 from Chapter 7. Write a function using remove_if to
 *  
 * @author Rahul W
 * @version 0.1 11/13/19
 */

#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <ostream>
#include <iostream>
#include <iterator>


std::string GenerateRandomWord() {
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 eng(rd()); // seed the generator
  std::uniform_real_distribution<> distr_word(97, 122); // define the range
  std::uniform_real_distribution<> distr_num_chars(1, 10);
  
  std::string word = "";
  for (int i = 0; i < distr_num_chars(eng); ++i) {
    char ch = distr_word(eng);
    std::string temp(1, ch);
    word.append(temp);
  }
  return word;
}


void GenerateNWords(std::vector<std::string>& container,
  const int& numWords) {
  for (int i = 0; i < numWords; ++i) {
    container.push_back(GenerateRandomWord());
  }
}


void RemoveStringWithLength(std::vector<std::string>& vec, const size_t& len) {
  auto removeFn = [len](std::string str)->bool {
    return str.length() <= len;
  };
  vec.erase(std::remove_if(vec.begin(), vec.end(), removeFn), vec.end());
}


int main() {
  std::vector<std::string> words;
  GenerateNWords(words, 50);
  std::copy(words.begin(), words.end(),
      std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;
  size_t len = 3;
  std::cout << "After words with length " << len << " removed" << std::endl;
  RemoveStringWithLength(words, len);
  std::copy(words.begin(), words.end(),
      std::ostream_iterator<std::string>(std::cout, " "));
}
