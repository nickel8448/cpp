/**
 * open_file_buf_iterator.cc
 * Purpose: Solution to question 14 from Chapter 7. Open a file and print its
 * contents to cout using a combination of copy, istreambuf_iterator and
 * ostreambuf_iterator
 *  
 * @author Rahul W
 * @version 0.1 11/15/19
 */


#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
#include <iterator>


int main() {
  std::string filename = "test.txt";
  std::ifstream test_file(filename);
  std::copy(std::istreambuf_iterator<char>(test_file),
      std::istreambuf_iterator<char>(),
      std::ostreambuf_iterator<char>(std::cout));
}
