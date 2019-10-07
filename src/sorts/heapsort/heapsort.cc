#include <iostream>
#include "heapsort.h"
#include "src/sorts/sort_utils/sort_utils.h"

using Heapsort::maxHeapify;
using SortUtil::printArray;

// i is the root node provided
void Heapsort::maxHeapify(int arr[], const int i, const int n) {
    int largest = i;
    int leftNode = (2 * i ) + 1; // 2 * k + 1
    int rightNode = (2 * i) + 2; // 2 * k + 2

    if (leftNode < n && arr[leftNode] > arr[largest])
        largest = leftNode;
    
    if (rightNode < n && arr[rightNode] > arr[largest])
        largest = rightNode;
    
    if (arr[largest] > arr[i]) {
        SortUtil::swap(&arr[largest], &arr[i]);

        // Recursively heapify the affected sub-tree
        Heapsort::maxHeapify(arr, largest, n);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Unsorted array: " << std::endl;
    ::printArray(arr, size);
    for (int i = size / 2 - 1; i >= 0; i--) {
        ::maxHeapify(arr, i, size);
    }
    std::cout << "Max Heapified: " << std::endl;
    ::printArray(arr, size);
}