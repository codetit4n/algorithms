#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <stdio.h>

/// Print a 1D array of integers
static inline void print_array_1d(const int *arr, int size) {
  if (!arr || size <= 0) {
    printf("[]\n");
    return;
  }

  printf("[");
  for (int i = 0; i < size; ++i) {
    printf("%d", arr[i]);
    if (i != size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

/// Print a 2D array of integers
static inline void print_array_2d(int rows, int cols, const int arr[rows][cols]) {
  if (rows <= 0 || cols <= 0 || !arr) {
    printf("Empty or invalid 2D array\n");
    return;
  }

  for (int i = 0; i < rows; ++i) {
    printf("[");
    for (int j = 0; j < cols; ++j) {
      printf("%d", arr[i][j]);
      if (j != cols - 1) {
        printf(", ");
      }
    }
    printf("]\n");
  }
}

/// Print a newline (alias for easier formatting)
static inline void println(void) {
  putchar('\n');
}

#endif // PRINT_UTILS_H
