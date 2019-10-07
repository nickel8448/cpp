#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/sorts/insertion_sort/insertionsort.h"
#include "src/sorts/selection_sort/selectionsort.h"

TEST(Sort, InsertionSort) {
    int arr[] = {74, 9, 23, 53, 654, 23, 132, 64, 78, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sortedarr[] = {9,12,23,23,53,64,74,78,132,654};
    InsertionSort::sort(arr, size);
    SelectionSort::printArray(arr, size);
    ASSERT_THAT(sortedarr, testing::ContainerEq(arr));
}