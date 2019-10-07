/**
 * insertionsort.cc
 * Purpose: Functions to sort an int using insertion sort algo
 * 
 * @author Rahul W
 * @version 0.1 10/06/19
 */

#include "insertionsort.h"

using InsertionSort::sort;

void InsertionSort::sort(int arr[], const int size) {
    int currentElement;
    for (int i = 1; i < size; i++) {
        currentElement = arr[i];
        int previousElementIndex = i - 1;
        while(previousElementIndex >= 0 && arr[previousElementIndex] > currentElement) {
            // Shifting the larger element to the right
            arr[previousElementIndex + 1] = arr[previousElementIndex];
            previousElementIndex--;
        }
        arr[previousElementIndex + 1] = currentElement;
    }
}

