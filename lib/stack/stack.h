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

void stack_init(Stack *s);
void stack_free(Stack *s);
void stack_push(Stack *s, int v);
bool stack_top(const Stack *s, int *out);
bool stack_pop(Stack *s, int *out);
int stack_is_empty(const Stack *s);
void stack_print(const Stack *s);

void stack_create_using_array(Stack *s, int *arr, size_t size);

#endif // STACK_H
