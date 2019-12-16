#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

class ShorterThan {
public:
  explicit ShorterThan(size_t maxLength) : length(maxLength) {}
  bool operator() (const std::string& str) const {
    return str.length() < length;
  }

private:
  size_t length;
};

bool ShorterThanFn(const std::string& str, size_t length) {
  return str.length() < length;
}

void UseBinding(const std::vector<std::string>& words) {
  auto ShorterThanFnBinded = std::bind(ShorterThanFn,
      std::placeholders::_1, 4);
  int numElementsFromBinding = std::count_if(words.begin(), words.end(),
      ShorterThanFnBinded);
  std::cout << "Output from binded function: " << numElementsFromBinding
            << std::endl;
}

int main() {
  std::vector<std::string> words;
  words.push_back("hello");
  words.push_back("world");
  words.push_back("hel");
  words.push_back("helo");
  words.push_back("hlo");
  words.push_back("hllo");
  words.push_back("helo");
  int numElements = 0;
  numElements = std::count_if(words.begin(), words.end(), ShorterThan(4));
  std::cout << numElements << std::endl;

  std::cout << "Trying binding\n";
  UseBinding(words);
}
