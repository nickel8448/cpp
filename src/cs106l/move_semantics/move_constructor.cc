#include <iostream>
#include <string>
#include <vector>

class StrVector {

 public:
  StrVector() = default; 
  void AddElement(std::string elem);
  size_t size();

  // Defining the move constructor
  StrVector(StrVector&& obj);

  // Move assignment operator
  StrVector& operator=(StrVector&& obj);

 private:
  std::vector<std::string> elems;
};

void StrVector::AddElement(std::string elem) {
  elems.push_back(elem);
}

StrVector::StrVector(StrVector&& obj) {
  std::cout << "Calling move constructor" << std::endl;
  elems = std::move(obj.elems);
  obj.elems.clear();
}

StrVector& StrVector::operator=(StrVector&& obj) {
  std::cout << "Move assignment called" << std::endl;
  // Self-detection check
  if (&obj == this)
    return *this;

  // Release whatever this object is holding
  elems.clear();
  elems = std::move(obj.elems);
  obj.elems.clear();
  return *this;
}

size_t StrVector::size() {
  return elems.size();
}

int main() {
  StrVector a;
  a.AddElement("hi");
  a.AddElement("Hello");
  StrVector b;
  // Using the move assignment
  b = std::move(a);
  std::cout << "Size of StrVector a : " << a.size() << std::endl;
  std::cout << "Size of StrVector b : " << b.size() << std::endl;
}
