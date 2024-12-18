// Naive approach:

// Create a temporary array and copy elements in the required order.

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

void reverseArray(int *arr, int n) {

  int tmp[n];

  for (int i = 0; i < n; i++) {
    tmp[i] = arr[n - i - 1];
  }

  for (int i = 0; i < n; i++) {
    arr[i] = tmp[i];
  }
}

// -----------------------------------------------------------------

Test(reverseArray, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArray(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {5, 4, 3, 2, 1};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArray, test_2) {
  printf("Test 2\n");
  int arr[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArray(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {5, 8, 4, 3, 0, 7, 1, 9, 6, 2};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArray, test_3) {
  printf("Test 3\n");
  int arr[] = {2};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArray(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {2};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArray, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArray(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {};

  int size_expected = sizeof(expected) / sizeof(expected[0]);

  cr_assert(eq(int, size, size_expected));
}
