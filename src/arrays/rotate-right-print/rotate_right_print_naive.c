// Naive approach:

// Rotate one by one

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void printRotateArrayRight(int *arr, int n, int k) {

  if (n == 0) {
    return;
  }

  k = k % n;

  for (int i = 0; i < n; i++) {
    if (i < k) {
      printf("%d ", arr[n + i - k]);
    } else {
      printf("%d ", arr[i - k]);
    }
  }

  printf("\n");
}

void redirect_stdout(void) { cr_redirect_stdout(); }

// -----------------------------------------------------------------

Test(printRotateArrayRight, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int k = 2; // Positions to rotate by to the left
  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  printf("Rotated array right(by %d): ", k);
  printRotateArrayRight(arr, size, k);

  cr_redirect_stdout();
  printRotateArrayRight(arr, size, k);
  fflush(stdout);

  cr_assert_stdout_eq_str("4 5 1 2 3 \n");
}

Test(printRotateArrayRight, test_2) {
  printf("Test 2\n");
  int arr[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int k = 3; // Positions to rotate by to the right
  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  printf("Rotated array right(by %d): ", k);
  printRotateArrayRight(arr, size, k);

  cr_redirect_stdout();
  printRotateArrayRight(arr, size, k);
  fflush(stdout);

  cr_assert_stdout_eq_str("4 8 5 2 6 9 1 7 0 3 \n");
}

Test(printRotateArrayRight, test_3) {
  printf("Test 3\n");
  int arr[] = {0};
  int size = sizeof(arr) / sizeof(arr[0]);
  int k = 4; // Positions to rotate by to the right
  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  printf("Rotated array right(by %d): ", k);
  printRotateArrayRight(arr, size, k);

  cr_redirect_stdout();
  printRotateArrayRight(arr, size, k);
  fflush(stdout);

  cr_assert_stdout_eq_str("0 \n");
}

Test(printRotateArrayRight, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);
  int k = 4; // Positions to rotate by to the right
  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  printf("Rotated array right(by %d): ", k);
  printRotateArrayRight(arr, size, k);

  cr_redirect_stdout();
  printRotateArrayRight(arr, size, k);
  fflush(stdout);

  cr_assert_stdout_eq_str("");
}
