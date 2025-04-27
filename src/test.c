#include "vector/vector.h"

int main() {

  Vector v;

  vector_init(&v);
  vector_push_back(&v, 39);
  vector_push_back(&v, 57);
  vector_push_back(&v, 23);
  vector_push_back(&v, 10);
  vector_push_back(&v, 90);
  vector_print(&v);
  vector_free(&v);

  return 0;
}
