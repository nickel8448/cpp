/**
 * filestream.cc
 * Purpose: To learn and understand the filestream better in c++
 * 
 * @author Rahul W
 * @version 0.1 10/10/19
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include "src/sorts/sort_utils/sort_utils.h"

void writeToOneFileThroughMultipleStreams() {
    std::ofstream myStream("myFile.txt");
    std::ofstream anotherStream;
    for (int i = 0; i < 10; i++) {
        myStream << i << std::endl;
        if (i == 7){
            anotherStream.open("myFile.txt");
        }
    }
    for (int i = 10; i < 20; i++) {
        anotherStream << i << std::endl;
    }
}

std::ifstream OpenFile() {
    while(true) {
        // read filename
        std::cout << "Enter the file name to open: ";
        std::string fileName;
        getline(std::cin, fileName);

        std::ifstream fileStream(fileName);
        if (!fileStream.is_open()) {
            std::cout << "File could not be opened: ";
            std::cout << strerror(errno) << "\nPlease try again.\n";
            std::cout << std::endl;
        } else {
            return fileStream;
        }
    }
}
