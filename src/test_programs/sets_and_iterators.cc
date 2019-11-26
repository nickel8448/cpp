/**
 * sets_and_iterators.cc
 * Purpose: To test what kind of values are returned when a set is used with an
 * iterator
 *  
 * @author Rahul W
 * @version 0.1 10/15/19
 */

#include <set>
#include <iostream>
#include <vector>
#include <stack>


/**
 * @brief  To test iterators on sets. The iterators are created using lower and
 * upper bound
 * @note  Page 131 of the cs106l course reader 
 * @retval None
 */
void setWithChars() {
  std::set<char> charSet;
  for(int i = 65; i <= 90; i++) {
    charSet.insert(char(i));
  }
  std::set<char>::iterator start = charSet.lower_bound('F');
  std::set<char>::iterator stop = charSet.upper_bound('P');
  for (; start != stop; start++) {
    std::cout << *start << std::endl;
  }
}


/**
 * @brief  To create a set using a set constructor which accepts an iterator
 * @note   
 * @retval None
 */
void vectorToSetUsingIterator() {
  std::vector<int> intVector;
  for (int i = 0; i < 10; i++) {
    intVector.push_back(rand() % 10);
  }
  for (auto itr = intVector.begin(); itr != intVector.end(); itr++) {
    std::cout << *itr << std::endl;
  }

  // putting the vector to a set using the set constructor
  std::cout << "Printing the set: " << std::endl;
  std::set<int> intSet(intVector.begin(), intVector.end());
  for (auto itr = intSet.begin(); itr != intSet.end(); itr++) {
    std::cout << *itr << std::endl;
  }
}


void intSetExperiment() {
  std::set<int> integerSet;
  for (int i = 0; i < 10; i++) {
    integerSet.insert(i * 100);
  }

  for (auto itr = integerSet.begin(); itr != integerSet.end(); itr++) {
    std::cout << *itr << std::endl;
  }
}


int main() {
  vectorToSetUsingIterator();
  std::stack<int, std::vector<int>> vectorStack;
}