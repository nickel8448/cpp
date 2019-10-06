#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/sorts/selection_sort/selectionsort.h"


TEST(Sort, SelectionSort) {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    SelectionSort::sort(arr, size);
    SelectionSort::printArray(arr, size);
    ASSERT_EQ(11, arr[0]);
}