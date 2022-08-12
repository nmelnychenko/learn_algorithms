#include <gmock/gmock.h>

using namespace testing;

void Swap(int arr[], int left, int right) {
  if (arr[left] != arr[right]) {
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
  }
}

int * BubbleSwap(int arr[], int arrSize) {
  bool swapped;

  do {
    swapped = false;

    for (int i = 1; i < arrSize; i++) {
      if (arr[i - 1] > arr[i]) {
        Swap(arr, i, i - 1);
        swapped = true;
      }
    }
  } while (swapped != false);

  return arr;
}




struct BubbleSorting : public Test {};

// Short Sorted Array
TEST_F(BubbleSorting, ShortSortedArray) {
  int source[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int etalon[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *sorted = BubbleSwap(source, 10);

  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Short Unsorted Array
TEST_F(BubbleSorting, ShortUnsortedArray) {
  int source[] = {5, 4, 1, 2, 3};
  int etalon[] = {1, 2, 3, 4, 5};
  int *sorted = BubbleSwap(source, 5);

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Single element array
TEST_F(BubbleSorting, SignleElementArray) {
  int source[] = {5};
  int etalon[] = {5};
  int *sorted = BubbleSwap(source, 1);

  for (int i = 0; i < 1; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Array with duplicates
TEST_F(BubbleSorting, ArrayWithDuplicates) {
  int source[22] = {1, 1, 1, 1, 2, 3, 4, 5, 1, 1, 1, 2, 2,
   2, 3, 3, 4, 5, 3, 3, 3, 2};
  int etalon[22] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3,
   3, 3, 3, 3, 3, 4, 4, 5, 5};
  int *sorted = BubbleSwap(source, 22);

  for (int i = 0; i < 22; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Very long array with random values
TEST_F(BubbleSorting, LongRandomArray) {
  int source[100000];
  for (int i = 0; i < 100000; i++) {
    source[i] = rand()%100;
  }

  int etalon[100000];

  std::copy(std::begin(source), std::end(source), std::begin(etalon));
  std::sort(etalon, etalon + 100000);

  int *algo_sorted = BubbleSwap(source, 100000);

  for (int k = 0; k < 100000; k++) {
    EXPECT_EQ(algo_sorted[k], etalon[k]) << "Arrays sorted and etalon differ at index " << k;
  }
}

// Reverse sorted array
TEST_F(BubbleSorting, ReversedArray) {
  int source[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int etalon[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *sorted = BubbleSwap(source, 10);

  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}

// Empty array
TEST_F(BubbleSorting, EmptyArray) {
  int source[] = {};
  int etalon[] = {};
  int *sorted = BubbleSwap(source, 0);
  int size = *(&sorted + 1) - sorted;

  for (int i = 0; i < size; ++i) {
    EXPECT_EQ(sorted[i], etalon[i]) << "Arrays sorted and etalon differ at index " << i;
  }
}
