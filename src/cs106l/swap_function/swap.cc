#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

class Patient {
public:
  Patient(std::string name, size_t num) : patientName(name),
    patientNumber(num) {}

private:
  std::string patientName;
  size_t patientNumber;
};

template <typename T>
void swapFn(T& obj1, T& obj2) {
  T obj3 = std::move(obj1);
  obj1 = std::move(obj2);
  obj2 = std::move(obj3);
}

int main() {
  std::vector<std::string> v1(10, "IT");
  std::vector<std::string> v2(10, "EN");
  swapFn(v1, v2);
  std::copy(v1.begin(), v1.end(),
      std::ostream_iterator<std::string>(std::cout, " "));

  Patient p1("Anna", 2);
  Patient p2("Avery", 3);
  swapFn(p1, p2);
}
