#include <iostream>
using namespace std;

void Swap(int arr[], int left, int right) {
  if (arr[left] != arr[right]) {
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
  }
}

void BubbleSwap(int arr[], int arrSize) {
  bool swapped;
  int counter = 0;

  do {
    swapped = false;

    for (int i = 1; i < arrSize; i++) {
      if (arr[i - 1] > arr[i]) {
        Swap(arr, i, i - 1);
        swapped = true;
      }

      counter++;
    }
  } while (swapped != false);

  // output results
  for (int i = 0; i < arrSize - 1; i++) {
    cout << arr[i] << ", ";
  }

  cout << arr[arrSize - 1] << "\n";

  cout << "iteration count: " << counter;
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
  // BubbleSwap(testArr1, 10);

  // small array
  // BubbleSwap(testArr2, 5);

  // one element array
  // BubbleSwap(testArr3, 1);

  // long array with random values
  // BubbleSwap(testArr4, 21);

  // long array with a lot of duplicates
  // BubbleSwap(testArr4, 21);

  // reverse sorted array
  BubbleSwap(testArr6, 10);

  return 0;
}
