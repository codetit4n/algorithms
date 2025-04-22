#include "stack/stack.h"

int main() {

  Stack s;

  init_stack(&s);
  create_stack_using_array(&s, (int[]){1, 4, 5, 2, 9, 7}, 6);
  push(&s, 19);
  print_stack(&s);
  free_stack(&s);

  return 0;
}
