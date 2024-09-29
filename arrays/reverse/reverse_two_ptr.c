// 2 ptrs approach:

// Use 2 ptrs left at start and right at end of array. While left ptr is
// less than right ptr, swap the elements. Move ptrs after each swap.

#include "../../utils/arrays.h"

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void reverseArray(int arr[], int n) {

  int left = 0;
  int right = n - 1;

  while (left < right) {
    swap(&arr[left], &arr[right]);
    left++;
    right--;
  }
}

int main() {

  int arr[] = {2, 9, 1, 7, 0, 3, 4, 8, 5};

  int size = sizeof(arr) / sizeof(arr[0]);

  display_arr_1D_with_msg("Array before: ", arr, size);

  reverseArray(arr, size);

  display_arr_1D_with_msg("Array after:  ", arr, size);

  return 0;
}
