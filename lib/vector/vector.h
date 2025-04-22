/**
 * @file    vector.h
 * @brief   Header file for minimal vector implementation like C++ STL
 * @details This file contains the definition of a vector data structure
 *          and its associated functions. The vector is implemented using
 *          a dynamic array to allow for flexible memory management.
 *
 * @author  Lokesh Kumar (codetit4n on GitHub)
 * @date    2025-04-23
 * @version 1.0
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Vector {
    int *data; // Ptr to dynamic array
    size_t size; // Total elements currently in the stack
    size_t capacity; // Total elements that could fit before need for more memory
} Vector;

void init_vector(Vector *v);
void free_vector(Vector *v);
void push_back(Vector *v, int d);
bool pop_back(Vector *v, int *out);
bool get_element(const Vector *v, size_t idx, int *out);
int is_empty_vector(Vector *v);
void print_vector(const Vector *v);


#endif // VECTOR_H
