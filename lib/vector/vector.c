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
#include <stdlib.h>

void init_vector(Vector *v) {
  v->data = NULL;
  v->capacity = 0;
  v->size = 0;
}

int is_empty_vector(Vector *v) {
  if (!v) {
    return 1;
  }

  return v->size == 0;
}

void free_vector(Vector *v) {
  if (!v) {
    return;
  }

  free(v->data);
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
}

void push_back(Vector *v, int d);
bool pop_back(Vector *v, int *out);
bool get_element(const Vector *v, size_t idx, int *out);
void print_vector(const Vector *v);
