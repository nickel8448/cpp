/**
 * iterator_adaptors.cc
 * Purpose: Try out sample operations on iterators
 *  
 * @author Rahul W
 * @version 0.1 11/09/19
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>


void addIntValuesToIterator(std::vector<int>& vec) {
  std::back_insert_iterator<std::vector<int>> vecItr(vec);
  for (int i = 0; i < 30; i++) { 
    *vecItr = i % 10;
    vecItr++;
  }
}


void printVectorValuesUsingIteratorAdaptor(const std::vector<int>& vec) {
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}


int main() {
  std::vector<int> myVec;
  addIntValuesToIterator(myVec);
  printVectorValuesUsingIteratorAdaptor(myVec);
  std::cout << std::endl;
  std::cout << "Vector size before removal: " << myVec.size() << std::endl;
  std::cout << "Removing all 3s" << std::endl;
  std::remove(myVec.begin(), myVec.end(), 3);
  std::cout << "Vector size after removal: " << myVec.size() << std::endl;
    printVectorValuesUsingIteratorAdaptor(myVec);
  /* std::copy(std::remove) */
}
