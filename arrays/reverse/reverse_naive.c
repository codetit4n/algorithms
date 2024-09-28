// Naive approach:

// Step 1: Create a temporary array of same size as the original array.
//
// Step 2: Now, copy all elements from original array to the temporary array in
// reverse order.
//
// Step 3: Finally, copy all the elements from temporary array back to
// the original array.

#include "../../utils/array_utils.h"

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
  int arr[] = {2, 5, 9, 1, 5, 0, 2, 0, 1, 2, 9, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  display_arr_1D_with_msg("Array before: ", arr, size);

  reverseArray(arr, size);

  display_arr_1D_with_msg("Array after: ", arr, size);

  int arr1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  return 0;
}
