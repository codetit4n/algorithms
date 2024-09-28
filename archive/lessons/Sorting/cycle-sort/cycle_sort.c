#include <stdio.h>

void display(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[] = {3, 5, 2, 1, 4};
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("Before sorting: ");
  display(arr, size);
  printf("\n");

  int index = 0;
  while (index < size) {
    int correct_index = arr[index] - 1;
    // check if element is at correct pos
    if (index == correct_index) {
      index++;
    } else {
      // swap if not at the right pos
      int tmp = arr[correct_index];
      arr[correct_index] = arr[index];
      arr[index] = tmp;
    }
  }

  printf("After sorting: ");
  display(arr, size);
  printf("\n");

  return 0;
}
