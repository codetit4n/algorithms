// Swap approach:

// Iterate over the first half of the array and swap each element with its
// corresponding element from the end.

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void reverseArraySwap(int *arr, int n) {

  for (int i = 0; i < n / 2; i++) {
    swap(&arr[i], &arr[n - i - 1]);
  }
}

// -----------------------------------------------------------------

Test(reverseArraySwap, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArraySwap(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {5, 4, 3, 2, 1};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArraySwap, test_2) {
  printf("Test 2\n");
  int arr[] = {5, 8, 4, 3, 5, 7, 1, 9, 6, 2};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArraySwap(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {2, 6, 9, 1, 7, 5, 3, 4, 8, 5};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArraySwap, test_3) {
  printf("Test 3\n");
  int arr[] = {8};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArraySwap(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {8};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArraySwap, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArraySwap(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {};

  int size_expected = sizeof(expected) / sizeof(int);
  cr_assert(eq(int, size, size_expected));
}
