#include <iostream>
#include "sort_utils.h"

void SortUtil::swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SortUtil::printArray(const int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}