// Juggling approach:

// The idea is to use Juggling Algorithm which is based on rotating elements in
// cycles. Each cycle is independent and represents a group of elements that
// will shift among themselves during the rotation.

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

// using Euclidean method - recursive
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

void rotateArrayLeftJuggle(int *arr, int n, int d) {

  if (n == 0) {
    return;
  }

  // if d >= n
  d %= n;
  // Example: Rotating an array of size 5 by 6 positions is the same as rotating
  // it by 1 position (6 % 5 = 1).
  // Rotating an array of size 5 by 10 positions is the same as rotating it by 0
  // positions (10 % 5 = 0).

  int cycles = gcd(n, d);

  for (int i = 0; i < cycles; i++) {

    // Get start element for current cycle
    int startEl = arr[i];

    // Start index of current cycle
    int currIdx = i, nextIdx;

    // Rotate elements till we reach the start of cycle
    while (true) {
      nextIdx = (currIdx + d) % n;

      if (nextIdx == i)
        break;

      // Update the next index with the current element
      arr[currIdx] = arr[nextIdx];
      currIdx = nextIdx;
    }

    // Copy the start element of current cycle at the last index of the cycle
    arr[currIdx] = startEl;
  }
}

// -----------------------------------------------------------------

Test(rotateArrayLeftJuggle, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 2; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftJuggle(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {3, 4, 5, 1, 2};

  cr_assert(eq(int[size], arr, expected));
}

Test(rotateArrayLeftJuggle, test_2) {
  printf("Test 2\n");
  int arr[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("size: %d\n", size);
  int d = 3; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftJuggle(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {1, 7, 0, 3, 4, 8, 5, 2, 6, 9};

  cr_assert(eq(int[size], arr, expected));
}

Test(rotateArrayLeftJuggle, test_3) {
  printf("Test 3\n");
  int arr[] = {0};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 4; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftJuggle(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {0};

  cr_assert(eq(int[size], arr, expected));
}

Test(rotateArrayLeftJuggle, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);
  int d = 5; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftJuggle(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {};

  int size_expected = sizeof(expected) / sizeof(expected[0]);

  cr_assert(eq(int, size, size_expected));
}

Test(rotateArrayLeftJuggle, test_5) {
  printf("Test 5\n");
  int arr[] = {1, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 3; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeftJuggle(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {2, 1};

  cr_assert(eq(int[size], arr, expected));
}
