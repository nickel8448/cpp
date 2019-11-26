#include <iostream>
#include <algorithm>
#include <iterator>

#include "src/test_programs/stack_class.h"

int main() {
  // Stack<int> s;
  // s.push(100);
  // s.push(50);
  // s.push(20);
  // std::cout << s.pop() << std::endl;
  // std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
  
  // declaring a const pointer
  char* const myConstPointer = "Hello World";

  // declaring a pointer to const
  const char* myPointerToConst = "Hello World2";
  std::cout << &myPointerToConst << std::endl;

  // Changing the 
  myPointerToConst = "New World";
  std::cout << myPointerToConst << std::endl;
}