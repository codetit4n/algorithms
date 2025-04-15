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


void append_data(LinkedList* ll, int d);
void append_node(LinkedList* ll, Node* n);
void print_linked_list(LinkedList *ll);
void print_node(Node *n);



#endif // LINKED_LIST_H
