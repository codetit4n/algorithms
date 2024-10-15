// GCD using Euclidian recursive algorithm

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdio.h>

// using Euclidean method - recursive
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

Test(gcdEuclidianRecursive, test_1) {
  printf("Test 1\n");
  int a = 10;
  int b = 5;
  int expected = 5;

  int result = gcd(a, b);

  printf("GCD of %d and %d is %d\n", a, b, result);

  cr_assert(eq(int, result, expected));
}

Test(gcdEuclidianRecursive, test_2) {
  printf("Test 2\n");
  int a = 1220;
  int b = 516;
  int expected = 4;

  int result = gcd(a, b);

  printf("GCD of %d and %d is %d\n", a, b, result);

  cr_assert(eq(int, result, expected));
}

Test(gcdEuclidianRecursive, test_3) {
  printf("Test 3\n");
  int a = 1;
  int b = 0;
  int expected = 1;

  int result = gcd(a, b);

  printf("GCD of %d and %d is %d\n", a, b, result);

  cr_assert(eq(int, result, expected));
}

Test(gcdEuclidianRecursive, test_4) {
  printf("Test 4\n");
  int a = 0;
  int b = 0;
  int expected = 0;

  int result = gcd(a, b);

  printf("GCD of %d and %d is %d\n", a, b, result);

  cr_assert(eq(int, result, expected));
}
