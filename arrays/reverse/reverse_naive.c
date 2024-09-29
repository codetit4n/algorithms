// Naive approach:

// Create a temporary array and copy elements in the required order.

#include "../../utils/arrays.h"

void reverseArray(int arr[], int n) {

  int tmp[n];

  for (int i = 0; i < n; i++) {
    tmp[i] = arr[n - i - 1];
  }

  for (int i = 0; i < n; i++) {
    arr[i] = tmp[i];
  }
}

int main() {

  int arr[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  display_arr_1D_with_msg("Array before: ", arr, size);

  reverseArray(arr, size);

  display_arr_1D_with_msg("Array after:  ", arr, size);

  return 0;
}
