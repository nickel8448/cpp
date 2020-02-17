#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int> CreateVector() {
  std::vector<int> temp{1, 2, 3, 4, 5};
  return temp;
}


int main() {
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2;

  std::cout << "Before moving" << std::endl;
  std::cout << "Size of v1: " << v1.size() << std::endl;
  std::cout << "Size of v2: " << v2.size() << std::endl;
  std::cout << "Vector size " << v1.size() << std::endl;


  // Moving v1 to v2
  v2 = std::move(v1);

  std::cout << "After moving" << std::endl;
  std::cout << "Size of v1: " << v1.size() << std::endl;
  std::cout << "Size of v2: " << v2.size() << std::endl;

  std::cout << "Creating a vector from a function and storing it in main";
  std::cout << std::endl;
  std::vector<int> v3;
  v3 = CreateVector();
  std::cout << "Size of new vector" << std::endl;
  std::cout << v3.size() << std::endl;
}
