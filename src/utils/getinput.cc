/**
 * getinput.cc
 * Purpose: Get an input from the user
 * The program was a task in CS106L Lecture 6 - Templates
 *  
 * @author Rahul W
 * @version 0.1 11/09/19
 */

#include <sstream>
#include <iostream>
#include <string>

#include "getinput.h"

template <typename T>
T getTypeValue() {
  std::cout << "Enter a " << typeid(T).name() << " value: ";
  std::string line;
  char extra;
  T result;
  if(!getline(std::cin, line))
    throw std::domain_error("Could not get line");
  std::istringstream iss(line);
  if (iss >> result && !(iss >> extra)) return result;
  std::cout << "Invalid format." << std::endl;
  return 0;
}

int main() {
  double trialDouble = getTypeValue<double>();
  std::cout << "Printing double: " << trialDouble << std::endl;
  std::string trialString = getTypeValue<std::string>();
  std::cout << "Printing string: " << trialString << std::endl;
  int trialInt = getTypeValue<int>();
  std::cout << "Printing int: " << trialInt << std::endl;
}
