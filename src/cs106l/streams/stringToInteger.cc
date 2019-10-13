/**
 * stringToInteger.cc
 * Purpose: Learn about input stream while creating a function to convert a
 * string to integer
 *  
 * @author Rahul W
 * @version 0.1 10/10/19
 */

#include <sstream>
#include <iostream>

/*
 * Converts string into an integer
 * parameter: string represeting an int
 * return: integer written in the string
 * 
 * throws a domain error if string does not contain exactly an integer
 */
int stringToInteger(const std::string& str) {
    std::istringstream iss(str);
    int result;
    char remain;
    if (!(iss >> result) || iss >> remain) {
        throw std::domain_error("stringToInteger: error parsing \"" + str + "\"");
    }
    return result;
}

int getInteger(const std::string& prompt, const std::string& repromt) {
    while (true) {
        std::cout << prompt;
        std::string line;

        if (!getline(std::cin, line)) {
            throw std::domain_error("...");
        }

        // Adding the line to the string stream
        // Every loop creates a new one stream
        std::istringstream iss(line);
        int val;
        char remain;

        // If the string stream works and the value is transfeered to int
        // and there is no remaining data in the stream it can be closed
        if (iss >> val && !(iss >> remain)) {
            return val;
        }

        std::cout << repromt << std::endl;
    }
}

int main() {
    std::cout << getInteger("Enter integer: ", "Please enter an integer.")
        << std::endl;
}
