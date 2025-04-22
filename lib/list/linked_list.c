/**
 * @file    linked_list.c
 * @brief   Minimal linked list implementation
 * @details This file contains the implementation of a linked list data
 *          structure and its associated functions. The linked list is
 *          implemented using a dynamic memory allocation to allow for flexible
 *          memory management.
 *
 * @author  Lokesh Kumar (codetit4n on GitHub)
 * @date    2025-04-20
 * @version 1.0
 */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int is_empty_list(LinkedList *ll) {

  if (!ll) {
    return 1;
  }

  return ll->size == 0;
}

void init_linked_list(LinkedList *ll) {
  ll->head = NULL;
  ll->tail = NULL;
  ll->size = 0;
}

void free_linked_list(LinkedList *ll) {

  if (!ll) {
    return;
  }

  Node *n = ll->head;

  while (n != NULL) {
    Node *to_del = n;
    n = n->next;
    free(to_del);
  }

  ll->head = ll->tail = NULL;
  ll->size = 0;
}

void print_node(Node *n, unsigned int nl) {

  if (!n) {
    printf("NULL\n");
    return;
  }

  if (nl > 0) {
    printf("%d\n", n->data);
  } else {
    printf("%d", n->data);
  }
}

void print_linked_list(LinkedList *ll) {

  if (is_empty_list(ll)) {
    printf("Empty list!\n");
    return;
  }

  printf("HEAD -> ");
  Node *n = ll->head;

  while (n != NULL) {
    print_node(n, 0);
    printf(" -> ");
    n = n->next;
  }
  printf("TAIL\n");
}

void append_data(LinkedList *ll, int d) {

  Node *n = malloc(sizeof(Node));
  if (!n) {
    printf("Not enough memory for Node!\n");
    return;
  }

  n->data = d;
  n->next = NULL;

  if (ll->head == NULL) {
    ll->head = ll->tail = n;
  } else {
    ll->tail->next = n;
    ll->tail = n;
  }

  ll->size++;
}

void prepend_data(LinkedList *ll, int d) {

  Node *n = malloc(sizeof(Node));

  if (!n) {
    printf("Not enough memory for Node!\n");
    return;
  }

  n->data = d;
  n->next = NULL;

  if (ll->head == NULL) {
    ll->head = ll->tail = n;
  } else {
    n->next = ll->head;
    ll->head = n;
  }

  ll->size++;
}

void create_ll_using_array(LinkedList *ll, int *arr, size_t size) {

  if (!ll || !arr || size == 0) {
    return;
  }

  for (size_t i = 0; i < size; i++) {
    append_data(ll, arr[i]);
  }
}
