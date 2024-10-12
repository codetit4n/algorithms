// cyclic sort approach

#include "../../../utils/arrays.h"

int missing_number(int arr[], int size) {
  int index = 0;
  while (index < size) {
    // since array is from 0 to n
    int correct_index = arr[index];
    if (arr[index] < size && arr[index] != arr[correct_index]) {
      int temp = arr[index];
      arr[index] = arr[correct_index];
      arr[correct_index] = temp;
    } else {
      index++;
    }
  }

  // search for first missing number
  for (int i = 0; i < size; i++) {
    if (arr[i] != i) {
      return i;
    }
  }

  return size; // if no missing number
}

int main() {
  int arr[] = {3, 0, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Input array: ");
  display_arr_1D(arr, size);
  endl();

  int missing = missing_number(arr, size);
  printf("\nIndex of missing number: %d\n", missing);

  return 0;
}
