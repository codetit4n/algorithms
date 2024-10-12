#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>

static inline void display_arr_1D(int *arr, int size) {
  if (size == 0) {
    printf("Empty array!");
    return;
  }
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

static inline void display_arr_2D(int rows, int cols, int arr[rows][cols]) {
  if (rows == 0 || cols == 0) {
    printf("Empty array\n");
    return;
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }
}

static inline void endl() { printf("\n"); }

#endif // ARRAYS_H
