// Swap approach:

// Iterate over the first half of the array and swap each element with its
// corresponding element from the end.

#include "../../utils/arrays.h"

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void reverseArray(int arr[], int n) {

  for (int i = 0; i < n / 2; i++) {
    swap(&arr[i], &arr[n - i - 1]);
  }
}

int main() {

  int arr[] = {2, 9, 1, 7, 4, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  display_arr_1D_with_msg("Array before: ", arr, size);

  reverseArray(arr, size);

  display_arr_1D_with_msg("Array after:  ", arr, size);

  return 0;
}
