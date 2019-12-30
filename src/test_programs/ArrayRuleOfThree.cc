#include <algorithm>

class Array {
public:
  // Constructor 
  Array(int s, int* v);

  // Destructor
  ~Array();

private:
  int size;
  int* vals;
};

Array::~Array() {
  delete[] vals;
  vals = nullptr;
}

Array::Array(int s, int* v) {
  this->size = s;
  this->vals = new int[size];
  std::copy(v, v + size, vals);
}

int main() {
  int vals[4] = {11, 22, 33, 44};
  Array a1(4, vals);

  // There is no copy constructor created
  Array a2(a1);

  return 0;
}
