/**
 * bubble_sort.cc
 * Purpose: Function to sort an int using bubble sort. The algorithm
 * is copied from the Intro to Algorithms book
 *
 * @author Rahul W
 * @version 0.1 12/28/19
 */

#include <cstddef>
#include <iostream>

void PrintArray(const std::string context, const int arr[], const size_t size) {
  std::cout << "Printing for: " << context;
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;
}

void Merge(int arr[], int startLength, int midLength, int endLength) {
  int leftArraySize = midLength - startLength + 1;
  int rightArraySize = endLength - midLength;
  int leftArray[leftArraySize];
  int rightArray[rightArraySize];

  // Put data in the new arrays
  for (int i = 0; i < leftArraySize; ++i) leftArray[i] = arr[i + startLength];
  for (int i = 0; i < rightArraySize; ++i) {
    rightArray[i] = arr[i + midLength + 1];
  }

  PrintArray("Left array: ", leftArray, leftArraySize);
  PrintArray("Right array: ", rightArray, rightArraySize);

  // Sort the arrays
  int leftArrayCounter = 0, rightArrayCounter = 0, arrayCounter = startLength;
  while (leftArrayCounter < leftArraySize &&
         rightArrayCounter < rightArraySize) {
    if (leftArray[leftArrayCounter] < rightArray[rightArrayCounter]) {
      arr[arrayCounter] = leftArray[leftArrayCounter];
      ++leftArrayCounter;
    } else {
      arr[arrayCounter] = rightArray[rightArrayCounter];
      ++rightArrayCounter;
    }
    ++arrayCounter;
  }

  while (leftArrayCounter < leftArraySize) {
    arr[arrayCounter] = leftArray[leftArrayCounter];
    ++leftArrayCounter;
    ++arrayCounter;
  }
  while (rightArrayCounter < rightArraySize) {
    arr[arrayCounter] = rightArray[rightArrayCounter];
    ++rightArrayCounter;
    ++arrayCounter;
  }
}

void MergeSort(int arr[], int startLength, int endLength) {
  if (startLength < endLength) {
    int midLength = (startLength + endLength) / 2;
    MergeSort(arr, startLength, midLength);
    MergeSort(arr, midLength + 1, endLength);
    Merge(arr, startLength, midLength, endLength);
  }
}

int main() {
  int arr[] = {5, 2, 4, 6, 1, 3, 7, 8, 9, 0};
  size_t arrSize = sizeof(arr) / sizeof(arr[0]);
  PrintArray("Before sorting: ", arr, arrSize);
  MergeSort(arr, 0, arrSize - 1);
  PrintArray("After sorting: ", arr, arrSize);
}
