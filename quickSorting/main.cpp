#include <gmock/gmock.h>
#include <algorithm>    // std::sort
#include <iterator>

using namespace testing;

void Swap(int arr[], int left, int right) {
  if (arr[left] != arr[right]) {
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
  }
}

void QuickSort(int arr[], int n, int left, int right) {
  int i = left;
  int j = right;
  int middle = (left + right) / 2;
  int pivot = arr[middle];

  do {
    // traversing the array from the left, until find element higher then pivot
    while (arr[i] < pivot) { i++; }
    // traversing the array from the right, until find element lower then pivot
    while (arr[j] > pivot) { j--; }

    // if element higher than middle in the left side and lower than middle in the right -> do swap
    if (i <= j) {
      Swap(arr, i, j);
      i++;
      j--;
    }
  } while (i < j); // do until find middle element

  if (left < j) {
    // recursively do QuickSort for the arr where right border is `j` iterator, that lowered by 1 after Swap
    QuickSort(arr, n, left, j);
  }

  if (i < right) {
    // recursively do QuickSort for the arr where left border is `i` iterator, that increased by 1 after Swap
    QuickSort(arr, n, i, right);
  }
}

int * quickSortedArray(int arr[], int n) {
  QuickSort(arr, n, 0, n - 1);

  return arr;
}

// int testArr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// int testArr2[5] = {5, 4, 1, 2, 3};
// int testArr3[1] = {7};
// int testArr4[22] = {1, 1, 1, 1, 2, 3, 4, 5, 1, 1, 1, 2, 2,
//   2, 3, 3, 4, 5, 3, 3, 3, 2};
// int *testArr5 = randomLongArray();
// int testArr6[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
// int testArr7[0] = {};

// int *sortedArr1 = quickSortedArray(testArr1, 10);
// int *sortedArr2 = quickSortedArray(testArr2, 5);
// int *sortedArr3 = quickSortedArray(testArr3, 1);
// int *sortedArr4 = quickSortedArray(testArr4, 22);
// int *sortedArr5 = quickSortedArray(testArr5, 10);
// int *sortedArr6 = quickSortedArray(testArr6, 10);
// int *sortedArr7 = quickSortedArray(testArr7, 0);

struct QuickSorting : public Test {};

// Short Sorted Array
TEST_F(QuickSorting, ShortSortedArray) {
  int source[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int etalon[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *sorted = quickSortedArray(source, 10);

  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Short Unsorted Array
TEST_F(QuickSorting, ShortUnsortedArray) {
  int source[] = {5, 4, 1, 2, 3};
  int etalon[] = {1, 2, 3, 4, 5};
  int *sorted = quickSortedArray(source, 5);

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Single element array
TEST_F(QuickSorting, SignleElementArray) {
  int source[] = {5};
  int etalon[] = {5};
  int *sorted = quickSortedArray(source, 1);

  for (int i = 0; i < 1; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Array with duplicates
TEST_F(QuickSorting, ArrayWithDuplicates) {
  int source[22] = {1, 1, 1, 1, 2, 3, 4, 5, 1, 1, 1, 2, 2,
   2, 3, 3, 4, 5, 3, 3, 3, 2};
  int etalon[22] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3,
   3, 3, 3, 3, 3, 4, 4, 5, 5};
  int *sorted = quickSortedArray(source, 22);

  for (int i = 0; i < 22; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Very long array with random values
TEST_F(QuickSorting, LongRandomArray) {
  int source[10000];
  for (int i = 0; i < 10000; i++) {
    source[i] = rand()%100;
  }

  int etalon[10000];

  std::copy(std::begin(source), std::end(source), std::begin(etalon));
  std::sort(etalon, etalon + 10000);

  int *algo_sorted = quickSortedArray(source, 10000);

  for (int k = 0; k < 10000; k++) {
    EXPECT_EQ(algo_sorted[k], etalon[k]) << "Arrays sorted and etalon differ at index " << k;
  }
}

// Reverse sorted array
TEST_F(QuickSorting, ReversedArray) {
  int source[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int etalon[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *sorted = quickSortedArray(source, 10);

  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Empty array
TEST_F(QuickSorting, EmptyArray) {
  int source[] = {};
  int etalon[] = {};
  int *sorted = quickSortedArray(source, 0);
  int size = *(&sorted + 1) - sorted;

  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}
