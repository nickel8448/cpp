/**
 * bubble_sort.cc
 * Purpose: Function to sort an int using bubble sort. The algorithm
 * is copied from the Intro to Algorithms book
 * 
 * @author Rahul W
 * @version 0.1 12/28/19
 */

#include <algorithm>
#include <cstddef>
#include <iostream>

void BubbleSort(int arr[], size_t size) {
  for (size_t i = 0; i < size - 1; ++i) {
    for (size_t j = size - 1; j > i; --j) {
      if (arr[j - 1] > arr[j]) {
        std::swap(arr[j], arr[j-1]);
      }
    }
  }
}

void PrintArray(const int arr[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << ", " << std::endl;
  }
}

int main() {
  int arr[] = {5, 2, 4, 6, 1, 3};
  size_t arrSize = sizeof(arr) / sizeof(arr[0]);
  BubbleSort(arr, arrSize);
  PrintArray(arr, arrSize);
}