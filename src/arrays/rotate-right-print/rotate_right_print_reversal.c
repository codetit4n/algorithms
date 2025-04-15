// Reversal approach:

// 1. Reverse last K elements
// 2. Reverse first N-K elements
// 3. Reverse entire array
// 4. print reversed array

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void reverse(int *arr, int start, int end) {
  while (start < end) {
    int tmp = arr[start];
    arr[start] = arr[end];
    arr[end] = tmp;
    start++;
    end--;
  }
}

void printRotateArrayRight(int *arr, int n, int k) {

  if (n == 0) {
    return;
  }

  k = k % n;

  // Reverse last K elements
  reverse(arr, n - k, n - 1);
  // Reverse first N-K elements
  reverse(arr, 0, n - k - 1);
  // Reverse entire arr reverse(arr, 0, n - 1);
  reverse(arr, 0, n - 1);

  // Print arr
  display_arr_1D(arr, n);

  endl();
}

void redirect_stdout(void) { cr_redirect_stdout(); }

// -----------------------------------------------------------------

Test(printRotateArrayRight, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int arr_cpy[] = {1, 2, 3, 4, 5}; // only for display purpose
  int size = sizeof(arr) / sizeof(arr[0]);
  int k = 2; // Positions to rotate by to the right
  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  printf("Rotated array right(by %d): ", k);
  printRotateArrayRight(arr_cpy, size, k);

  cr_redirect_stdout();
  printRotateArrayRight(arr, size, k);
  fflush(stdout);

  cr_assert_stdout_eq_str("4 5 1 2 3 \n");
}

Test(printRotateArrayRight, test_2) {
  printf("Test 2\n");
  int arr[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5};
  int arr_cpy[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5}; // only for display purpose
  int size = sizeof(arr) / sizeof(arr[0]);
  int k = 3; // Positions to rotate by to the right
  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  printf("Rotated array right(by %d): ", k);
  printRotateArrayRight(arr_cpy, size, k);

  cr_redirect_stdout();
  printRotateArrayRight(arr, size, k);
  fflush(stdout);

  cr_assert_stdout_eq_str("4 8 5 2 6 9 1 7 0 3 \n");
}

Test(printRotateArrayRight, test_3) {
  printf("Test 3\n");
  int arr[] = {0};
  int arr_cpy[] = {0}; // only for display purpose
  int size = sizeof(arr) / sizeof(arr[0]);
  int k = 4; // Positions to rotate by to the right
  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  printf("Rotated array right(by %d): ", k);
  printRotateArrayRight(arr_cpy, size, k);

  cr_redirect_stdout();
  printRotateArrayRight(arr, size, k);
  fflush(stdout);

  cr_assert_stdout_eq_str("0 \n");
}

Test(printRotateArrayRight, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int arr_cpy[] = {}; // only for display purpose
  int size = sizeof(arr) / sizeof(int);
  int k = 4; // Positions to rotate by to the right
  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  printf("Rotated array right(by %d): ", k);
  printRotateArrayRight(arr_cpy, size, k);

  cr_redirect_stdout();
  printRotateArrayRight(arr, size, k);
  fflush(stdout);

  cr_assert_stdout_eq_str("");
}
