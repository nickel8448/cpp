/**
 * karatsuba.cc
 * Purpose: Implementing the karatsuba algorithm
 *
 * @author Rahul W
 * @version 0.1 12/29/19
 *
 */

#include <cmath>
#include <string>
#include <iostream>

int Karatsuba(const int a, const int b) {
  int lengthA = std::to_string(a).length();
  int lengthB = std::to_string(b).length();
  if (lengthA == 1 && lengthB == 1) {
    return a * b;
  }
  int firstHalfA = a / (static_cast<int>(std::pow(10, lengthA / 2)));
  int secondHalfA = a % (static_cast<int>(std::pow(10, lengthA / 2)));
  int firstHalfB = b / (static_cast<int>(std::pow(10, lengthB / 2)));
  int secondHalfB = b % (static_cast<int>(std::pow(10, lengthB / 2)));
  int p = firstHalfA + secondHalfA;
  int q = firstHalfB + secondHalfB;

  int ac = Karatsuba(firstHalfA, firstHalfB);
  int bd = Karatsuba(secondHalfA, secondHalfB);
  int pq = Karatsuba(p, q);

  int adbc = pq - ac - bd;

  return static_cast<int>(std::pow(10, lengthA)) * ac +
         static_cast<int>(std::pow(10, lengthA / 2)) * adbc + bd;
}

int main() {
  std::cout << Karatsuba(20, 40) << std::endl;
}