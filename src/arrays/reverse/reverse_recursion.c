// Recursion approach:

// Recursively swap the first and last elements until the entire array is
// reversed.

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void reverseArrayRecursive(int *arr, int l, int r) {

  // Base case
  if (l >= r) {
    return;
  }

  // Swap elements at the ends
  swap(&arr[l], &arr[r]);

  // Recursive call
  reverseArrayRecursive(arr, l + 1, r - 1);
}

// -----------------------------------------------------------------

Test(reverseArrayRecursive, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArrayRecursive(arr, 0, size - 1);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {5, 4, 3, 2, 1};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArrayRecursive, test_2) {
  printf("Test 2\n");
  int arr[] = {5, 8, 4, 3, 0, 7, 1, 9, 6, 2};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArrayRecursive(arr, 0, size - 1);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArrayRecursive, test_3) {
  printf("Test 3\n");
  int arr[] = {5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArrayRecursive(arr, 0, size - 1);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {5};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArrayRecursive, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArrayRecursive(arr, 0, size - 1);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {};

  int size_expected = sizeof(expected) / sizeof(int);
  cr_assert(eq(int, size, size_expected));
}
