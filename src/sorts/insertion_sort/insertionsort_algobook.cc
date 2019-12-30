/**
 * insertionsort_algobook.cc
 * Purpose: Functions to sort an int using insertion sort algo. The algorithm
 * is copied from the Intro to Algorithms book
 * 
 * @author Rahul W
 * @version 0.1 12/28/19
 */

 #include <cstddef>
 #include <iostream>

void InsertionSort(int arr[], const size_t size) {
  for (size_t i = 1; i < size; i++) {
    int currentElement = arr[i];
    size_t previousElementIndex = i - 1;
    while (previousElementIndex >= 0 && arr[previousElementIndex] > currentElement) {
      arr[previousElementIndex + 1] = arr[previousElementIndex];
      --previousElementIndex;
    }
    arr[previousElementIndex + 1] = currentElement;
  }
}

void InsertionSortInDecrementing(int arr[], const size_t size) {
  for (size_t i = 1; i < size; ++i) {
    int currentElement = arr[i];
    int previousElementIndex = i - 1;
    while (previousElementIndex >= 0 && currentElement > arr[previousElementIndex]) {
      arr[previousElementIndex + 1] = arr[previousElementIndex];
      --previousElementIndex;
    }
    arr[previousElementIndex + 1] = currentElement;
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
  InsertionSortInDecrementing(arr, arrSize);
  PrintArray(arr, arrSize);
}
