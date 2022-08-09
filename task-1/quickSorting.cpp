#include <iostream>
using namespace std;

void OutputArr(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << arr[i] << ", ";
  }

  cout << arr[n - 1];
}

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

int main() {
  int testArr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int testArr2[5] = {5, 4, 1, 2, 3};
  int testArr3[1] = {7};
  int testArr4[21] = {1, 3245, 567, 657, 87, 43, 12, 34, 567, 23,
   4512, 123, 12345, 3154, 567, 6478, 68, 798, 1234, 1, 0};
  int testArr5[22] = {1, 1, 1, 1, 2, 3, 4, 5, 1, 1, 1, 2, 2,
   2, 3, 3, 4, 5, 3, 3, 3, 2};
  int testArr6[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  // already sorted array
  // QuickSort(testArr1, 10, 0, 9);
  // OutputArr(testArr1, 10);

  // small array
  // QuickSort(testArr2, 5, 0, 4);
  // OutputArr(testArr2, 5);

  // one element array
  // QuickSort(testArr3, 1, 0, 0);
  // OutputArr(testArr3, 1);

  // long array with random values
  // QuickSort(testArr4, 21, 0, 20);
  // OutputArr(testArr4, 21);

  // long array with a lot of duplicates
  // QuickSort(testArr5, 22, 0, 21);
  // OutputArr(testArr5, 22);

  // reverse sorted array
  QuickSort(testArr6, 10, 0, 9);
  OutputArr(testArr6, 10);

  return 0;
}
