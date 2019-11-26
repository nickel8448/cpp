/**
 * remove_short_words.cc
 * Purpose: Question 12 and 15 combined. Generate n random numbers and insert
 * them into an iterator using back_insert_iterator and write the contents
 * of the container to a file
 *  
 * @author Rahul W
 * @version 0.1 11/13/19
 */


#include <iterator>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>


int GenerateRandomNumber() {
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 eng(rd()); // seed the generator
  std::uniform_real_distribution<> distr_num(1, 1000); // define the range
  return distr_num(eng); 
}


void InsertRandomNumIntoVector(std::vector<int>& vec, const int num) {
  std::generate_n(std::back_insert_iterator<std::vector<int>>(vec), num,
      GenerateRandomNumber);
}


void PrintVector(const std::vector<int>& vec) {
  std::copy(vec.begin(), vec.end(),
      std::ostream_iterator<int>(std::cout, " "));
}


void WriteVectorToFile(const std::vector<int>& vec, std::string filename) {
  std::ofstream file_to_write(filename);
  std::copy(vec.begin(), vec.end(),
      std::ostream_iterator<int>(file_to_write, "\n"));
}


int main() {
  std::vector<int> vec;
  InsertRandomNumIntoVector(vec, 10);
  PrintVector(vec);
  WriteVectorToFile(vec, "vec_test.txt");
}
