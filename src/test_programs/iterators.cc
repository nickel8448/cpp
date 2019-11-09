/**
 * iterators.cc
 * Purpose: Try out sample operations on iterators
 *  
 * @author Rahul W
 * @version 0.1 11/09/19
 */

#include <map>
#include <list>
#include <iostream>
#include <vector>


void testListIterator() {
  std::list<int> sampleIterator{5, 4, 3, 2, 1};

  // List provides a bidirectional iterator
  auto endItr = sampleIterator.end();
  --endItr;
  for (; endItr != sampleIterator.begin(); endItr--) {
    std::cout << *endItr << std::endl;
  }
}

// Function was written in Lecture 7. It is an example to show how templates
// can be used to write generic functions
template <typename InputIterator, typename T>
int countOccurences(InputIterator begin, InputIterator end, T val) {
  int count = 0;
  for (auto itr = begin; itr != end; ++itr) {
    if (*itr == val) ++count;
  }
  return count;
}


// Function template is a generic function which takes an iterator and also a
// predicate function to print the number of elements < 5 in a collection
// which can export a forward iterator
template <typename InputIterator, typename UnaryPredicator>
int countOccurencesUsingPredicator(InputIterator begin, InputIterator end,
    UnaryPredicator predicate) {
  std::cout << "Type id of predicate: " << typeid(predicate).name() << std::endl;
  int count = 0;
  for (auto itr = begin; itr != end; ++itr) {
    if(predicate(*itr)) ++count;
  }
  return count;
}


// Predicate function to be used with generic function
inline bool isLessThan5(int num) {
  return (num < 5);
}


// Function to utilize generic function
void useCountOccurenceFunction() {
  std::vector<int> testing {1, 2, 3, 4, 5, 6};
  std::cout << countOccurencesUsingPredicator(testing.begin(), testing.end(),
      isLessThan5) << std::endl;
}


int main() {
  useCountOccurenceFunction();
}
