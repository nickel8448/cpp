#include <iostream>
#include <cstring>

template <typename T>
int compare(const T& v1, const T& v2) {
  if (v1 < v2) return -1;
  if (v2 > v1) return 1;
  return 0;
}

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
  std::cout << "M: " << M << std::endl;
  return strcmp(p1, p2);
}

int main(int argc, char** argv) {
  std::cout << compare<int>(1, 0) << std::endl;
  std::cout << compare("hi", "mom") << std::endl;
}
