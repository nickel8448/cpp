/**
 * vectortimecheck.cc
 * Purpose: Check how much time it takes to add elements to a vector after
 * memory has been reserved for the vector
 *  
 * @author Rahul W
 * @version 0.1 10/13/19
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <deque>


const int kNumElementsToAdd = 10000000; // 1 million
const int kStringLength = 500;


std::string generateLongString(int size) {
	std::string output;
	for (int i = 0; i < size; i++) {
		int numOfChar = rand() % 200;
		char character = numOfChar;
		output += character;
	}
	return output;
}


void addElementsToVector(std::vector<std::string>& elementsVector) {
	for (int i = 0; i < kNumElementsToAdd; i++) {
		elementsVector.push_back(generateLongString(kStringLength));
	}
}


void addElementsToDeque(std::deque<std::string>& elementsDeque) {
	for (int i = 0; i < kNumElementsToAdd; i++) {
		elementsDeque.push_front(generateLongString(kStringLength));
	}
}


void vectorCheckWithReserve() {
	std::vector<std::string> elements;
	elements.reserve(kNumElementsToAdd);  // Reserving the space
	clock_t startTime = clock();
	addElementsToVector(elements);
	double timeTaken = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	std::cout << "Time taken by vector with reserve: " << timeTaken << "s.\n";
}


void vectorCheckWithoutReserve() {
	std::vector<std::string> elements;
	clock_t startTime = clock();
	addElementsToVector(elements);	
	double timeTaken = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	std::cout << "Time taken by vector: " << timeTaken << "s.\n";
}


void dequeTimeCheck() {
	std::deque<std::string> elements;
	clock_t startTime = clock();
	addElementsToDeque(elements);
	double timeTaken = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	std::cout << "Time taken by deque: " << timeTaken << "s.\n";
}


int main() {
	vectorCheckWithReserve();
	vectorCheckWithoutReserve();
	dequeTimeCheck();
	return 0;
}