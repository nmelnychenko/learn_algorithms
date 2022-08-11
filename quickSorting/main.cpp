#include <gmock/gmock.h>

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

int * randomLongArray() {
  static int randomArr[10000];
  srand(time(NULL));

  for (int i = 0; i < 10000; i++) {
    int no = rand()%1000;
    randomArr[i] = no;
  }

  return randomArr;
}

int * quickSortedArray(int arr[], int n) {
  QuickSort(arr, n, 0, n);

  return arr;
}

int testArr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int testArr2[5] = {5, 4, 1, 2, 3};
int testArr3[1] = {7};
int testArr4[22] = {1, 1, 1, 1, 2, 3, 4, 5, 1, 1, 1, 2, 2,
  2, 3, 3, 4, 5, 3, 3, 3, 2};
int *testArr5 = randomLongArray();
int testArr6[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int testArr7[0] = {};

int *sortedArr1 = quickSortedArray(testArr1, 10);
int *sortedArr2 = quickSortedArray(testArr2, 5);
int *sortedArr3 = quickSortedArray(testArr3, 1);
int *sortedArr4 = quickSortedArray(testArr4, 22);
int *sortedArr5 = quickSortedArray(testArr5, 10000);
int *sortedArr6 = quickSortedArray(testArr6, 10);
int *sortedArr7 = quickSortedArray(testArr7, 0);

struct QuickSorting : public Test {};

// Short Sorted Array
TEST_F(QuickSorting, ShortSortedArray) { EXPECT_TRUE(std::is_sorted(sortedArr1, sortedArr1 + 10)); }

// Short Unsorted Array
TEST_F(QuickSorting, ShortUnsortedArray) { EXPECT_TRUE(std::is_sorted(sortedArr2, sortedArr2 + 5)); }

// Single element array
TEST_F(QuickSorting, SignleElementArray) { EXPECT_TRUE(std::is_sorted(sortedArr3, sortedArr3 + 1)); }

// Array with duplicates
TEST_F(QuickSorting, ArrayWithDuplicates) { EXPECT_TRUE(std::is_sorted(sortedArr4, sortedArr4 + 22)); }

// Very long array with random values
TEST_F(QuickSorting, LongRandomArray) { EXPECT_TRUE(std::is_sorted(sortedArr5, sortedArr5 + 10000)); }

// Reverse sorted array
TEST_F(QuickSorting, ReversedArray) { EXPECT_TRUE(std::is_sorted(sortedArr6, sortedArr6 + 10)); }

// Empty array
TEST_F(QuickSorting, EmptyArray) { EXPECT_TRUE(std::is_sorted(sortedArr7, sortedArr7)); }
