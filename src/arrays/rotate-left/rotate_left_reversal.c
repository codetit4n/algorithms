// Reversal approach:

// The idea is based on the observation that if we left rotate the array by d
// positions, the last (n – d) elements will be at the front and the first d
// elements will be at the end.

// Algorithm:
// 1. Reverse the first d elements.
// 2. Reverse the last n-d elements.
// 3. Reverse the whole array.

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

void reverse(int *arr, int start, int end) {
  while (start < end) {
    int tmp = arr[start];
    arr[start] = arr[end];
    arr[end] = tmp;
    start++;
    end--;
  }
}

void rotateArrayLeftReversal(int *arr, int n, int d) {

  if (n == 0) {
    return;
  }

  // if d >= n
  d %= n;
  // Example: Rotating an array of size 5 by 6 positions is the same as rotating
  // it by 1 position (6 % 5 = 1).
  // Rotating an array of size 5 by 10 positions is the same as rotating it by 0
  // positions (10 % 5 = 0).

  reverse(arr, 0, d - 1);

  reverse(arr, d, n - 1);

  reverse(arr, 0, n - 1);
}

// -----------------------------------------------------------------

Test(rotateArrayLeftReversal, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 2; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftReversal(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {3, 4, 5, 1, 2};

  cr_assert(eq(int[size], arr, expected));
}

Test(rotateArrayLeftReversal, test_2) {
  printf("Test 2\n");
  int arr[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 3; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftReversal(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {1, 7, 0, 3, 4, 8, 5, 2, 6, 9};

  cr_assert(eq(int[size], arr, expected));
}

Test(rotateArrayLeftReversal, test_3) {
  printf("Test 3\n");
  int arr[] = {0};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 4; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftReversal(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {0};

  cr_assert(eq(int[size], arr, expected));
}

Test(rotateArrayLeftReversal, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);
  int d = 5; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftReversal(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {};
  int size_expected = sizeof(expected) / sizeof(expected[0]);

  cr_assert(eq(int, size, size_expected));
}

Test(rotateArrayLeftReversal, test_5) {
  printf("Test 5\n");
  int arr[] = {1, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 3; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftReversal(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {2, 1};

  cr_assert(eq(int[size], arr, expected));
}
