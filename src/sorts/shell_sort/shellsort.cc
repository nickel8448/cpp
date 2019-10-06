/**
 * shellsort.cc
 * Purpose: Function to sort an int array using shell sort algorithm
 * 
 * @author Rahul W
 * @version 0.1 10/06/19
 */

#include "shellsort.h"
#include "src/sorts/selection_sort/selectionsort.h"

void ShellSort::sort(int arr[], int size) {
    // Starting with a big gap. size / 2
    for (int gap = size / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {45,2345,435,2,56,1,5,56,900,53,90,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    ShellSort::sort(arr, size);
    SelectionSort::printArray(arr, size);
}