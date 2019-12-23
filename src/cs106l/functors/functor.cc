#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <random>
#include <iterator>

using std::vector;

// Functor defined
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


void UsePlusFunctional(vector<int>& intVector, const int& toAdd) {
  std::transform(intVector.begin(), intVector.end(), intVector.begin(),
      std::bind(std::plus<int>(), std::placeholders::_1, toAdd));
}

void TestPlusFunctional() {
  vector<int> testVector(10, 100);
  std::cout << "Vector before addition\n";
  std::copy(testVector.begin(), testVector.end(), 
      std::ostream_iterator<int>(std::cout, " "));
  UsePlusFunctional(testVector, 20);
  std::cout << "Vector after addition\n";
  std::copy(testVector.begin(), testVector.end(), 
      std::ostream_iterator<int>(std::cout, " "));
}

// Function to understand how std::bind words on a vector of string
void UseBinding(const std::vector<std::string>& words) {
  auto ShorterThanFnBinded = std::bind(ShorterThanFn,
      std::placeholders::_1, 4);
  int numElementsFromBinding = std::count_if(words.begin(), words.end(),
      ShorterThanFnBinded);
  std::cout << "Output from binded function: " << numElementsFromBinding
            << std::endl;
}

<<<<<<< HEAD
// Function to understand how to use lambda on a vector of string
void UseLambda(const std::vector<std::string>& words, const size_t& length) {
  auto lengthFn = [length](const std::string& str) {
    return str.length() < length;
  };
  int numElements = std::count_if(words.begin(), words.end(), lengthFn);
  std::cout << "Output from lambda function: " << numElements << std::endl;
}



=======
// Class un is a function object which is a derived class of a unary function
template <typename UnaryPredicate>
class un : public std::unary_function<typename UnaryPredicate::argument_type, bool> {
  public:
    explicit un(const UnaryPredicate& pred) : p(pred) {}
  
    bool operator()(const typename UnaryPredicate::argument_type& param) const {
      return !p(param);
    }
  private:
    UnaryPredicate p;
};

template <typename UnaryPredicate>
un<UnaryPredicate> not1(const UnaryPredicate& pred) {
  return un<UnaryPredicate>(pred);
}
>>>>>>> 998bdfd989209e69acf28d754d8bb077626e43ad

int main() {
  std::vector<std::string> words;
  words.push_back("hello");
  words.push_back("world");
  words.push_back("hel");
  words.push_back("helo");
  words.push_back("hlo");
  words.push_back("hllo");
  words.push_back("helo");

  std::cout << "number of elements in the vector: " << words.size() << "\n";
  int numElements = 0;
  numElements = std::count_if(words.begin(), words.end(), ShorterThan(4));
  std::cout << "Output from functor: " << numElements << std::endl;

  std::cout << "Trying binding\n";
  UseBinding(words);

  std::cout << "Using a lambda\n";
  UseLambda(words, 4);
  std::cout << std::endl;
  
  TestPlusFunctional();
}
