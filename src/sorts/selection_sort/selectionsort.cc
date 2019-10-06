#include <iostream>
#include "selectionsort.h"

void SelectionSort::sort(int arr[], int size) {

    int min_index;

    for (int i = 0; i < size - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        SelectionSort::swap(&arr[min_index], &arr[i]);
    }
}

void SelectionSort::swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectionSort::printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
}
