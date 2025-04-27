/**
 * @file    linked_list.h
 * @brief   Header file for minimal linked list implementation
 * @details This file contains the definition of a linked list data
 *          structure and its associated functions. The linked list is implemented
 *          using a dynamic memory allocation to allow for flexible memory management.
 *
 * @author  Lokesh Kumar (codetit4n on GitHub)
 * @date    2025-04-20
 * @version 1.0
 */

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


void linked_list_init(LinkedList *ll);
void linked_list_free(LinkedList *ll);
void linked_list_append_data(LinkedList* ll, int d);
void linked_list_prepend_data(LinkedList* ll, int d);
void linked_list_print(LinkedList *ll);
void linked_list_print_node(Node *n, unsigned int nl);
int linked_list_is_empty(LinkedList *ll);

void linked_list_create_using_array(LinkedList *ll, int *arr, size_t size);


#endif // LINKED_LIST_H
