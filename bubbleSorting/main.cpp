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

int * randomLongArray() {
  static int randomArr[10000];
  srand(time(NULL));

  for (int i = 0; i < 10000; i++) {
    int no = rand()%1000;
    randomArr[i] = no;
  }

  return randomArr;
}

int testArr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int testArr2[5] = {5, 4, 1, 2, 3};
int testArr3[1] = {7};
int testArr4[22] = {1, 1, 1, 1, 2, 3, 4, 5, 1, 1, 1, 2, 2,
  2, 3, 3, 4, 5, 3, 3, 3, 2};
int *testArr5 = randomLongArray();
int testArr6[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int testArr7[0] = {};

int *sortedArr1 = BubbleSwap(testArr1, 10);
int *sortedArr2 = BubbleSwap(testArr2, 5);
int *sortedArr3 = BubbleSwap(testArr3, 1);
int *sortedArr4 = BubbleSwap(testArr4, 22);
int *sortedArr5 = BubbleSwap(testArr5, 10000);
int *sortedArr6 = BubbleSwap(testArr6, 10);
int *sortedArr7 = BubbleSwap(testArr7, 0);

struct BubbleSorting : public Test {};

// Short Sorted Array
TEST_F(BubbleSorting, ShortSortedArray) { EXPECT_TRUE(std::is_sorted(sortedArr1, sortedArr1 + 10)); }

// Short Unsorted Array
TEST_F(BubbleSorting, ShortUnsortedArray) { EXPECT_TRUE(std::is_sorted(sortedArr2, sortedArr2 + 5)); }

// Single element array
TEST_F(BubbleSorting, SignleElementArray) { EXPECT_TRUE(std::is_sorted(sortedArr3, sortedArr3 + 1)); }

// Array with duplicates
TEST_F(BubbleSorting, ArrayWithDuplicates) { EXPECT_TRUE(std::is_sorted(sortedArr4, sortedArr4 + 22)); }

// Very long array with random values
TEST_F(BubbleSorting, LongRandomArray) { EXPECT_TRUE(std::is_sorted(sortedArr5, sortedArr5 + 10000)); }

// Reverse sorted array
TEST_F(BubbleSorting, ReversedArray) { EXPECT_TRUE(std::is_sorted(sortedArr6, sortedArr6 + 10)); }

// Empty array
TEST_F(BubbleSorting, EmptyArray) { EXPECT_TRUE(std::is_sorted(sortedArr7, sortedArr7)); }
