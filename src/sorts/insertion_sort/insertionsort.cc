/**
 * insertionsort.cc
 * Purpose: Functions to sort an int using insertion sort algo
 * 
 * @author Rahul W
 * @version 0.1 10/06/19
 */

#include "insertionsort.h"
#include "src/sorts/selection_sort/selectionsort.h"

using InsertionSort::sort;
using SelectionSort::printArray;

void InsertionSort::sort(int arr[], int size) {
    int currentElement;

    for (int i = 1; i < size; i++) {
        currentElement  = arr[i];
        int prevElement = i - 1;

        while (prevElement >= 0 && arr[prevElement] > currentElement) {
            // shifting the previous element to the right
            arr[prevElement + 1] = arr[prevElement];
            prevElement = prevElement - 1;
        }
        arr[prevElement + 1] = currentElement;
    }
}