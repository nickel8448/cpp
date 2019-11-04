/**
 * mergesort.cc
 * Purpose: Functions to implement mergesort
 * 
 * @author Rahul W
 * @version 0.1 10/21/19
 */
#include <iostream>
#include "src/sorts/sort_utils/sort_utils.h"

// Function which merges the two halves together
void merge(int *array, const int low, const int mid, const int high) {
  // create left and right array
  int leftArrayLength = mid - low + 1;
  int rightArrayLength = high - mid;
  int leftArray[leftArrayLength];
  int rightArray[rightArrayLength];

  // copy data to temp arrays
  for (int i = 0; i < leftArrayLength; i++)
    leftArray[i] = array[low + i];
  for (int j = 0; j < rightArrayLength; j++)
    rightArray[j] = array[mid + 1 + j];
  
  int i = 0;
  int j = 0;
  int k = low;

  // sorting both the sides of the array
  while (i < leftArrayLength && j < rightArrayLength) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i = i + 1;
    } else {
      array[k] = rightArray[j];
      j = j + 1;
    }
    k++;
  }

  // add the remaining in left and right array to the main array
  while(i < leftArrayLength) {
    array[k] = leftArray[i];
    i++;
    k++;
  }
  while(j < rightArrayLength) {
    array[k] = rightArray[j];
    j++;
    k++;
  }
}

// The function which splits the array in two parts
void mergeSort(int *array, const int low, const int high) {
  int mid;
  if (low < high) {
    mid = low + (high-low) / 2;
    // Split the data in two halves
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    // Merge them together
    merge(array, low, mid, high);
  }
}

int main() {
  int arr[] = {45, 123, 432, 341, 56, 123, 2, 0};
  int size = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Given array: " << std::endl;
  SortUtil::printArray(arr, size);
  mergeSort(arr, 0, size - 1);
  std::cout << "Sorted array: " << std::endl;
  SortUtil::printArray(arr, size);

}