// GCD using Euclidian iterative algorithm

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdio.h>

// using Euclidean method - iterative
int gcd(int a, int b) {

  if (b == 0) {
    return a;
  }

  while (a % b != 0) { // Loop until a is divisible by b
    int r = a % b;
    a = b;
    b = r;
  }

  return b;
}

Test(gcdEuclidianIterative, test_1) {
  printf("Test 1\n");
  int a = 10;
  int b = 5;
  int expected = 5;

  int result = gcd(a, b);

  printf("GCD of %d and %d is %d\n", a, b, result);

  cr_assert(eq(int, result, expected));
}

Test(gcdEuclidianIterative, test_2) {
  printf("Test 2\n");
  int a = 1220;
  int b = 516;
  int expected = 4;

  int result = gcd(a, b);

  printf("GCD of %d and %d is %d\n", a, b, result);

  cr_assert(eq(int, result, expected));
}

Test(gcdEuclidianIterative, test_3) {
  printf("Test 3\n");
  int a = 1;
  int b = 0;
  int expected = 1;

  int result = gcd(a, b);

  printf("GCD of %d and %d is %d\n", a, b, result);

  cr_assert(eq(int, result, expected));
}

Test(gcdEuclidianIterative, test_4) {
  printf("Test 4\n");
  int a = 0;
  int b = 0;
  int expected = 0;

  int result = gcd(a, b);

  printf("GCD of %d and %d is %d\n", a, b, result);

  cr_assert(eq(int, result, expected));
}
