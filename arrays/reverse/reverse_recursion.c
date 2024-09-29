// Recursion approach:

// Recursively swap the first and last elements until the entire array is
// reversed.

#include "../../utils/arrays.h"

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void reverseArray(int arr[], int l, int r) {

  // Base case
  if (l >= r) {
    return;
  }

  // Swap elements at the ends
  swap(&arr[l], &arr[r]);

  // Recursive call
  reverseArray(arr, l + 1, r - 1);
}

int main() {

  int arr[] = {2, 9, 1, 7, 4, 8, 5, 0};

  int size = sizeof(arr) / sizeof(arr[0]);

  display_arr_1D_with_msg("Array before: ", arr, size);

  reverseArray(arr, 0, size - 1);

  display_arr_1D_with_msg("Array after:  ", arr, size);

  return 0;
}
