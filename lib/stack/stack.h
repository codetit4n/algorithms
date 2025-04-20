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
