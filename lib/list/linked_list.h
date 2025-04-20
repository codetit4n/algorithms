#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct Node Node;

struct Node {
  int data;
  Node *next;
};

typedef struct LinkedList {
  Node *head;
  Node *tail;
  size_t size;
} LinkedList;


void init_linked_list(LinkedList *ll);
void free_linked_list(LinkedList *ll);
void append_data(LinkedList* ll, int d);
void prepend_data(LinkedList* ll, int d);
void print_linked_list(LinkedList *ll);
void print_node(Node *n, unsigned int nl);
int is_empty(LinkedList *ll);

void create_ll_using_array(LinkedList *ll, int *arr, size_t size);


#endif // LINKED_LIST_H
