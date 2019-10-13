/**
 * ostringstream.cc
 * Purpose: It is a practice file to learn about ostringstream and some of its
 * functions
 * 
 * @author Rahul W
 * @version 0.1 10/10/19
 */

#include <sstream>
#include <iostream>

int main() {

    std::ostringstream oss("Ito En Green Tea");

    // when something new is being added to the string it gets added at the
    // start and at the end
    oss << 16.9;

    // fpos - stream position class template
    // oss.tellp() tells the current position of the stream
    // streamoff - type to represent position offsent in a stream
    std::fpos pos = oss.tellp() + std::streamoff(3);

    oss.seekp(pos);

    oss << "Black";

    std::cout << oss.str() << std::endl;

    // The program will output - 16.9En Black Tea
}