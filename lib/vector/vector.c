/**
 * @file    vector.c
 * @brief   Minimal vector implementation like C++ STL
 * @details This file contains the implementation of a vector data structure
 *          and its associated functions. The vector is implemented using
 *          a dynamic array to allow for flexible memory management. It is
 *          designed to be similar to the C++ STL vector.
 *
 * @author  Lokesh Kumar (codetit4n on GitHub)
 * @date    2025-04-23
 * @version 1.0
 */

#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void vector_init(Vector *v) {
  v->data = NULL;
  v->capacity = 0;
  v->size = 0;
}

int vector_is_empty(const Vector *v) {
  if (!v) {
    return 1;
  }

  return v->size == 0;
}

void vector_free(Vector *v) {
  if (!v) {
    return;
  }

  free(v->data);
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
}

void vector_push_back(Vector *v, int d) {
  if (v->size == v->capacity) {
    size_t new_capacity =
        v->capacity == 0 ? 4 : v->capacity * 2; // ensures amortization
    int *new_data = realloc(v->data, new_capacity * sizeof(int));
    if (!new_data) {
      printf("Vector memory allocation failed!\n");
      return;
    }

    v->data = new_data;
    v->capacity = new_capacity;
  }

  v->data[v->size++] = d;
}

bool vector_pop_back(Vector *v, int *out) {
  if (vector_is_empty(v)) {
    return false;
  }
  *out = v->data[v->size - 1];
  v->size--;
  return true;
}

bool vector_get_element(const Vector *v, size_t idx, int *out) {
  if (!v || idx >= v->size) {
    return false;
  }
  *out = v->data[idx];
  return true;
}

void vector_print(const Vector *v) {
  if (!v || v->size == 0) {
    printf("Empty vector!\n");
    return;
  }
  for (size_t i = 0; i < v->size; i++) {
    printf("%d ", v->data[i]);
  }

  printf("\n");
}
