#ifndef HEAPSORT
#define HEAPSORT

namespace Heapsort {

    void buildMaxHeap(int arr[], const int n);

    void maxHeapify(int arr[], const int i, const int n);

    void minHeapify(int arr[], const int i, const int n);

    void heapSort(int arr[], int n);

}

#endif