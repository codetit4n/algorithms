// Temprary array approach:

// The idea is to use a temporary array of size n, where n is the length of the
// original array. If we left rotate the array by d positions, the last n – d
// elements will be at the front and the first d elements will be at the end.

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>

void rotateArrayLeftTmp(int *arr, int n, int d) {

  if (n == 0) {
    return;
  }

  // if d >= n
  d %= n;
  // Example: Rotating an array of size 5 by 6 positions is the same as rotating
  // it by 1 position (6 % 5 = 1).
  // Rotating an array of size 5 by 10 positions is the same as rotating it by 0
  // positions (10 % 5 = 0).

  int tmp[n];
  // Copy last n - d elements to the front of tmp
  for (int i = 0; i < n - d; i++) {
    tmp[i] = arr[d + i];
  }

  // Copy first d elements to the end of tmp
  for (int i = 0; i < d; i++) {
    tmp[n - d + i] = arr[i];
  }

  // Copy the final tmp array back to arr
  for (int i = 0; i < n; i++) {
    arr[i] = tmp[i];
  }
}

// -----------------------------------------------------------------

void assert_arrays_eq(int *arr, int *expected, int size) {
  for (int i = 0; i < size; i++) {
    cr_assert_eq(arr[i], expected[i], "Element %d is %d but expected %d", i,
                 arr[i], expected[i]);
  }
}

Test(rotateArrayLeftTmp, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 2; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftTmp(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {3, 4, 5, 1, 2};

  assert_arrays_eq(arr, expected, size);
}

Test(rotateArrayLeftTmp, test_2) {
  printf("Test 2\n");
  int arr[] = {2, 9, 1, 9, 7, 0, 3, 4, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 3; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftTmp(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {9, 7, 0, 3, 4, 8, 5, 2, 9, 1};

  assert_arrays_eq(arr, expected, size);
}

Test(rotateArrayLeftTmp, test_3) {
  printf("Test 3\n");
  int arr[] = {8};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 3; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftTmp(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {8};

  assert_arrays_eq(arr, expected, size);
}

Test(rotateArrayLeftTmp, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);
  int d = 5; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftTmp(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {};

  assert_arrays_eq(arr, expected, size);
}
