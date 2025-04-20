#include "stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int is_empty_stack(Stack *s) {
  if (!s) {
    return 1;
  }

  return s->size == 0;
}

void init_stack(Stack *s) {
  s->data = NULL;
  s->size = 0;
  s->capacity = 0;
}

void free_stack(Stack *s) {

  if (!s) {
    return;
  }

  free(s->data);
  s->data = NULL;
  s->size = 0;
  s->capacity = 0;
}

bool top(const Stack *s, int *out) {
  if (!s || s->size == 0) {
    return false;
  }

  *out = s->data[s->size - 1];
  return true;
}

void push(Stack *s, int v) {
  if (s->size == s->capacity) {
    size_t new_capacity =
        s->capacity == 0 ? 4 : s->capacity * 2; // ensures amortization
    int *new_data = realloc(s->data, new_capacity * sizeof(int));
    if (!new_data) {
      printf("Stack memory allocation failed!\n");
      return;
    }

    s->data = new_data;
    s->capacity = new_capacity;
  }

  s->data[s->size++] = v;
}

bool pop(Stack *s, int *out) {
  if (is_empty_stack(s)) {
    return false;
  }
  *out = s->data[s->size - 1];
  s->size--;
  return true;
}

void create_stack_using_array(Stack *s, int *arr, size_t size) {
  if (!s || !arr || size == 0) {
    return;
  }

  for (size_t i = 0; i < size; i++) {
    push(s, arr[i]);
  }
}

void print_stack(const Stack *s) {
  if (!s || s->size == 0) {
    printf("Empty stack!\n");
    return;
  }

  printf("TOP -> [");
  for (size_t i = s->size; i-- > 0;) {
    printf("%d", s->data[i]);
    if (i != 0) {
      printf(", ");
    }
  }
  printf("]\n");
}
