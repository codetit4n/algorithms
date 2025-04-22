/**
 * @file    stack.h
 * @brief   Header file for minimal stack implementation
 * @details This file contains the definition of a stack data structure
 *          and its associated functions. The stack is implemented using
 *          a dynamic array to allow for flexible memory management.
 *
 * @author  Lokesh Kumar (codetit4n on GitHub)
 * @date    2025-04-21
 * @version 1.0
 */

#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Stack {
    int *data; // Ptr to dynamic array
    size_t size; // Total elements currently in the stack
    size_t capacity; // Total elements that could fit before need for more memory
} Stack;

void init_stack(Stack *s);
void free_stack(Stack *s);
void push(Stack *s, int v);
bool top(const Stack *s, int *out);
bool pop(Stack *s, int *out);
int is_empty_stack(Stack *s);
void print_stack(const Stack *s);

void create_stack_using_array(Stack *s, int *arr, size_t size);

#endif // STACK_H
