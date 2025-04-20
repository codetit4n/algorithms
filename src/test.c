#include "list/linked_list.h"

int main() {

  LinkedList ll;
  init_linked_list(&ll);

  create_ll_using_array(&ll, (int[]){1, 2, 3, 4, 5}, 5);

  print_linked_list(&ll);

  free_linked_list(&ll);

  return 0;
}
